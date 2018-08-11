/*
 * user_rotaryencoder.c
 *
 *  Created on: 29.04.2018
 *      Author: grobr
 */


#include "user_rotaryencoder.h"


void rotaryencoder_init(){
	HAL_TIM_Encoder_Start_IT(&htim4,TIM_CHANNEL_ALL);
}

char rotaryencoder_turn(){
	static uint32_t old_turn = 0;
	if(old_turn > TIM4->CNT)
		return 'l';
	else if(old_turn < TIM4->CNT)
		return 'r';
	else if(old_turn == TIM4->CNT)
		return 'c';
	else
		return 'x';
}
