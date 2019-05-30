#include "I2C.h"
#include "Delay.h"

int initialized = 0;
unsigned short TxDoneFlag = 1;
unsigned short RxDoneFlag = 1;
static unsigned char TxBuffer[4096];

void InitialI2C(void)
{
    R_PG_I2C_Set_C0();
}

int I2C_Write(unsigned char SlaveAdd, unsigned char RegAdd, unsigned char length, unsigned char const *data)
{
    unsigned char ctl_byte = 0;
    int i =0;
    ctl_byte = ((SlaveAdd) << 1)&0xFF;

    TxBuffer[0] = RegAdd;
    for (i = 0; i < length; i++)
    {
        TxBuffer[i+1] = data[i];
    }
        
    while (!(TxDoneFlag & RxDoneFlag))
        ;
    TxDoneFlag = 0;
    R_PG_I2C_MasterSend_C0(ctl_byte,TxBuffer, length+1);
    while (!(TxDoneFlag & RxDoneFlag));
    if(!initialized)
        delay_ms(1);

    return 0;
}

int I2C_Read(unsigned char SlaveAdd, unsigned char RegAdd, unsigned char length, unsigned char *data)
{
    unsigned char ctl_byte = 0;
    ctl_byte = ((SlaveAdd) << 1)&0xFF;

    while (!(TxDoneFlag & RxDoneFlag))
        ;
    TxDoneFlag = 0;
    R_PG_I2C_MasterSendWithoutStop_C0(ctl_byte, &RegAdd, 1);

    while (!(TxDoneFlag & RxDoneFlag))
        ;
    RxDoneFlag = 0;
    R_PG_I2C_MasterReceive_C0(ctl_byte + 1, data, (unsigned int)length);
    while (!(TxDoneFlag & RxDoneFlag));
    if(!initialized)
        delay_ms(1);
        
    return 0;
}

void MPU6050_Read(unsigned char device, unsigned char address, unsigned char *data, unsigned int data_size)
{
    unsigned char ctl_byte = 0;
    ctl_byte = (0x68 + device) << 1;

    while (!(TxDoneFlag & RxDoneFlag))
        ;
    TxDoneFlag = 0;
    R_PG_I2C_MasterSendWithoutStop_C0(ctl_byte, &address, 1);

    while (!(TxDoneFlag & RxDoneFlag))
        ;
    RxDoneFlag = 0;
    R_PG_I2C_MasterReceive_C0(ctl_byte + 1, data, data_size);

    //while( !(TxDoneFlag&RxDoneFlag) );
}

void MPU6050_WriteSingle(unsigned char device, unsigned char address, unsigned char data)
{
    unsigned char ctl_byte = 0;
    unsigned char Add_Data[2] = {0};
    ctl_byte = (0x68 + device) << 1;

    Add_Data[0] = address;
    Add_Data[1] = data;

    while (!(TxDoneFlag & RxDoneFlag))
        ;
    TxDoneFlag = 0;
    R_PG_I2C_MasterSend_C0(ctl_byte, Add_Data, 2);

    //while( !(TxDoneFlag&RxDoneFlag) );
}

void MPU6050_GetGyroXYZ(short XYZ[3])
{
    unsigned char RX_data[6] = {0};

    MPU6050_Read(0, 0x43, &RX_data[0], 6);

    XYZ[0] = RX_data[0] << 8 | RX_data[1];
    XYZ[1] = RX_data[2] << 8 | RX_data[3];
    XYZ[2] = RX_data[4] << 8 | RX_data[5];
}

float MPU6050_GetTemperature(void)
{
    unsigned char RX_data[2] = {0};
    short temp_raw = 0;
    float temp = 0;

    I2C_Read(0x68, 0x41, 2, RX_data);
    //MPU6050_Read(0, 0x41, &RX_data[0], 2);
    temp_raw = (RX_data[0] << 8 | RX_data[1]);
    temp = ((float)temp_raw) / 340.0 + 36.53;

    return temp;
}

void IIC0MasterTrFunc(void)
{
    TxDoneFlag = 1;
}

void IIC0MasterReFunc(void)
{
    RxDoneFlag = 1;
}