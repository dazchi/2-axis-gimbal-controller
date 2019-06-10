typedef struct
{
    float SetValue;
    float ActualValue;
    float err;      //本次誤差
    float err_last; //上次誤差
    float err_prev; //上上次誤差
    float integral;
    float Result;
    float Kp, Ki, Kd;
    float Slow_Kp, Slow_Ki, Slow_Kd;       
    float UpperLimit, LowerLimit;

} PID;

extern PID pid_Roll;
extern PID pid_Pitch;

void PID_Initial(PID* pid);
float PID_Update(PID* pid,float TargetAngle);
float PID_Increase(PID* pid,float TargetAngle);
float PID_Increase_Pitch(float TargetAngle);
float PID_Increase_Roll(float TargetAngle);