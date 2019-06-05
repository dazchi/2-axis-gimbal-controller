#include "PID.h"
#include "mathf.h"
PID pid_Roll;
PID pid_Pitch;
int slow_flag_Pitch = 0;
int slow_flag_Roll = 0;

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
    pid->SetAngle = TargetAngle;
    pid->err = pid->SetAngle - pid->ActualAngle;

    pid->theta = pid->Kp * (pid->err - pid->err_last) + pid->Ki * pid->err + pid->Kd * (pid->err - 2 * pid->err_last + pid->err_prev);
    pid->err_prev = pid->err_last;
    pid->err_last = pid->err;

    return pid->theta;
}

float PID_Increase_Pitch(float TargetAngle) 
{
    pid_Pitch.SetAngle = TargetAngle;
    pid_Pitch.err = pid_Pitch.SetAngle - pid_Pitch.ActualAngle;

    if (fabsf(pid_Pitch.err) > 15)
    {
        slow_flag_Pitch = 1;
    }
    else if (fabsf(pid_Pitch.err) < 1)
    {
        slow_flag_Pitch = 0;
    }

    pid_Pitch.theta = pid_Pitch.Kp * (pid_Pitch.err - pid_Pitch.err_last) + pid_Pitch.Ki * pid_Pitch.err + pid_Pitch.Kd * (pid_Pitch.err - 2 * pid_Pitch.err_last + pid_Pitch.err_prev);
    pid_Pitch.err_prev = pid_Pitch.err_last;
    pid_Pitch.err_last = pid_Pitch.err;

    if (slow_flag_Pitch)
    {
        if (fabsf(pid_Pitch.theta) >= 0.02)
        {
            if (pid_Pitch.theta >= 0)
            {
                return 0.02;
            }
            else
            {
                return -0.02;
            }
        }
    }

    return pid_Pitch.theta;
}

float PID_Increase_Roll(float TargetAngle) 
{
    pid_Roll.SetAngle = TargetAngle;
    pid_Roll.err = pid_Roll.SetAngle - pid_Roll.ActualAngle;

    if (fabsf(pid_Roll.err) > 15)
    {
        slow_flag_Roll = 1;
    }
    else if (fabsf(pid_Roll.err) < 1)
    {
        slow_flag_Roll = 0;
    }

    pid_Roll.theta = pid_Roll.Kp * (pid_Roll.err - pid_Roll.err_last) + pid_Roll.Ki * pid_Roll.err + pid_Roll.Kd * (pid_Roll.err - 2 * pid_Roll.err_last + pid_Roll.err_prev);
    pid_Roll.err_prev = pid_Roll.err_last;
    pid_Roll.err_last = pid_Roll.err;

    if (slow_flag_Roll)
    {
        if (fabsf(pid_Roll.theta) >= 0.02)
        {
            if (pid_Roll.theta >= 0)
            {
                return 0.02;
            }
            else
            {
                return -0.02;
            }
        }
    }

    return pid_Roll.theta;
}
