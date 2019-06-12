#include "PID.h"
#include "math.h"
#include "mathf.h"
PID pid_Roll;
PID pid_Pitch;
PID pi_Roll_inner;

int slow_flag_Pitch = 0;
int slow_flag_Roll = 0;

float alpha = 0;

void PID_Initial(PID *pid)
{
    pid->SetValue = 0.0;
    pid->ActualValue = 0.0;
    pid->err = 0.0;      //本次誤差
    pid->err_last = 0.0; //上次誤差
    pid->err_prev = 0.0; //上上次誤差
    pid->integral = 0.0;
    pid->UpperLimit = 0.0;
    pid->LowerLimit = 0.0;
    pid->Result = 0.0;
}

float PID_Update(PID *pid, float TargetValue) //位置型
{
    pid->SetValue = TargetValue;
    pid->err = pid->SetValue - pid->ActualValue;

    if( fabsf(pid->err) > 2.5){
        //alpha = 0.05;     
    }else{
        //alpha = 1.0;
        pid->integral += pid->err;
    }    
    pid->Result = pid->Kp * pid->err + pid->Ki * pid->integral * alpha + pid->Kd * (pid->err - pid->err_last);
    pid->err_last = pid->err;

    return pid->Result;
}


float PID_Increase(PID *pid, float TargetValue) //增量型
{
    pid->SetValue = TargetValue;
    pid->err = pid->SetValue - pid->ActualValue;

    pid->Result = pid->Kp * (pid->err - pid->err_last) + pid->Ki * pid->err + pid->Kd * (pid->err - 2 * pid->err_last + pid->err_prev);
    pid->err_prev = pid->err_last;
    pid->err_last = pid->err;

    return pid->Result;
}

// float PID_Increase_Pitch(float TargetAngle)
// {
//     pid_Pitch.SetValue = TargetAngle;
//     pid_Pitch.err = pid_Pitch.SetValue - pid_Pitch.ActualValue;

//     if (fabsf(pid_Pitch.err) > 10)
//     {
//         slow_flag_Pitch = 1;
//     }
//     else if (fabsf(pid_Pitch.err) < 0.5)
//     {
//         slow_flag_Pitch = 0;
//     }

//     pid_Pitch.Result = pid_Pitch.Kp * (pid_Pitch.err - pid_Pitch.err_last) + pid_Pitch.Ki * pid_Pitch.err + pid_Pitch.Kd * (pid_Pitch.err - 2 * pid_Pitch.err_last + pid_Pitch.err_prev);
//     pid_Pitch.err_prev = pid_Pitch.err_last;
//     pid_Pitch.err_last = pid_Pitch.err;

//     if (slow_flag_Pitch)
//     {
//         if (fabsf(pid_Pitch.Result) >= 0.02)
//         {
//             if (pid_Pitch.Result >= 0)
//             {
//                 return 0.02;
//             }
//             else
//             {
//                 return -0.02;
//             }
//         }
//     }

//     return pid_Pitch.Result;
// }

// float PID_Increase_Roll(float TargetAngle)
// {    
//     pid_Roll.SetValue = TargetAngle;
//     pid_Roll.err = pid_Roll.SetValue - pid_Roll.ActualValue;

//     // if (fabsf(pid_Roll.err) > 10)
//     // {
//     //     slow_flag_Roll = 1;
//     // }
//     // else if (fabsf(pid_Roll.err) < 0.5)
//     // {
//     //     slow_flag_Roll = 0;
//     // } 

//     pid_Roll.Result = pid_Roll.Kp * (pid_Roll.err - pid_Roll.err_last) + pid_Roll.Ki * pid_Roll.err + pid_Roll.Kd * (pid_Roll.err - 2 * pid_Roll.err_last + pid_Roll.err_prev);
//     pid_Roll.err_prev = pid_Roll.err_last;
//     pid_Roll.err_last = pid_Roll.err;

//     if (slow_flag_Roll)
//     {
//         if (fabsf(pid_Roll.Result) >= 0.02)
//         {
//             if (pid_Roll.Result >= 0)
//             {
//                 return 0.02;
//             }
//             else
//             {
//                 return -0.02;
//             }
//         }
//     }
//     else
//     {
//         if (pid_Roll.Result > pid_Roll.UpperLimit)
//         {
//             return pid_Roll.UpperLimit;
//         }
//         else if (pid_Roll.Result < pid_Roll.LowerLimit)
//         {
//             return pid_Roll.LowerLimit;
//         }
//     }

//     return pid_Roll.Result;
// }

float PID_Increase_Pitch(float TargetAngle)
{
    float alpha_Pitch = 1.0;

    pid_Pitch.SetValue = TargetAngle;
    pid_Pitch.err = pid_Pitch.SetValue - pid_Pitch.ActualValue;

    if(fabsf(pid_Pitch.err) > 3){
        alpha_Pitch = 1.0 / fabsf(pid_Pitch.err);
    }else{
        alpha_Pitch = 1.0;
    }
    
    pid_Pitch.Result = pid_Pitch.Kp * (pid_Pitch.err - pid_Pitch.err_last) + alpha_Pitch * pid_Pitch.Ki * pid_Pitch.err + pid_Pitch.Kd * (pid_Pitch.err - 2 * pid_Pitch.err_last + pid_Pitch.err_prev);
    pid_Pitch.err_prev = pid_Pitch.err_last;
    pid_Pitch.err_last = pid_Pitch.err;

    return pid_Pitch.Result;
}

float PID_Increase_Roll(float TargetAngle)
{    
    float alpha_Roll = 1.0;

    pid_Roll.SetValue = TargetAngle;
    pid_Roll.err = pid_Roll.SetValue - pid_Roll.ActualValue;

    if(fabsf(pid_Roll.err) > 2.5){
        alpha_Roll = 1.0 / fabsf(pid_Roll.err);
    }else{
        alpha_Roll = 1.0;
    }

    pid_Roll.Result = pid_Roll.Kp * (pid_Roll.err - pid_Roll.err_last) + alpha_Roll * pid_Roll.Ki * pid_Roll.err + pid_Roll.Kd * (pid_Roll.err - 2 * pid_Roll.err_last + pid_Roll.err_prev);
    pid_Roll.err_prev = pid_Roll.err_last;
    pid_Roll.err_last = pid_Roll.err;

    return pid_Roll.Result;
}

