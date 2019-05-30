extern unsigned short ms;

void InitialDelay(void);
void delay_cycles(unsigned long count);
void delay_ms(unsigned short ms_delay);
void getms(unsigned long *count);
void _NOP(void);
void Cmt0IntFunc(void);