void InitialI2C(void);
int I2C_Write(unsigned char SlaveAdd, unsigned char RegAdd, unsigned char length, unsigned char const *data);
int I2C_Read(unsigned char SlaveAdd, unsigned char RegAdd, unsigned char length, unsigned char *data);
void IIC0MasterReFunc(void);
void IIC0MasterTrFunc(void);

void MPU6050_Read(unsigned char device, unsigned char address, unsigned char *data, unsigned int data_size);
void MPU6050_WriteSingle(unsigned char device,unsigned char address,unsigned char data);
float MPU6050_GetTemperature(void);
void MPU6050_GetGyroXYZ(short XYZ[3]);

extern int mpu_initialized;
extern unsigned short TxDoneFlag;
extern unsigned short RxDoneFlag;
