#ifndef FUEL_SENSOR_H
#define FUEL_SENSOR_H
#ifdef __cplusplus
 extern "C" {
#endif

void calibration(float *MEAS1_EMPTY, float *MEAS2_EMPTY, float *MEAS3_EMPTY);
void write_register(uint8_t register_pointer, uint16_t register_value);
void register_init();
void read_register(uint8_t register_pointer, uint8_t* receive_buffer);
void liquid_level(float *MEAS1_EMPTY, float *MEAS2_EMPTY, float *MEAS3_EMPTY, float *MEAS1, float *MEAS2, float *MEAS3, int *fuel_level, float *level);
void calibration(float *MEAS1_EMPTY, float *MEAS2_EMPTY, float *MEAS3_EMPTY);
	 
#ifdef __cplusplus
}
#endif
#endif
