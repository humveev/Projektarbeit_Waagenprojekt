/*
 * user_7segment.h
 *
 *  Created on: 26.04.2018
 *      Author: grobr
 *
 *      Usage:
 *      Init and write to the 7-segment Display for printing out the
 *      value.
 *
 *		Shifting from high to low. First digit is lowest (after decimal point)
 *
 *      Use pin PC5 to select LCD (Nucleo Dev Board STM32F103C4xx)
 *
 *      Output 0 ==> Segment a
 *      Output 1 ==> Segment b
 *      Output 2 ==> Segment c
 *      Output 3 ==> Segment d
 *      Output 4 ==> Segment e
 *      Output 5 ==> Segment f
 *      Output 6 ==> Segment g
 *      Output 7 ==> Segment DP
 *
 *
 *
 */

#ifndef USER_7SEGMENT_H_
#define USER_7SEGMENT_H_

#define seg_a		0b1
#define seg_b		0b10
#define seg_c		0b100
#define seg_d		0b1000
#define seg_e		0b10000
#define seg_f		0b100000
#define seg_g		0b1000000
#define seg_dp		0b10000000


#include <stdint.h>
#include <string.h>
#include "spi.h"

void seg7_send_command(char* data, uint16_t length);

void seg7_clear(void);
void seg7_send_data(char* number, uint8_t dp,uint16_t point_place);


#endif /* USER_7SEGMENT_H_ */
