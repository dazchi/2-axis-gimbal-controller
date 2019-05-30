#include "PID.h"
#include "mathf.h"

void PID_Initial(PID *pid)
{
    pid->SetAngle = 0.0;
    pid->ActualAngle = 0.0;
    pid->err = 0.0;      //本次誤差
    pid->err_last = 0.0; //上次誤差
    pid->err_prev = 0.0; //上上次誤差
    pid->integral = 0.0;
    pid->theta = 0.0;
}

float PID_Update(PID *pid, float TargetAngle) //位置型
{
    pid->SetAngle = TargetAngle;
    pid->err = pid->SetAngle - pid->ActualAngle;
    pid->integral += pid->err;
    pid->theta = pid->Kp * pid->err + pid->Ki * pid->integral + pid->Kd * (pid->err - pid->err_last);
    pid->err_last = pid->err;

    return pid->theta;
}

float PID_Increase(PID *pid, float TargetAngle) //增量型 0.02,0.04,0.4
{
    float original_Ki = 0;
    float original_Kd = 0;

    pid->SetAngle = TargetAngle;
    pid->err = pid->SetAngle - pid->ActualAngle;

    /*-------------------------------------------------*/
    if (fabsf(pid->err) > 15)
    {
        pid->Ki = 0.001;
        pid->Kd = 0.1;
    }else{
        
    }
    /*-------------------------------------------------*/

    pid->theta = pid->Kp * (pid->err - pid->err_last) + pid->Ki * pid->err + pid->Kd * (pid->err - 2 * pid->err_last + pid->err_prev);
    pid->err_prev = pid->err_last;
    pid->err_last = pid->err;

    // pid->Ki = original_Ki;
    // pid->Kd = original_Kd;

    return pid->theta;
}
