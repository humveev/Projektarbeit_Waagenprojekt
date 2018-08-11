/*
 * user_7segment.c
 *
 *  Created on: 26.04.2018
 *      Author: grobr
 */

#include "user_7segment.h"

void seg7_send_command(char* data, uint16_t length) {
	char numbers[length];
	int i,j;
	for(i=0,j=length-1; i<length; i++,j--){
		numbers[j] = data[i];
	}

	//HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_RESET);		//SPI SS

/*	for(i=0;i<length-1;i++){
		HAL_SPI_Transmit(&hspi2,(uint8_t * ) data+i, 1, 0xFF);
	}*/

	HAL_SPI_Transmit(&hspi1, (uint8_t *) numbers, length, 0xFF);


	//HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_SET);			//not SPI SS


	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6,GPIO_PIN_SET);		//Pulses Ledge to display data
	HAL_Delay(10);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6,GPIO_PIN_RESET);

}


void seg7_clear(){
	//uint8_t zero = seg_a + seg_b + seg_c + seg_d + seg_e + seg_f;
	char data[]={0x00,0x00,0x00,0x00,0x00};
	seg7_send_command(data,5);
}

void seg7_send_data(char* number, uint8_t point, uint16_t point_place) {
	int i;
	uint16_t length = strlen(number);
	char data[length];
	for (i = 0; i < length; i++) {
		data[i] = 0x00;
		switch (number[i]) {
		case '1':
			data[i] = seg_b + seg_c;							//
			break;
		case '2':
			data[i] = seg_a + seg_b + seg_g + seg_e + seg_d;	//
			break;
		case '3':
			data[i] = seg_a + seg_b + seg_g + seg_c + seg_d;
			break;
		case '4':
			data[i] = seg_f + seg_g + seg_b + seg_c;
			break;
		case '5':
			data[i] = seg_a + seg_f + seg_g + seg_c + seg_d;
			break;
		case '6':
			data[i] = seg_a + seg_f + seg_e + seg_g + seg_d + seg_c;
			break;
		case '7':
			data[i] = seg_a + seg_b + seg_c;
			break;
		case '8':
			data[i] = seg_a + seg_b + seg_c + seg_d + seg_e + seg_f + seg_g;
			break;
		case '9':
			data[i] = seg_a + seg_f + seg_b + seg_g + seg_c + seg_d;
			break;
		case '0':
			data[i] = seg_a + seg_b + seg_c + seg_d + seg_e + seg_f;
			break;
		case '-':
			data[i] = seg_g;
			break;
		default:
			data[i] += seg_a + seg_f + seg_g + seg_e + seg_d;
			break;
		}
		if (point > 0 && i == point_place - 1) {
			data[i] += seg_dp;
		}
		}
	seg7_send_command(data, length);
}
