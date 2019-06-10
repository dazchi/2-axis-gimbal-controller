#include "MPU6050.h"
#include "I2C.h"
#include "Delay.h"
#include "PWM.h"
#include "UART.h"
#include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h"
#include "dmpKey.h"
#include "dmpmap.h"
#include "mathf.h"

#define MPU6050
#define DEFAULT_MPU_HZ (200)
#define DMP_SAMPLE_RATE (200)
#define printf LOG
#define q30 (1073741824.0f)

int run_self_test_flag = 0;

enum packet_type_e
{
    PACKET_TYPE_ACCEL,
    PACKET_TYPE_GYRO,
    PACKET_TYPE_QUAT,
    PACKET_TYPE_TAP,
    PACKET_TYPE_ANDROID_ORIENT,
    PACKET_TYPE_PEDO,
    PACKET_TYPE_MISC
};

void DMP_Init(void)
{
    static signed char gyro_orientation[9] = {1, 0, 0,
                                              0, 1, 0,
                                              0, 0, 1};

    delay_ms(1000);

    LOG("DMP Initializing...........\r\n");
    if (!mpu_init()) //mpu初始化
    {
        LOG("mpu_init complete ......\r\n");
        if (!mpu_set_sensors(INV_XYZ_GYRO | INV_XYZ_ACCEL)) //设置需要的传感器
            LOG("mpu_set_sensors complete ......\r\n");
        delay_ms(10);
        if (!mpu_configure_fifo(INV_XYZ_GYRO | INV_XYZ_ACCEL)) //设置fifo
            printf("mpu_configure_fifo complete ......\r\n");
        delay_ms(10);
        if (!mpu_set_sample_rate(DEFAULT_MPU_HZ)) //设置采集样率
            printf("mpu_set_sample_rate complete ......\r\n");
        delay_ms(100);
        if (!dmp_load_motion_driver_firmware()) //加载dmp固件
            printf("dmp_load_motion_driver_firmware complete ......\r\n");
        delay_ms(10);
        if (!dmp_set_orientation(inv_orientation_matrix_to_scalar(gyro_orientation))) // if (!dmp_set_orientation(inv_orientation_matrix_to_scalar(gyro_orientation)))
            printf("dmp_set_orientation complete ......\r\n");                        //设置陀螺仪方向
        delay_ms(10);
        if (!dmp_enable_feature(DMP_FEATURE_6X_LP_QUAT | DMP_FEATURE_TAP |
                                DMP_FEATURE_ANDROID_ORIENT | DMP_FEATURE_SEND_RAW_ACCEL | DMP_FEATURE_SEND_CAL_GYRO |
                                DMP_FEATURE_GYRO_CAL))
            printf("dmp_enable_feature complete ......\r\n");
        delay_ms(10);
        if (!dmp_set_fifo_rate(DMP_SAMPLE_RATE)) //设置速率
            printf("dmp_set_fifo_rate complete ......\r\n");
        delay_ms(10);

        if (run_self_test_flag)
        {
            run_self_test(); //自检
            delay_ms(10);
        }
        
        if (!mpu_set_dmp_state(1)) //使能
            printf("mpu_set_dmp_state complete ......\r\n");

        mpu_initialized = 1;
    }
    else
    {
    }
}

unsigned char Read_DMP(float *Pitch, float *Roll, float *Yaw)
{
    short gyro[3], accel[3], sensors;
    float q0 = 1.0f, q1 = 0.0f, q2 = 0.0f, q3 = 0.0f;
    unsigned long sensor_timestamp;
    unsigned char more;
    long quat[4];
    if (dmp_read_fifo(gyro, accel, quat, &sensor_timestamp, &sensors, &more))
        return 1;
    if (sensors & INV_WXYZ_QUAT)
    {
        q0 = quat[0] / q30;
        q1 = quat[1] / q30;
        q2 = quat[2] / q30;
        q3 = quat[3] / q30;
        *Pitch = (float)asinf(-2 * q1 * q3 + 2 * q0 * q2) * Rad2Deg;
        *Roll = (float)atan2f(2 * q2 * q3 + 2 * q0 * q1, -2 * q1 * q1 - 2 * q2 * q2 + 1) * Rad2Deg; // roll
        *Yaw = (float)atan2f(2 * (q1 * q2 + q0 * q3), q0 * q0 + q1 * q1 - q2 * q2 - q3 * q3) * Rad2Deg;
        return 0;
    }
    else
        return 2;
}

static unsigned short inv_orientation_matrix_to_scalar(
    const signed char *mtx)
{
    unsigned short scalar;

    /*
       XYZ  010_001_000 Identity Matrix
       XZY  001_010_000
       YXZ  010_000_001
       YZX  000_010_001
       ZXY  001_000_010
       ZYX  000_001_010
     */

    scalar = inv_row_2_scale(mtx);
    scalar |= inv_row_2_scale(mtx + 3) << 3;
    scalar |= inv_row_2_scale(mtx + 6) << 6;

    return scalar;
}

static unsigned short inv_row_2_scale(const signed char *row)
{
    unsigned short b;

    if (row[0] > 0)
        b = 0;
    else if (row[0] < 0)
        b = 4;
    else if (row[1] > 0)
        b = 1;
    else if (row[1] < 0)
        b = 5;
    else if (row[2] > 0)
        b = 2;
    else if (row[2] < 0)
        b = 6;
    else
        b = 7; // error
    return b;
}

// static void run_self_test(void)
// {
//     int result;
//     long gyro[3], accel[3];
//     unsigned char i = 0;

//     LOG("Running Self Test.......\r\n");
//     result = mpu_run_self_test(gyro, accel);
//     LOG("Self Test Result = 0x%2X.......\r\n", result);

//     if (result == 0x7)
//     {
//         /* Test passed. We can trust the gyro data here, so let's push it down
//          * to the DMP.
//          */
//         for (i = 0; i < 3; i++)
//         {
//             gyro[i] = (long)(gyro[i] * 32.8f); //convert to +-1000dps
//             accel[i] *= 2048.f;                //convert to +-16G
//             accel[i] = accel[i] >> 16;
//             gyro[i] = (long)(gyro[i] >> 16);
//         }

//         mpu_set_gyro_bias_reg(gyro);
//         LOG("Gyro Recalibrated......\r\n");
//         mpu_set_accel_bias_6050_reg(accel);
//         LOG("Accelerometer Recalibrated......\r\n");
//     }
// }

static void run_self_test(void)
{
    int result;
    long gyro[3], accel[3];
    float sens;
    unsigned short accel_sens;

    //传感器自检，并返回偏差值
    LOG("Running Self Test.......\r\n");
    result = mpu_run_self_test(gyro, accel);
    LOG("Self Test Result = 0x%02X.......\r\n", result);

    if (result == 0x07)
    {
        LOG("Self Test Passed......\r\n");
        /* Test passed. We can trust the gyro data here, so let's push it down
         * to the DMP.
         */

        mpu_get_gyro_sens(&sens); //获得陀螺仪的灵敏度因子
        gyro[0] = (long)(gyro[0] * sens);
        gyro[1] = (long)(gyro[1] * sens);
        gyro[2] = (long)(gyro[2] * sens);
        dmp_set_gyro_bias(gyro); //重新校准陀螺仪
        LOG("Gyro Recalibrated......\r\n");

        mpu_get_accel_sens(&accel_sens); //获得加速计的灵敏度因子
        accel[0] *= accel_sens;
        accel[1] *= accel_sens;
        accel[2] *= accel_sens;
        dmp_set_accel_bias(accel); //重新校准加速计
        LOG("Accelerometer Recalibrated......\r\n");
    }
    else
    {
        LOG("Self Test Failed......\r\n");
    }
    //  ---------------------
    // 作者：a1058191679
    // 来源：CSDN
    // 原文：https://blog.csdn.net/a1058191679/article/details/88592757
    // 版权声明：本文为博主原创文章，转载请附上博文链接！
}
