#pragma once
#include<iostream>
#include<fstream>
#include <stdio.h>
#include <string>
#include <conio.h>
#include <locale>
#include <codecvt>
#include <cstdio>  // for _fileno
#include <io.h>    // for _setmode
#include <fcntl.h> // for _O_U16TEXT
#include<ctime> /* thư viện hỗ trợ về thời gian thực */
#include "windows.h" // thư viện này bá đạo lắm nhé - chứa nhiều đồ chơi nek - cứ tìm hiểu dần dần s
using namespace std;
//======= lấy tọa độ x của con trỏ hiện tại =============
#define KEY_NONE	-1
//Khai báo các biến toàn cục
static int x, y;
static HANDLE hConsoleColor;
//Ghi lỗi và thoát ra
static VOID WriteError(LPSTR lpszMessage) {
    printf("%s\n", lpszMessage);
    ExitProcess(0);
}
inline int whereX()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
        return csbi.dwCursorPosition.X;
    return -1;
}
//========= lấy tọa độ y của con trỏ hiện tại =======
inline int whereY()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
        return csbi.dwCursorPosition.Y;
    return -1;
}
//============== dịch con trỏ hiện tại đến điểm có tọa độ (x,y) ==========
inline void gotoXY(int x, int y)
{
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos = { x, y };
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
//============= đặt màu cho chữ =========
static void SetColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
//============== làm ẩn trỏ chuột ===========
static void ShowCur(bool CursorVisibility)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
    SetConsoleCursorInfo(handle, &cursor);
}
//======= trả về mã phím người dùng bấm =========
static int inputKey()
{
    if (_kbhit())
    {
        int key = _getch();

        if (key == 224)
        {
            key = _getch();
            return key + 1000;
        }

        return key;
    }
    else
    {
        return KEY_NONE;
    }

    return KEY_NONE;
}
static void paint()
{
    hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
    if ((x >= 40 && x <= 61) && (y >= 4 && y <= 6))
    {
        gotoXY(40, 4);
        SetConsoleTextAttribute(hConsoleColor, 192);
        wcout << L"╔════════════════════╗";
        gotoXY(40, 5);
        wcout << L"║";
        SetConsoleTextAttribute(hConsoleColor, 206);
        wcout << L"    App Banking     ";
        SetConsoleTextAttribute(hConsoleColor, 192);
        wcout << L"║";
        gotoXY(40, 6);
        wcout << L"╚════════════════════╝";
    }
    else
    {
        gotoXY(40, 4);
        SetConsoleTextAttribute(hConsoleColor, 224);
        wcout << L"╔════════════════════╗";
        gotoXY(40, 5);
        wcout << L"║";
        SetConsoleTextAttribute(hConsoleColor, 228);
        wcout << L"    App Banking     ";
        SetConsoleTextAttribute(hConsoleColor, 224);
        wcout << L"║";
        gotoXY(40, 6);
        wcout << L"╚════════════════════╝";
    }
    if ((x >= 40 && x <= 61) && (y >= 9 && y <= 11))
    {
        gotoXY(40, 9);
        SetConsoleTextAttribute(hConsoleColor, 192);
        wcout << L"╔════════════════════╗";
        gotoXY(40, 10);
        wcout << L"║";
        SetConsoleTextAttribute(hConsoleColor, 206);
        wcout << L"        ATM         ";
        SetConsoleTextAttribute(hConsoleColor, 192);
        wcout << L"║";
        gotoXY(40, 11);
        wcout << L"╚════════════════════╝";
    }
    else
    {
        gotoXY(40, 9);
        SetConsoleTextAttribute(hConsoleColor, 224);
        wcout << L"╔════════════════════╗";
        gotoXY(40, 10);
        wcout << L"║";
        SetConsoleTextAttribute(hConsoleColor, 228);
        wcout << L"        ATM         ";
        SetConsoleTextAttribute(hConsoleColor, 224);
        wcout << L"║";
        gotoXY(40, 11);
        wcout << L"╚════════════════════╝";
    }
    if ((x >= 40 && x <= 61) && (y >= 14 && y <= 16))
    {
        gotoXY(40, 14);
        SetConsoleTextAttribute(hConsoleColor, 192);
        wcout << L"╔════════════════════╗";
        gotoXY(40, 15);
        wcout << L"║";
        SetConsoleTextAttribute(hConsoleColor, 206);
        wcout << L" Thoát chương trình ";
        SetConsoleTextAttribute(hConsoleColor, 192);
        wcout << L"║";
        gotoXY(40, 16);
        wcout << L"╚════════════════════╝";
        SetConsoleTextAttribute(hConsoleColor, 7);
    }
    else
    {
        gotoXY(40, 14);
        SetConsoleTextAttribute(hConsoleColor, 224);
        wcout << L"╔════════════════════╗";
        gotoXY(40, 15);
        wcout << L"║";
        SetConsoleTextAttribute(hConsoleColor, 228);
        wcout << L" Thoát chương trình ";
        SetConsoleTextAttribute(hConsoleColor, 224);
        wcout << L"║";
        gotoXY(40, 16);
        wcout << L"╚════════════════════╝";
        SetConsoleTextAttribute(hConsoleColor, 7);
    }
}