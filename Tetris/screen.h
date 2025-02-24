#pragma once


void clear();
void move_cursor(short x, short y);
short get_cursor_x();
short get_cursor_y();
short get_window_width();
short get_window_height();
void hide_cursor();
void show_cursor();
void change_cursor(short size);
void mvprint(short x, short y, char ch);
void mvprint(short x, short y, const char* str);