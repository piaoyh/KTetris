#include <conio.h>
#include <stdio.h>

#include "screen.h"
#include "windows.h"

void clear()
{
	system("cls");
}

void move_cursor(short x, short y)
{
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD   cur;
    cur.X = x;
    cur.Y = y;
    SetConsoleCursorPosition(screen, cur);
}

short get_cursor_x()
{
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO  info;
    GetConsoleScreenBufferInfo(screen, &info);
    return info.dwCursorPosition.X;
}

short get_cursor_y()
{
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO  info;
    GetConsoleScreenBufferInfo(screen, &info);
    return info.dwCursorPosition.Y;
}

short get_window_width()
{
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO  info;
    GetConsoleScreenBufferInfo(screen, &info);
    return info.srWindow.Right + 1;
}

short get_window_height()
{
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO  info;
    GetConsoleScreenBufferInfo(screen, &info);
    return info.srWindow.Bottom + 1;
}


void hide_cursor()
{
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     info;
    info.bVisible = false;
    info.dwSize = 20;
    SetConsoleCursorInfo(screen, &info);
}

void show_cursor()
{
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     info;
    info.bVisible = true;
    info.dwSize = 20;
    SetConsoleCursorInfo(screen, &info);
}

void change_cursor(short size)
{
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     info;
    info.bVisible = true;
    info.dwSize = size;
    SetConsoleCursorInfo(screen, &info);
}

void mvprint(short x, short y, char ch)
{
    move_cursor(x, y);
    _putch(ch);
}

void mvprint(short x, short y, const char* str)
{
    move_cursor(x, y);
    puts(str);
}