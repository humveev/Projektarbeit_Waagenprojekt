/*
 * user_adafruit_adc.c
 *
 *  Created on: 02.05.2018
 *      Author: grobr
 */

#include "user_adafruit_adc.h"

void Adafruit_ADS1115_writeRegister(uint16_t i2cAddress, uint8_t reg, uint16_t value){
	HAL_I2C_Master_Transmit(&hi2c1,i2cAddress,&reg,1,0xFF);
	HAL_I2C_Master_Transmit(&hi2c1,i2cAddress,&value,2,0xFF);
}

uint16_t Adafruit_ADS1115_readRegister(uint16_t i2cAddress, uint8_t reg){
	uint16_t data=0;
	HAL_I2C_Master_Transmit(&hi2c1,i2cAddress,&reg,1,0xFF);
	HAL_I2C_Master_Receive(&hi2c1,i2cAddress,&data,2,0xFF);
	return data;
}

uint16_t Adafruit_ADS1115_SingleEnded(uint8_t channel){

	volatile uint8_t data[2] = {0};
	volatile uint16_t data_ret = 0;
	volatile uint16_t config = 0;
	volatile uint16_t config_bytereverse = 0;

	config = ADS1115_REG_CONFIG_CQUE_NONE|
					  ADS1115_REG_CONFIG_CLAT_NONLAT|
					  ADS1115_REG_CONFIG_CPOL_ACTVLOW|
					  ADS1115_REG_CONFIG_CMODE_TRAD|
					  ADS1115_REG_CONFIG_DR_128SPS|
					  ADS1115_REG_CONFIG_MODE_SINGLE;


	config |= GAIN_TWOTHIRDS;

	config |= ADS1115_REG_CONFIG_OS_SINGLE;

	switch(channel){
		case(0):
				config |= ADS1115_REG_CONFIG_MUX_SINGLE_0;
				break;
		case(1):
				config |= ADS1115_REG_CONFIG_MUX_SINGLE_1;
				break;
		case(2):
				config |= ADS1115_REG_CONFIG_MUX_SINGLE_2;
				break;
		case(3):
				config |= ADS1115_REG_CONFIG_MUX_SINGLE_3;
				break;
		default:
				return 0xFFFF;
	}

	config_bytereverse = (config << 8) + (config >> 8);


	HAL_I2C_Mem_Write(&hi2c1,ADS1115_ADDRESS,ADS1115_REG_POINTER_CONFIG,I2C_MEMADD_SIZE_8BIT, &config_bytereverse,2,0xFF);

	HAL_Delay(ADS1115_CONVERSIONDELAY);

	HAL_I2C_Mem_Read(&hi2c1,ADS1115_ADDRESS,ADS1115_REG_POINTER_CONVERT,I2C_MEMADD_SIZE_8BIT,(uint8_t*) &data_ret,2,0xFF);
	//data_ret = data[0] + data[1];

	data_ret = (data_ret<<8) + (data_ret>>8);

	if(data_ret == 0xFFFF){
		data_ret = 0x0000;
	}

	return data_ret;
}

