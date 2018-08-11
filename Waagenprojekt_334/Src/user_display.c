/*
 * user_display.c
 *
 *  Created on: 26.04.2018
 *      Author: grobr
 */



#include "user_display.h"


void display_send_command(char *data){
	char send[2];
	int i,j;
//	for(i=0,j=1;i<2;i++,j--){
//		send[j]=data[i];
//	}
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_4,GPIO_PIN_RESET);
	HAL_SPI_Transmit(&hspi1, (uint8_t *) data, 2, 0xFF);
	HAL_Delay(11);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_4,GPIO_PIN_SET);
}

void display_init(){
	char data[] ={0xFE, 0x41};
	display_send_command(data);
}
void display_on(){
	char data[] = {0xFE, 0x41};
	display_send_command(data);
}
void display_off(){
	char data[] = {0xFE, 0x42};
	display_send_command(data);
}


void display_cursor_set(char row, char col){
	char data[] = {0xFE ,0x45};
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_4,GPIO_PIN_RESET);
	HAL_SPI_Transmit(&hspi1, (uint8_t*) data, 2, 0xFF);
	switch(row){
	case 0:
		data[0]=0x00;
		break;
	case 1:
		data[0]=0x40;
		break;
	case 2:
		data[0]=0x14;
		break;
	case 3:
		data[0]=0x54;
		break;
	}
	if(col>=0 && col<20){
		data[0] += col;
	}
	HAL_SPI_Transmit(&hspi1, (uint8_t *) data,1,0xFF);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_4,GPIO_PIN_SET);
}


void display_cursor_underline(uint8_t status){
	char data[] = {0xFE, 0x00};
	if(status == 1)
		data[1] = 0x47;
	else
		data[1] = 0x48;

	display_send_command(data);
}
void display_cursor_home(){
	char data[] = {0xFE, 0x46};
	display_send_command(data);
}
void display_cursor_move_left(){
	char data[] = {0xFE, 0x49};
	display_send_command(data);
}
void display_cursor_move_right(){
	char data[] = {0xFE, 0x4A};
	display_send_command(data);
}
void display_blinking_cursor(uint8_t status){
	char data[] = {0xFE, 0x00};
	if(status == 1)
		data[1] = 0x4B;
	else
		data[1] = 0x4C;

	display_send_command(data);
}
void display_backspace(void){
	char data[] = {0xFE, 0x4E};
	display_send_command(data);
}
void display_clear(){
	char data[] = {0xFE, 0x51};
	display_send_command(data);
}
void display_constrast(char value){
	char data[] = {0xFE, 0x52};
	HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_4);
	HAL_SPI_Transmit(&hspi1, (uint8_t *) data, 2, 0xFF);
	if(value >= 0 && value < 51)
		data[0] = value;
	else;
	HAL_SPI_Transmit(&hspi1, (uint8_t *) data, 1, 0xFF);
	HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_4);
}
void display_brightness(char value){
	char data[] = {0xFE, 0x52};
	HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_4);
	HAL_SPI_Transmit(&hspi1, (uint8_t *) data, 2, 0xFF);
	if(value >= 0 && value < 51)
		data[0] = value;
	else;
	HAL_SPI_Transmit(&hspi1, (uint8_t *) data, 1, 0xFF);
	HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_4);
}
void display_move_left(){
	char data[] = {0xFE,0x55};
	display_send_command(data);
}
void display_move_right(){
	char data[] = {0xFE,0x56};
	display_send_command(data);
}
void display_firmware(){
	char data[] = {0xFE,0x70};
	display_send_command(data);
}

void display_write(char* string){
	uint32_t length = strlen(string);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4,GPIO_PIN_RESET);
	HAL_SPI_Transmit(&hspi1, (uint8_t *) string, length, 0xFF);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4,GPIO_PIN_SET);
}

void display_set_write(char* string, char row, char col){
	uint32_t length = strlen(string);

	char data[] = {0xFE ,0x45};
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_4,GPIO_PIN_RESET);
	HAL_SPI_Transmit(&hspi1, (uint8_t*) data, 2, 0xFF);
	switch(row){
	case 0:
		data[0]=0x00;
		break;
	case 1:
		data[0]=0x40;
		break;
	case 2:
		data[0]=0x14;
		break;
	case 3:
		data[0]=0x54;
		break;
	}
	if(col>=0 && col<20){
		data[0] += col;
	}
	HAL_SPI_Transmit(&hspi1, (uint8_t *) data,1,0xFF);
	HAL_SPI_Transmit(&hspi1, (uint8_t *) string, length, 0xFF);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4,GPIO_PIN_SET);
}
