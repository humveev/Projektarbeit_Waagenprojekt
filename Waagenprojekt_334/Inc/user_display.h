/*
 * user_display.h
 *
 *  Created on: 26.04.2018
 *      Author: grobr
 *
 *      Usage:
 *		Init and write on the Display with SPI.
 *
 *		Use pin PC4 to select LCD (Nucleo Dev Board STM32F103C4xx)
 *
 *		All Commands have a Prefix Command of 0xFE.
 */

#ifndef USER_DISPLAY_H_
#define USER_DISPLAY_H_

#include <stdint.h>
#include <string.h>
#include "spi.h"

void display_send_command(char* data);
void display_init(void);
void display_on(void);
void display_off(void);
void display_cursor_set(char row, char col);
void display_cursor_underline(uint8_t);
void display_cursor_home(void);
void display_cursor_move_left(void);
void display_cursor_move_right(void);
void display_blinking_cursor(uint8_t);
void display_backspace(void);
void display_clear(void);
void display_constrast(char);
void display_brightness(char);
void display_move_left(void);
void display_move_right(void);
void display_firmware(void);

void display_write(char* string);
void display_set_write(char* string,char row,char col);

#endif /* USER_DISPLAY_H_ */
