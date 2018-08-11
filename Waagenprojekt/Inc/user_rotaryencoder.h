/*
 * user_rotaryencoder.h
 *
 *  Created on: 29.04.2018
 *      Author: grobr
 */

#include <stdint.h>
#include "tim.h"

#ifndef USER_ROTARYENCODER_H_
#define USER_ROTARYENCODER_H_


void rotaryencoder_init(void);

char rotaryencoder_turn(void);


#endif /* USER_ROTARYENCODER_H_ */
