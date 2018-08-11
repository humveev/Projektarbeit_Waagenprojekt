/*
 * user_menu_guide.c
 *
 *  Created on: 11.05.2018
 *      Author: grobr
 */


#include "user_menu_guide.h"
extern display_settings this_display;


void menu_Save(){
	this_display.current_screen='S';
	this_display.cursor_border[0]=1;
	this_display.cursor_border[1]=2;
	this_display.cursor_pos=2;


	display_clear();
	display_set_write("Speichern",0,3);
	display_set_write("Ja!",1,3);
	display_set_write("Nein!",2,3);
}

void menu_Main(){
	display_settings this_display;
	this_display.cursor = 0b01111110;
	this_display.current_screen='M';
	this_display.cursor_border[0]=1;
	this_display.cursor_border[1]=2;

	display_clear();
	display_set_write("Hauptmenü",0,3);
	display_set_write("Kalibrieren",1,3);
	display_set_write("Speichern",2,3);
}

