#include "PWM.h"
#include "mathf.h"
#include "iodefine.h"

const float Pi = 3.14159265359;

float sin2pi_3 = 0;
float sin4pi_3 = 0;
float cos2pi_3 = 0;
float cos4pi_3 = 0;

float _2pi_6 = 0;  // 60deg
float _4pi_6 = 0;  //120deg
float _6pi_6 = 0;  //180deg
float _8pi_6 = 0;  //240deg
float _10pi_6 = 0; //300deg
float _12pi_6 = 0; //360deg

float Rad2Deg = 0;
float Deg2Rad = 0;

unsigned short phase = 1;
unsigned short PWM = 0;
unsigned short PWM_LimitA = PWM_MAX * 0.4;
unsigned short PWM_LimitB = PWM_MAX * 0.45;


void InitialPWMs(void)
{

    sin2pi_3 = sinf((2 * Pi) / 3);
    sin4pi_3 = sinf((4 * Pi) / 3);
    cos2pi_3 = cosf((2 * Pi) / 3);
    cos4pi_3 = cosf((4 * Pi) / 3);

    _2pi_6 = (2 * Pi) / 6;
    _4pi_6 = (4 * Pi) / 6;
    _6pi_6 = (6 * Pi) / 6;
    _8pi_6 = (8 * Pi) / 6;
    _10pi_6 = (10 * Pi) / 6;
    _12pi_6 = (12 * Pi) / 6;

    Rad2Deg = 180/Pi;
    Deg2Rad = Pi/180;

    R_PG_IO_PORT_Set_P9();
    R_PG_Timer_Set_GPT_U0();
    R_PG_Timer_Set_GPT_U0_C0();
    R_PG_Timer_Set_GPT_U0_C1();
    R_PG_Timer_Set_GPT_U0_C2();

    GPT0.GTPR = PWM_MAX;
    GPT1.GTPR = PWM_MAX;
    GPT2.GTPR = PWM_MAX;

    R_PG_Timer_SynchronouslyStartCount_GPT_U0(1, 1, 1, 0);
}

void EnablePWM_A(void){
    R_PG_IO_PORT_Write_P91(1);
}

void DisablePWM_A(void){
    R_PG_IO_PORT_Write_P91(0);
}

void EnablePWM_B(void){
    R_PG_IO_PORT_Write_P92(1);
}

void DisablePWM_B(void){
    R_PG_IO_PORT_Write_P92(0);
}

void SetPWM_A0(unsigned short gtccr)
{
    switch (gtccr)
    {
    case 0:
        GPT0.GTIOR.WORD = (GPT0.GTIOR.WORD & 0xFF00) | 0x0005;
        break;
    case PWM_MAX:
        GPT0.GTIOR.WORD = (GPT0.GTIOR.WORD & 0xFF00) | 0x0002;
        break;
    default:
        GPT0.GTIOR.WORD = (GPT0.GTIOR.WORD & 0xFF00) | 0x0006;
        GPT0.GTCCRA = gtccr;
        break;
    }
}

void SetPWM_A1(unsigned short gtccr)
{
    switch (gtccr)
    {
    case 0:
        GPT1.GTIOR.WORD = (GPT1.GTIOR.WORD & 0xFF00) | 0x0005;
        break;
    case PWM_MAX:
        GPT1.GTIOR.WORD = (GPT1.GTIOR.WORD & 0xFF00) | 0x0002;
        break;
    default:
        GPT1.GTIOR.WORD = (GPT1.GTIOR.WORD & 0xFF00) | 0x0006;
        GPT1.GTCCRA = gtccr;
        break;
    }
}

void SetPWM_A2(unsigned short gtccr)
{
    switch (gtccr)
    {
    case 0:
        GPT2.GTIOR.WORD = (GPT2.GTIOR.WORD & 0xFF00) | 0x0005;
        break;
    case PWM_MAX:
        GPT2.GTIOR.WORD = (GPT2.GTIOR.WORD & 0xFF00) | 0x0002;
        break;
    default:
        GPT2.GTIOR.WORD = (GPT2.GTIOR.WORD & 0xFF00) | 0x0006;
        GPT2.GTCCRA = gtccr;
        break;
    }
}

void SetPWM_B0(unsigned short gtccr)
{
    switch (gtccr)
    {
    case 0:
        GPT0.GTIOR.WORD = (GPT0.GTIOR.WORD & 0x00FF) | 0x0500;
        break;
    case PWM_MAX:
        GPT0.GTIOR.WORD = (GPT0.GTIOR.WORD & 0x00FF) | 0x0200;
        break;
    default:
        GPT0.GTIOR.WORD = (GPT0.GTIOR.WORD & 0x00FF) | 0x0600;
        GPT0.GTCCRB = gtccr;
        break;
    }
}

void SetPWM_B1(unsigned short gtccr)
{
    switch (gtccr)
    {
    case 0:
        GPT1.GTIOR.WORD = (GPT1.GTIOR.WORD & 0x00FF) | 0x0500;
        break;
    case PWM_MAX:
        GPT1.GTIOR.WORD = (GPT1.GTIOR.WORD & 0x00FF) | 0x0200;
        break;
    default:
        GPT1.GTIOR.WORD = (GPT1.GTIOR.WORD & 0x00FF) | 0x0600;
        GPT1.GTCCRB = gtccr;
        break;
    }
}

void SetPWM_B2(unsigned short gtccr)
{
    switch (gtccr)
    {
    case 0:
        GPT2.GTIOR.WORD = (GPT2.GTIOR.WORD & 0x00FF) | 0x0500;
        break;
    case PWM_MAX:
        GPT2.GTIOR.WORD = (GPT2.GTIOR.WORD & 0x00FF) | 0x0200;
        break;
    default:
        GPT2.GTIOR.WORD = (GPT2.GTIOR.WORD & 0x00FF) | 0x0600;
        GPT2.GTCCRB = gtccr;
        break;
    }
}

void calcPWM_A_Sine(float theta_e)
{
    SetPWM_A0((PWM_LimitA  / 2) * (sinf(theta_e) + 1));
    SetPWM_A1((PWM_LimitA  / 2) * (sinf(theta_e + _4pi_6) + 1));
    SetPWM_A2((PWM_LimitA  / 2) * (sinf(theta_e + _8pi_6) + 1));
}

void calcPWM_B_Sine(float theta_e)
{
    SetPWM_B0((PWM_LimitB / 2) * (sinf(theta_e) + 1));
    SetPWM_B1((PWM_LimitB / 2) * (sinf(theta_e + _4pi_6) + 1));
    SetPWM_B2((PWM_LimitB / 2) * (sinf(theta_e + _8pi_6) + 1));
}

void calcPWM_A(float theta_e)
{

    theta_e = fmodf(theta_e, 2 * Pi);
    if (theta_e < 0)
    {
        theta_e = theta_e + (2 * Pi);
    }

    if (theta_e < _2pi_6)
    {
        PWM = (tanf(theta_e) * PWM_LimitA) / (sin2pi_3 - (cos2pi_3 * tanf(theta_e)));
        phase = 1;
    }
    else if (theta_e < _4pi_6)
    {
        PWM = -(tanf(theta_e) * cos2pi_3 * PWM_MAX - sin2pi_3 * PWM_LimitA) / (tanf(theta_e));
        phase = 2;
    }
    else if (theta_e < _6pi_6)
    {
        PWM = (tanf(theta_e) * cos2pi_3 * PWM_MAX - sin2pi_3 * PWM_LimitA) / (sin4pi_3 - cos4pi_3 * tanf(theta_e));
        phase = 3;
    }
    else if (theta_e < _8pi_6)
    {
        PWM = (tanf(theta_e) * cos4pi_3 * PWM_MAX - sin4pi_3 * PWM_LimitA) / (sin2pi_3 - cos2pi_3 * tanf(theta_e));
        phase = 4;
    }
    else if (theta_e < _10pi_6)
    {
        PWM = -(tanf(theta_e) * cos4pi_3 * PWM_MAX - sin4pi_3 * PWM_LimitA) / (tanf(theta_e));
        phase = 5;
    }
    else if (theta_e < _12pi_6)
    {
        PWM = (tanf(theta_e) * PWM_LimitA) / (sin4pi_3 - (cos4pi_3 * tanf(theta_e)));
        phase = 6;
    }

    switch (phase)
    {
    case 1:
        SetPWM_A0(PWM_LimitA);
        SetPWM_A1(PWM);
        SetPWM_A2(0);
        break;
    case 2:
        SetPWM_A0(PWM);
        SetPWM_A1(PWM_LimitA);
        SetPWM_A2(0);
        break;
    case 3:
        SetPWM_A0(0);
        SetPWM_A1(PWM_LimitA);
        SetPWM_A2(PWM);
        break;
    case 4:
        SetPWM_A0(0);
        SetPWM_A1(PWM);
        SetPWM_A2(PWM_LimitA);
        break;
    case 5:
        SetPWM_A0(PWM);
        SetPWM_A1(0);
        SetPWM_A2(PWM_LimitA);
        break;
    case 6:
        SetPWM_A0(PWM_LimitA);
        SetPWM_A1(0);
        SetPWM_A2(PWM);
        break;
    }
}
