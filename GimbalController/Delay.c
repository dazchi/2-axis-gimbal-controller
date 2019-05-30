#include "Delay.h"

unsigned short ms = 0;

void InitialDelay(void){
    R_PG_Timer_Start_CMT_U0_C0();
}

void delay_cycles(unsigned long count)
{
    unsigned long i = 0;
    for (; i < count; i++);
}

void delay_ms(unsigned short ms_delay)
{
    ms = 0;
    R_PG_Timer_Start_CMT_U0_C0();
    while (ms < ms_delay);
    R_PG_Timer_StopModule_CMT_U0();
}

void _NOP(void){
    delay_cycles(1);
}

void getms(unsigned long *count){
    *count = 0;
}

void Cmt0IntFunc(void)
{
    ms++;
}

