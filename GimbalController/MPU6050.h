void DMP_Init(void);
unsigned char Read_DMP(float *Pitch, float *Roll, float *Yaw);
static unsigned short inv_orientation_matrix_to_scalar(const signed char *mtx);
static unsigned short inv_row_2_scale(const signed char *row);
static void run_self_test(void);

extern int calibrate_flag;

