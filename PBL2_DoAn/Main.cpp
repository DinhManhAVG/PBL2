#include "AppBanking.h"
#include "ATM.h"
using namespace std;
int main()
{
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);
    AppBanking abk;
    ATM atm;
    HashTableUser hs;
    HashTableAdmin had;
    HashTableBank hsb;
    hs.docFile();
    had.docFile();
    hsb.docFile();
    ShowCur(false);
    // Vòng lặp để quét qua các event 
    while (true)
    {
        paint();
        HANDLE hStdin;
        HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD CursorPosition;

        // đọc event vào
        DWORD cNumRead, fdwMode, i;
        INPUT_RECORD irInBuf[128];

        // Get the standard input handle. 

        hStdin = GetStdHandle(STD_INPUT_HANDLE);
        if (hStdin == INVALID_HANDLE_VALUE)
            WriteError("GetStdHandle");

        // Mở cửa sổ ở chế độ mở
        fdwMode = ENABLE_EXTENDED_FLAGS;
        if (!SetConsoleMode(hStdin, fdwMode)) {
            WriteError("SetConsoleMode");
        }

        // Mở cửa sổ ở chế độ chấp nhận input

        fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
        if (!SetConsoleMode(hStdin, fdwMode)) {
            WriteError("SetConsoleMode");
        }
        if (!ReadConsoleInput(hStdin, irInBuf, 128, &cNumRead)) {
            WriteError("ReadConsoleInput");
        }
        // xử lý từng event một
        for (i = 0; i < cNumRead; i++)
        {
            // Khai báo các biến mà hàm cần
            INPUT_RECORD Inrec;
            DWORD eventRead;
            HANDLE hStdIn;
            DWORD dwMode;
            bool Captured = false;
            hStdIn = GetStdHandle(STD_INPUT_HANDLE);
            dwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;

            //Kiểm tra xem console đã ở chế độ chấp nhận input từ chuột chưa
            if (SetConsoleMode(hStdIn, dwMode | ENABLE_MOUSE_INPUT) == TRUE)

                GetConsoleMode(hStdIn, &dwMode);
            SetConsoleMode(hStdIn, (dwMode & (ENABLE_MOUSE_INPUT)));

            if (GetAsyncKeyState(0x01))
            {
                // vòng lặp này sẽ lấy các event của trong bộ nhớ ra để xử lý
                do
                {
                    PeekConsoleInput(hStdIn, &Inrec, 1, &eventRead);
                    if (eventRead)
                    {
                        ReadConsoleInput(hStdIn, &Inrec, 1, &eventRead);
                        x = Inrec.Event.MouseEvent.dwMousePosition.X;
                        y = Inrec.Event.MouseEvent.dwMousePosition.Y;
                        switch (Inrec.EventType)
                        {

                        case MOUSE_EVENT:
                        {
                            Captured = true;
                            if ((x >= 40 && x <= 61) && (y >= 4 && y <= 6))
                            {
                                while (true)
                                {
                                    system("cls");
                                    int access = 0;
                                    abk.displayTongQuat(hs, access, had);
                                    system("cls");
                                    if (access == 1)
                                        abk.displayAdmin(had, hs, hsb);
                                    else if (access == 2)
                                        abk.displayApp(hs, hsb, had);
                                    else
                                        break;
                                }
                            }
                            else if ((x >= 40 && x <= 61) && (y >= 9 && y <= 11))
                            {
                                system("cls");
                                atm.hienThi();
                                atm.luaChonChucNang(hs);
                            }
                            else if ((x >= 40 && x <= 61) && (y >= 14 && y <= 16))
                            {
                                system("cls");
                                hs.ghiFile();
                                had.ghiFile();
                                hsb.ghiFile();
                                exit(0);
                            }
                            break;
                        }
                        }
                    }

                } while (!Captured);
            }
            else
            {
                // vòng lặp này sẽ lấy các event của trong bộ nhớ ra để xử lý
                do
                {
                    PeekConsoleInput(hStdIn, &Inrec, 1, &eventRead);
                    if (eventRead)
                    {
                        ReadConsoleInput(hStdIn, &Inrec, 1, &eventRead);
                        x = Inrec.Event.MouseEvent.dwMousePosition.X;
                        y = Inrec.Event.MouseEvent.dwMousePosition.Y;
                        switch (Inrec.EventType)
                        {

                        case MOUSE_EVENT:
                        {
                            Captured = true;
                            paint();
                            break;
                        }
                        }
                    }

                } while (!Captured);
            }
        }
    }
    return 0;
}