#include <main.h>
#include <i2c.h>
#include <fuel_sensor.h>

void calibration (float *MEAS1_EMPTY, float *MEAS2_EMPTY, float *MEAS3_EMPTY) {
	float sum1=0, sum2=0, sum3=0;
	uint16_t MEAS1, MEAS2, MEAS3;
		
	uint8_t MEAS1_MSB = 0x00;//Pointer for Register MSB portion of Measurement 1
	uint8_t MEAS2_MSB = 0x02;//Pointer for Register MSB portion of Measurement 2
	uint8_t MEAS3_MSB = 0x04;//Pointer for Register MSB portion of Measurement 3
		
	uint8_t CONF_MEAS1 = 0x08;//Pointer for Register Measurement 1 configuration
	uint8_t CONF_MEAS2 = 0x09;//Pointer for Register Measurement 2 configuration
	uint8_t CONF_MEAS3 = 0x0A;//Pointer for Register Measurement 3 configuration
			
	uint8_t FDC_CONF = 0x0C;//Pointer to Configuration settings
		
	uint16_t MEAS1_CONF_VAL = 0b0001110000000000;//CHA=CIN1, CHB=disabled, CAPDAC=0
	uint16_t MEAS2_CONF_VAL = 0b0011110000000000;//CHA=CIN2, CHB=disabled, CAPDAC=0
	uint16_t MEAS3_CONF_VAL = 0b0101110000000000;//CHA=CIN3, CHB=disabled, CAPDAC=0
	uint16_t FDC_VAL = 0b0000110111100000;//400S/s, REPEAT=1, MEAS1=enabled, MEAS2=enabled, MEAS3=enabled
		
	uint8_t M1_MSB[2];//MSB measurement 1
	uint8_t M2_MSB[2];//MSB measurement 2
	uint8_t M3_MSB[2];//MSB measurement 3
							
	write_register(CONF_MEAS1, MEAS1_CONF_VAL);
	write_register(CONF_MEAS2, MEAS2_CONF_VAL);
	write_register(CONF_MEAS3, MEAS3_CONF_VAL);
		
	write_register(FDC_CONF, FDC_VAL);
	
	for (int i=0; i<3000; i++) {		
		read_register(MEAS1_MSB, M1_MSB);
		read_register(MEAS2_MSB, M2_MSB);
		read_register(MEAS3_MSB, M3_MSB);
						
		MEAS1 = M1_MSB[0] << 8 | M1_MSB[1];
		MEAS2 = M2_MSB[0] << 8 | M2_MSB[1];
		MEAS3 = M3_MSB[0] << 8 | M3_MSB[1];
								
		if (i>1000) {			
			sum1 = sum1+(float)MEAS1;
			sum2 = sum2+(float)MEAS2;
			sum3 = sum3+(float)MEAS3;
		}
		else {
			sum1 = sum1;
			sum2 = sum2;
			sum3 = sum3;
		}}
		
		*MEAS1_EMPTY = sum1/2000;//empty container - measurement 1
		*MEAS2_EMPTY = sum2/2000;//empty container - measurement 2
		*MEAS3_EMPTY = sum3/2000;//empty container - measurement 3
}

int level_step (float level) {//liquid level 5% accuracy
	if (level>100)
		level=100;
	else if (level>95 && level<100)
		level=95;
	else if (level>90 && level<95)
		level=90;
	else if (level>85 && level<90)
		level=85;
	else if (level>80 && level<85)
		level=80;
	else if (level>75 && level<80)
		level=75;
	else if (level>70 && level<75)
		level=70;
	else if (level>65 && level<70)
		level=65;
	else if (level>60 && level<65)
		level=60;
	else if (level>55 && level<60)
		level=55;
	else if (level>50 && level<55)
		level=50;
	else if (level>45 && level<50)
		level=45;
	else if (level>40 && level<45)
		level=40;
	else if (level>35 && level<40)
		level=35;
	else if (level>30 && level<35)
		level=30;
	else if (level>25 && level<30)
		level=25;
	else if (level>20 && level<25)
		level=20;
	else if (level>15 && level<20)
		level=15;
	else if (level>10 && level<15)
		level=10;
	else if (level>5 && level<10)
		level=5;
	else if (level<5)
		level=0;

return level;
}

float median_filter (float input[5]) {//median filter
	float output[5];
	float dummy;
	
	for (int i=0; i<5; i++) {
		float min=input[i];
		for (int j=i+1; j<5; j++) {
			if (input[j]<min) {
				dummy=min;
				min=input[j];
				input[j]=dummy;
		}
		output[i]=min;
	}
}
	return output[2];//median value
}


void liquid_level (float *MEAS1_EMPTY, float *MEAS2_EMPTY, float *MEAS3_EMPTY, float *MEAS1, float *MEAS2, float *MEAS3, int *fuel_level, float *level) {
	float level_pom=0;
	float sum1=0, sum2=0, sum3=0;
	float m1=0, m2=0, m3=0;
	float data1[5], data2[5], data3[5];
	uint8_t M1_MSB[2], M2_MSB[2], M3_MSB[2];
	
	uint8_t MEAS1_MSB = 0x00;//Pointer for Register MSB portion of Measurement 1
	uint8_t MEAS2_MSB = 0x02;//Pointer for Register MSB portion of Measurement 2
	uint8_t MEAS3_MSB = 0x04;//Pointer for Register MSB portion of Measurement 3
	
	for (int j=0; j<5; j++) {
		for (int i=0; i<400; i++) {			
			read_register(MEAS1_MSB, M1_MSB);
			read_register(MEAS2_MSB, M2_MSB);
			read_register(MEAS3_MSB, M3_MSB);
						
			*MEAS1 = M1_MSB[0] << 8 | M1_MSB[1];
			*MEAS2 = M2_MSB[0] << 8 | M2_MSB[1];
			*MEAS3 = M3_MSB[0] << 8 | M3_MSB[1];
				
			sum1 = sum1+(float)*MEAS1;
			sum2 = sum2+(float)*MEAS2;
			sum3 = sum3+(float)*MEAS3;
		}
		
		m1 = sum1/400;
		m2 = sum2/400;
		m3 = sum3/400;
	
		sum1 = 0;
		sum2 = 0;
		sum3 = 0;
		
		data1[j] = m1;
		data2[j] = m2;
		data3[j] = m3;
	}
		
	m1 = median_filter(data1);
	m2 = median_filter(data2);
	m3 = median_filter(data3);
		
	level_pom = (m1-*MEAS1_EMPTY)/(m2-*MEAS2_EMPTY)*10+5;
	 
	if (level_pom>25)
		*level = level_pom;//float liquid level
	else if (level_pom<25)
		*level = level_pom*5-100;//float liquid level
					
	if (*level>100)
		*level=100;
	else if (*level<0)
		*level=0;
		
	*fuel_level = level_step(*level);//liquid level 5% accuracy
}

void read_register(uint8_t register_pointer, uint8_t* receive_buffer) {
    HAL_I2C_Master_Transmit(&hi2c1, 0xA0, &register_pointer, 1, 100);  
	  HAL_I2C_Master_Receive(&hi2c1, 0xA0, receive_buffer, 2, 100);   
}

void register_init () {

uint8_t CONF_MEAS1 = 0x08; //Pointer for Register Measurement 1 configuration
uint8_t CONF_MEAS2 = 0x09; //Pointer for Register Measurement 2 configuration
uint8_t CONF_MEAS3 = 0x0A; //Pointer for Register Measurement 3 configuration
			
uint8_t FDC_CONF = 0x0C; //Pointer to Configuration settings
	
uint16_t MEAS1_CONF_VAL = 0b0001110000000000;// CHA=CIN1, CHB=disabled, CAPDAC=0
uint16_t MEAS2_CONF_VAL = 0b0011110000000000;// CHA=CIN2, CHB=disabled, CAPDAC=0
uint16_t MEAS3_CONF_VAL = 0b0101110000000000;// CHA=CIN3, CHB=disabled, CAPDAC=0
uint16_t FDC_VAL = 0b0000110111100000;// 400S/s, REPEAT=1, MEAS1=enabled, MEAS2=enabled, MEAS3=enabled
		
uint8_t M1_MSB[2];
uint8_t M2_MSB[2];
uint8_t M3_MSB[2];
							
write_register(CONF_MEAS1, MEAS1_CONF_VAL);
write_register(CONF_MEAS2, MEAS2_CONF_VAL);
write_register(CONF_MEAS3, MEAS3_CONF_VAL);
		
write_register(FDC_CONF, FDC_VAL);
}

void write_register(uint8_t register_pointer, uint16_t register_value) {
    uint8_t data[3];
    data[0] = register_pointer;
    data[1] = register_value>>8;// MSB byte of 16bit data
    data[2] = register_value;// LSB byte of 16bit data
    HAL_I2C_Master_Transmit(&hi2c1, 0xA0, data, 3, 100);// data is the start pointer of array
}