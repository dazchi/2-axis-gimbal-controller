#define PWM_MAX (4095)
#define N_POLES (14)

extern const float Pi;

extern float sin2pi_3;
extern float sin4pi_3;
extern float cos2pi_3;
extern float cos4pi_3;
 
extern float _2pi_6;
extern float _4pi_6;
extern float _6pi_6;
extern float _8pi_6;
extern float _10pi_6;
extern float _12pi_6;

extern float Rad2Deg;
extern float Deg2Rad;

extern unsigned short phase;
extern unsigned short PWM;
extern unsigned short PWM_Limit;

void InitialPWMs(voidvv);
void EnablePWM_A(void);
void DisablePWM_A(void);
void EnablePWM_B(void);
void DisablePWM_B(void);
void SetPWM_A0(unsigned short gtccr);
void SetPWM_A1(unsigned short gtccr);
void SetPWM_A2(unsigned short gtccr);
void SetPWM_B0(unsigned short gtccr);
void SetPWM_B1(unsigned short gtccr);
void SetPWM_B2(unsigned short gtccr);
void calcPWM_A_Sine(float theta_e);
void calcPWM_B_Sine(float theta_e);
void calcPWM_A(float theta_e);

