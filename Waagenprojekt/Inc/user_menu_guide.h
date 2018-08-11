/*
 * user_menu_guide.h
 *
 *  Created on: 11.05.2018
 *      Author: grobr
 */

#ifndef USER_MENU_GUIDE_H_
#define USER_MENU_GUIDE_H_

#include "user_rotaryencoder.h"
#include "user_display.h"

typedef struct {
	uint8_t cursor;
	uint8_t cursor_pos;
	uint8_t cursor_border[2];
	char current_screen;


}display_settings;


uint8_t menu_cursor_position(void);
void menu_cursor_move(char to);
void menu_onClick(void);

void menu_Calibrate(void);
void menu_Main(void);
void menu_Save(void);

#endif /* USER_MENU_GUIDE_H_ */
