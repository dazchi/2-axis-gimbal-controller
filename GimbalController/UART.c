#include "UART.h"
#include "stdlib.h"
#include "stdarg.h"

unsigned char RxBuffer[64] = {0};
unsigned char TxBuffer[64] = {0};

void InitialUART(void)
{
    R_PG_SCI_Set_C2();
}

void LOG(const char *fmt, ...)
{
    char str[128];
    int length = 0;

    va_list args;
    va_start(args, fmt);
    length = vsprintf(str, fmt, args);
    va_end(args);

    R_PG_SCI_SendAllData_C2(str,length);
}