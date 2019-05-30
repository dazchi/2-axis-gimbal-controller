#include "LED.h"

void InitialLED(void)
{
    R_PG_IO_PORT_Set_P3();
    R_PG_IO_PORT_Write_P3(0x0F);
}

void SetLED1(int state)
{
    R_PG_IO_PORT_Write_P30(state==0?1:0);
}

void SetLED2(int state)
{
    R_PG_IO_PORT_Write_P31(state==0?1:0);
}

void SetLED3(int state)
{
    R_PG_IO_PORT_Write_P32(state==0?1:0);
}

void SetLED4(int state)
{
    R_PG_IO_PORT_Write_P33(state==0?1:0);
}