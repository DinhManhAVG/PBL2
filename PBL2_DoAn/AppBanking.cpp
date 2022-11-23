 #include "AppBanking.h"
void AppBanking::chuyenKhoan(HashTableThe hashtb)
{
    SetColor(11);
    gotoXY(30, 14);
    wstring soTaiKhoanNguoiNhan;
    wcout << L"Nhập số tài khoản cần chuyển: "; wcin >> soTaiKhoanNguoiNhan;
    int soTien;
    gotoXY(30, 16);
    wcout << L"Nhập số tiền cần chuyển: "; wcin >> soTien;
    hashtb.timKiemNguoiNhan(the.getSoTaiKhoan(), soTaiKhoanNguoiNhan, soTien);
    system("pause");
    system("cls");
    SetColor(7);
}
void AppBanking::kiemTraThongTin(HashTableThe hashtb, HashTableBank htbank)
{
    hashtb.timKiemNguoiDung(the.getSoTaiKhoan(), htbank);
    char c = _getch();
    system("cls");
}
void AppBanking::hienThiTopKhachHang(HashTableThe hashtb, HashTableBank htbank)
{
    system("cls");
    hashtb.sapXepTheoSoTaiKhoan(htbank);
    system("pause");
    system("cls");
}
void AppBanking::doiMatKhau(HashTableThe& hashtb)
{
    system("cls");
    paintKhung();
    wstring matKhauHienTai, matKhauMoi;
    gotoXY(30, 7);
    wcout << L"Nhập mật khẩu hiện tại: ";
    wcin >> matKhauHienTai;
    gotoXY(30, 8);
    wcout << L"Nhập mật khẩu mới: ";
    wcin >> matKhauMoi;
    if (matKhauHienTai == the.getMatKhau())
    {
        if (matKhauHienTai != matKhauMoi)
        {
            the.setMatKhau(matKhauMoi);
            hashtb.chinhSuaMatKhau(the.getSoTaiKhoan(), matKhauMoi);
        }
    }
    else
    {
        gotoXY(30, 9);
        wcout << L"Mật khẩu sai!";
    }
    system("pause");
    system("cls");
}
void AppBanking::doiMatKhauAd(HashTableAdmin& hashtad)
{
    system("cls");
    paintKhung();
    wstring matKhauHienTai, matKhauMoi;
    gotoXY(30, 7);
    wcout << L"Nhập mật khẩu hiện tại: ";
    wcin >> matKhauHienTai;
    gotoXY(30, 8);
    wcout << L"Nhập mật khẩu mới: ";
    wcin >> matKhauMoi;
    if (matKhauHienTai == ad.getMatKhauAdmin())
    {
        if (matKhauHienTai != matKhauMoi)
        {
            ad.setMatKhauAdmin(matKhauMoi);
            hashtad.docFile();
            hashtad.chinhSuaMatKhau(ad.getMaAdmin(), matKhauMoi);
            hashtad.ghiFile();
        }
    }
    else
    {
        gotoXY(30, 9);
        wcout << L"Mật khẩu sai!";
    }
    system("pause");
    system("cls");
}

bool AppBanking::checkAccount(wstring acc, wstring pass, wstring nameFile)
{
    wifstream input(nameFile);
    locale utf8_locale(locale(), new codecvt_utf8<wchar_t>);
    input.imbue(utf8_locale);
    wchar_t bom = L'\0';
    input.get(bom);
    wstring s;
    int count = 0;
    bool check_acc = false, check_pass = false;
    while (input >> s)
    {
        if (s == L"|")
        {
            count++;
        }
        else if (s == L"|||")
        {
            count = 0;
        }
        else if (count == 0)
        {
            if (s == acc)
            {
                check_acc = true;
            }
        }
        else if (count == 1)
        {
            if (check_acc)
            {
                if (s == pass)
                    return true;
                else
                    check_acc = false;
            }
        }
    }
    input.close();
    return false;
}
void AppBanking::paintKhung()
{
    SetColor(2);
    gotoXY(20, 6);
    wcout << L"╔══════════════════════════════════════════════════════════════════╗";
    gotoXY(20, 7); wcout << L"║";
    gotoXY(87, 7); wcout << L"║";
    gotoXY(20, 8); wcout << L"║";
    gotoXY(87, 8); wcout << L"║";
    gotoXY(20, 9); wcout << L"║";
    gotoXY(87, 9); wcout << L"║";
    gotoXY(20, 10); wcout << L"║";
    gotoXY(87, 10); wcout << L"║";
    gotoXY(20, 11); wcout << L"║";
    gotoXY(87, 11); wcout << L"║";
    gotoXY(20, 12); wcout << L"║";
    gotoXY(87, 12); wcout << L"║";
    gotoXY(20, 13); wcout << L"║";
    gotoXY(87, 13); wcout << L"║";
    gotoXY(20, 14); wcout << L"║";
    gotoXY(87, 14); wcout << L"║";
    gotoXY(20, 15); wcout << L"║";
    gotoXY(87, 15); wcout << L"║";
    gotoXY(20, 16); wcout << L"║";
    gotoXY(87, 16); wcout << L"║";
    gotoXY(20, 17); wcout << L"║";
    gotoXY(87, 17); wcout << L"║";
    gotoXY(20, 18);
    wcout << L"╚══════════════════════════════════════════════════════════════════╝";
    SetColor(7);
}
void AppBanking::paintApp()
{
    hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
    if ((x >= 25 && x <= 51) && (y >= 5 && y <= 7))
    {
        gotoXY(25, 5);
        SetConsoleTextAttribute(hConsoleColor, 192);
        wcout << L"╔═════════════════════════╗";
        gotoXY(25, 6);
        wcout << L"║";
        SetConsoleTextAttribute(hConsoleColor, 206);
        wcout << L"       Chuyển khoản      ";
        SetConsoleTextAttribute(hConsoleColor, 192);
        wcout << L"║";
        gotoXY(25, 7);
        wcout << L"╚═════════════════════════╝";
    }
    else
    {
        gotoXY(25, 5);
        SetConsoleTextAttribute(hConsoleColor, 224);
        wcout << L"╔═════════════════════════╗";
        gotoXY(25, 6);
        wcout << L"║";
        SetConsoleTextAttribute(hConsoleColor, 228);
        wcout << L"       Chuyển khoản      ";
        SetConsoleTextAttribute(hConsoleColor, 224);
        wcout << L"║";
        gotoXY(25, 7);
        wcout << L"╚═════════════════════════╝";
    }
    if ((x >= 25 && x <= 51) && (y >= 10 && y <= 12))
    {
        gotoXY(25, 10);
        SetConsoleTextAttribute(hConsoleColor, 192);
        wcout << L"╔═════════════════════════╗";
        gotoXY(25, 11);
        wcout << L"║";
        SetConsoleTextAttribute(hConsoleColor, 206);
        wcout << L"     Thông tin cá nhân   ";
        SetConsoleTextAttribute(hConsoleColor, 192);
        wcout << L"║";
        gotoXY(25, 12);
        wcout << L"╚═════════════════════════╝";
    }
    else
    {
        gotoXY(25, 10);
        SetConsoleTextAttribute(hConsoleColor, 224);
        wcout << L"╔═════════════════════════╗";
        gotoXY(25, 11);
        wcout << L"║";
        SetConsoleTextAttribute(hConsoleColor, 228);
        wcout << L"     Thông tin cá nhân   ";
        SetConsoleTextAttribute(hConsoleColor, 224);
        wcout << L"║";
        gotoXY(25, 12);
        wcout << L"╚═════════════════════════╝";
    }
    if ((x >= 25 && x <= 51) && (y >= 15 && y <= 17))
    {
        gotoXY(25, 15);
        SetConsoleTextAttribute(hConsoleColor, 192);
        wcout << L"╔═════════════════════════╗";
        gotoXY(25, 16);
        wcout << L"║";
        SetConsoleTextAttribute(hConsoleColor, 206);
        wcout << L"        Đăng xuất        ";
        SetConsoleTextAttribute(hConsoleColor, 192);
        wcout << L"║";
        gotoXY(25, 17);
        wcout << L"╚═════════════════════════╝";
    }
    else
    {
        gotoXY(25, 15);
        SetConsoleTextAttribute(hConsoleColor, 224);
        wcout << L"╔═════════════════════════╗";
        gotoXY(25, 16);
        wcout << L"║";
        SetConsoleTextAttribute(hConsoleColor, 228);
        wcout << L"        Đăng xuất        ";
        SetConsoleTextAttribute(hConsoleColor, 224);
        wcout << L"║";
        gotoXY(25, 17);
        wcout << L"╚═════════════════════════╝";
    }
    if ((x >= 55 && x <= 81) && (y >= 5 && y <= 7))
    {
        gotoXY(55, 5);
        SetConsoleTextAttribute(hConsoleColor, 192);
        wcout << L"╔═════════════════════════╗";
        gotoXY(55, 6);
        wcout << L"║";
        SetConsoleTextAttribute(hConsoleColor, 206);
        wcout << L" Hiển thị top khách hàng ";
        SetConsoleTextAttribute(hConsoleColor, 192);
        wcout << L"║";
        gotoXY(55, 7);
        wcout << L"╚═════════════════════════╝";
    }
    else
    {
        gotoXY(55, 5);
        SetConsoleTextAttribute(hConsoleColor, 224);
        wcout << L"╔═════════════════════════╗";
        gotoXY(55, 6);
        wcout << L"║";
        SetConsoleTextAttribute(hConsoleColor, 228);
        wcout << L" Hiển thị top khách hàng ";
        SetConsoleTextAttribute(hConsoleColor, 224);
        wcout << L"║";
        gotoXY(55, 7);
        wcout << L"╚═════════════════════════╝";
    }
    if ((x >= 55 && x <= 81) && (y >= 10 && y <= 12))
    {
        gotoXY(55, 10);
        SetConsoleTextAttribute(hConsoleColor, 192);
        wcout << L"╔═════════════════════════╗";
        gotoXY(55, 11);
        wcout << L"║";
        SetConsoleTextAttribute(hConsoleColor, 206);
        wcout << L"       Đổi mật khẩu      ";
        SetConsoleTextAttribute(hConsoleColor, 192);
        wcout << L"║";
        gotoXY(55, 12);
        wcout << L"╚═════════════════════════╝";
    }
    else
    {
        gotoXY(55, 10);
        SetConsoleTextAttribute(hConsoleColor, 224);
        wcout << L"╔═════════════════════════╗";
        gotoXY(55, 11);
        wcout << L"║";
        SetConsoleTextAttribute(hConsoleColor, 228);
        wcout << L"       Đổi mật khẩu      ";
        SetConsoleTextAttribute(hConsoleColor, 224);
        wcout << L"║";
        gotoXY(55, 12);
        wcout << L"╚═════════════════════════╝";
    }
    if ((x >= 55 && x <= 81) && (y >= 15 && y <= 17))
    {
        gotoXY(55, 15);
        SetConsoleTextAttribute(hConsoleColor, 192);
        wcout << L"╔═════════════════════════╗";
        gotoXY(55, 16);
        wcout << L"║";
        SetConsoleTextAttribute(hConsoleColor, 206);
        wcout << L"    Thoát chương trình   ";
        SetConsoleTextAttribute(hConsoleColor, 192);
        wcout << L"║";
        gotoXY(55, 17);
        wcout << L"╚═════════════════════════╝";
        SetConsoleTextAttribute(hConsoleColor, 7);
    }
    else
    {
        gotoXY(55, 15);
        SetConsoleTextAttribute(hConsoleColor, 224);
        wcout << L"╔═════════════════════════╗";
        gotoXY(55, 16);
        wcout << L"║";
        SetConsoleTextAttribute(hConsoleColor, 228);
        wcout << L"    Thoát chương trình   ";
        SetConsoleTextAttribute(hConsoleColor, 224);
        wcout << L"║";
        gotoXY(55, 17);
        wcout << L"╚═════════════════════════╝";
        SetConsoleTextAttribute(hConsoleColor, 7);
    }
}
void AppBanking::displayApp(HashTableThe& hashtb, HashTableBank hashtbank, HashTableAdmin hashtad)
{
    int check = 1;
    HANDLE hConsoleColor;
    hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
    // Vòng lặp để quét qua các event 
    while (check)
    {
        gotoXY(30, 0); wcout << L"╔════╦═══╦═══╗ ╔═══╦╦══╦═══╦═╔╗ ╔╦═══╦═══╦═╦═══╗";
        gotoXY(30, 1); wcout << L"║    ╠═══╬═══╣ ║   ║║  ║ ║ ║ ║╚═╝╠╣ ╠╣ ║ ║ ║   ║";
        gotoXY(30, 2); wcout << L"╠════╣   ║   ║ ╠═══╣╠══╣ ║ ║ ╠═══╬╣ ╠╣ ║ ║ ╠══ ║";
        gotoXY(30, 3); wcout << L"║ ╔╗ ║  ╔╣  ╔╝ ║   ║║╔╗║ ║ ║ ║╔═╗╠╣ ╠╣ ║ ║ ╠╦╦╦╣";
        gotoXY(30, 4); wcout << L"╚═╝╚═╩══╝╚══╝  ╚═══╩╩╚╩╩═╩═══╩╝ ╚╩═══╩═╩═══╩╩╩╩╝";
        paintApp();
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
                            if ((x >= 25 && x <= 51) && (y >= 5 && y <= 7))
                            {
                                system("cls");
                                chuyenKhoan(hashtb);
                            }
                            else if ((x >= 25 && x <= 51) && (y >= 10 && y <= 12))
                            {
                                
                                kiemTraThongTin(hashtb, hashtbank);
                                system("cls");
                            }
                            else if ((x >= 25 && x <= 51) && (y >= 15 && y <= 17))
                            {
                                system("cls");
                                check = 0;
                            }
                            else if ((x >= 55 && x <= 81) && (y >= 5 && y <= 7))
                            {
                                system("cls");
                                hienThiTopKhachHang(hashtb, hashtbank);
                            }
                            else if ((x >= 55 && x <= 81) && (y >= 10 && y <= 12))
                            {
                                system("cls");
                                doiMatKhau(hashtb);
                            }
                            else if ((x >= 55 && x <= 81) && (y >= 15 && y <= 17))
                            {
                                system("cls");
                                hashtb.ghiFile();
                                hashtbank.ghiFile();
                                hashtad.ghiFile();
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
                            paintApp();
                            break;
                        }
                        }
                    }

                } while (!Captured);
            }
        }
    }
    system("cls");
}
void AppBanking::paintAdmin()
{
    hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
    if ((x >= 25 && x <= 51) && (y >= 5 && y <= 7))
    {
        gotoXY(25, 5);
        SetConsoleTextAttribute(hConsoleColor, 192);
        wcout << L"╔═════════════════════════╗";
        gotoXY(25, 6);
        wcout << L"║";
        SetConsoleTextAttribute(hConsoleColor, 206);
        wcout << L"         Xóa user        ";
        SetConsoleTextAttribute(hConsoleColor, 192);
        wcout << L"║";
        gotoXY(25, 7);
        wcout << L"╚═════════════════════════╝";
    }
    else
    {
        gotoXY(25, 5);
        SetConsoleTextAttribute(hConsoleColor, 224);
        wcout << L"╔═════════════════════════╗";
        gotoXY(25, 6);
        wcout << L"║";
        SetConsoleTextAttribute(hConsoleColor, 228);
        wcout << L"         Xóa user        ";
        SetConsoleTextAttribute(hConsoleColor, 224);
        wcout << L"║";
        gotoXY(25, 7);
        wcout << L"╚═════════════════════════╝";
    }
    if ((x >= 25 && x <= 51) && (y >= 10 && y <= 12))
    {
        gotoXY(25, 10);
        SetConsoleTextAttribute(hConsoleColor, 192);
        wcout << L"╔═════════════════════════╗";
        gotoXY(25, 11);
        wcout << L"║";
        SetConsoleTextAttribute(hConsoleColor, 206);
        wcout << L"      Nạp tiền user      ";
        SetConsoleTextAttribute(hConsoleColor, 192);
        wcout << L"║";
        gotoXY(25, 12);
        wcout << L"╚═════════════════════════╝";
    }
    else
    {
        gotoXY(25, 10);
        SetConsoleTextAttribute(hConsoleColor, 224);
        wcout << L"╔═════════════════════════╗";
        gotoXY(25, 11);
        wcout << L"║";
        SetConsoleTextAttribute(hConsoleColor, 228);
        wcout << L"      Nạp tiền user      ";
        SetConsoleTextAttribute(hConsoleColor, 224);
        wcout << L"║";
        gotoXY(25, 12);
        wcout << L"╚═════════════════════════╝";
    }
    if ((x >= 25 && x <= 51) && (y >= 15 && y <= 17))
    {
        gotoXY(25, 15);
        SetConsoleTextAttribute(hConsoleColor, 192);
        wcout << L"╔═════════════════════════╗";
        gotoXY(25, 16);
        wcout << L"║";
        SetConsoleTextAttribute(hConsoleColor, 206);
        wcout << L"        Đăng xuất        ";
        SetConsoleTextAttribute(hConsoleColor, 192);
        wcout << L"║";
        gotoXY(25, 17);
        wcout << L"╚═════════════════════════╝";
    }
    else
    {
        gotoXY(25, 15);
        SetConsoleTextAttribute(hConsoleColor, 224);
        wcout << L"╔═════════════════════════╗";
        gotoXY(25, 16);
        wcout << L"║";
        SetConsoleTextAttribute(hConsoleColor, 228);
        wcout << L"        Đăng xuất        ";
        SetConsoleTextAttribute(hConsoleColor, 224);
        wcout << L"║";
        gotoXY(25, 17);
        wcout << L"╚═════════════════════════╝";
    }
    if ((x >= 55 && x <= 81) && (y >= 5 && y <= 7))
    {
        gotoXY(55, 5);
        SetConsoleTextAttribute(hConsoleColor, 192);
        wcout << L"╔═════════════════════════╗";
        gotoXY(55, 6);
        wcout << L"║";
        SetConsoleTextAttribute(hConsoleColor, 206);
        wcout << L"  Danh sách khách hàng   ";
        SetConsoleTextAttribute(hConsoleColor, 192);
        wcout << L"║";
        gotoXY(55, 7);
        wcout << L"╚═════════════════════════╝";
    }
    else
    {
        gotoXY(55, 5);
        SetConsoleTextAttribute(hConsoleColor, 224);
        wcout << L"╔═════════════════════════╗";
        gotoXY(55, 6);
        wcout << L"║";
        SetConsoleTextAttribute(hConsoleColor, 228);
        wcout << L"  Danh sách khách hàng   ";
        SetConsoleTextAttribute(hConsoleColor, 224);
        wcout << L"║";
        gotoXY(55, 7);
        wcout << L"╚═════════════════════════╝";
    }
    if ((x >= 55 && x <= 81) && (y >= 10 && y <= 12))
    {
        gotoXY(55, 10);
        SetConsoleTextAttribute(hConsoleColor, 192);
        wcout << L"╔═════════════════════════╗";
        gotoXY(55, 11);
        wcout << L"║";
        SetConsoleTextAttribute(hConsoleColor, 206);
        wcout << L"       Đổi mật khẩu      ";
        SetConsoleTextAttribute(hConsoleColor, 192);
        wcout << L"║";
        gotoXY(55, 12);
        wcout << L"╚═════════════════════════╝";
    }
    else
    {
        gotoXY(55, 10);
        SetConsoleTextAttribute(hConsoleColor, 224);
        wcout << L"╔═════════════════════════╗";
        gotoXY(55, 11);
        wcout << L"║";
        SetConsoleTextAttribute(hConsoleColor, 228);
        wcout << L"       Đổi mật khẩu      ";
        SetConsoleTextAttribute(hConsoleColor, 224);
        wcout << L"║";
        gotoXY(55, 12);
        wcout << L"╚═════════════════════════╝";
    }
    if ((x >= 55 && x <= 81) && (y >= 15 && y <= 17))
    {
        gotoXY(55, 15);
        SetConsoleTextAttribute(hConsoleColor, 192);
        wcout << L"╔═════════════════════════╗";
        gotoXY(55, 16);
        wcout << L"║";
        SetConsoleTextAttribute(hConsoleColor, 206);
        wcout << L"      Xóa ngân hàng      ";
        SetConsoleTextAttribute(hConsoleColor, 192);
        wcout << L"║";
        gotoXY(55, 17);
        wcout << L"╚═════════════════════════╝";
        SetConsoleTextAttribute(hConsoleColor, 7);
    }
    else
    {
        gotoXY(55, 15);
        SetConsoleTextAttribute(hConsoleColor, 224);
        wcout << L"╔═════════════════════════╗";
        gotoXY(55, 16);
        wcout << L"║";
        SetConsoleTextAttribute(hConsoleColor, 228);
        wcout << L"      Xóa ngân hàng      ";
        SetConsoleTextAttribute(hConsoleColor, 224);
        wcout << L"║";
        gotoXY(55, 17);
        wcout << L"╚═════════════════════════╝";
        SetConsoleTextAttribute(hConsoleColor, 7);
    }
}
void AppBanking::displayAdmin(HashTableAdmin& hashtad, HashTableThe& hashtuser, HashTableBank& hashtbank)
{
    int check = 1;
    HANDLE hConsoleColor;
    hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
    // Vòng lặp để quét qua các event 
    while (check)
    {
        gotoXY(30, 0); wcout << L"╔════╦═══╦═══╗ ╔═══╦╦══╦═══╦═╔╗ ╔╦═══╦═══╦═╦═══╗";
        gotoXY(30, 1); wcout << L"║    ╠═══╬═══╣ ║   ║║  ║ ║ ║ ║╚═╝╠╣ ╠╣ ║ ║ ║   ║";
        gotoXY(30, 2); wcout << L"╠════╣   ║   ║ ╠═══╣╠══╣ ║ ║ ╠═══╬╣ ╠╣ ║ ║ ╠══ ║";
        gotoXY(30, 3); wcout << L"║ ╔╗ ║  ╔╣  ╔╝ ║   ║║╔╗║ ║ ║ ║╔═╗╠╣ ╠╣ ║ ║ ╠╦╦╦╣";
        gotoXY(30, 4); wcout << L"╚═╝╚═╩══╝╚══╝  ╚═══╩╩╚╩╩═╩═══╩╝ ╚╩═══╩═╩═══╩╩╩╩╝";
        paintAdmin();
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
                            if ((x >= 25 && x <= 51) && (y >= 5 && y <= 7))
                            {
                                system("cls");
                                paintKhung();
                                gotoXY(30, 7);
                                wstring stk;
                                wcout << L"Nhập số tài khoản người dùng cần xóa:";
                                getline(wcin, stk);
                                hashtuser.remove(stk);
                            }
                            else if ((x >= 25 && x <= 51) && (y >= 10 && y <= 12))
                            {
                                system("cls");
                                paintKhung();
                                gotoXY(30, 7);
                                wstring stk;
                                wcout << L"Nhập số tài khoản người dùng cần thêm tiền: ";
                                getline(wcin, stk);
                                gotoXY(30, 8);
                                long long soTien;
                                wcout << L"Nhập số tiền cần nap: ";
                                wcin >> soTien;
                                hashtuser.napTienUser(stk, soTien);
                                gotoXY(30, 9);
                                wcout << L"Nạp tiền cho người dùng thành công!";
                                gotoXY(30, 10);
                                system("pause");
                                system("cls");
                            }
                            else if ((x >= 25 && x <= 51) && (y >= 15 && y <= 17))
                            {
                                system("cls");
                                check = 0;
                            }
                            else if ((x >= 55 && x <= 81) && (y >= 5 && y <= 7))
                            {
                                system("cls");
                                Admin ad;
                                ad.DanhSachThongTin();
                            }
                            else if ((x >= 55 && x <= 81) && (y >= 10 && y <= 12))
                            {
                                system("cls");
                                doiMatKhauAd(hashtad);
                            }
                            else if ((x >= 55 && x <= 81) && (y >= 15 && y <= 17))
                            {
                                system("cls");
                                paintKhung();
                                gotoXY(30, 7);
                                wstring mabank;
                                wcout << L"Nhập mã ngân hàng cần xóa:";
                                getline(wcin, mabank);
                                hashtbank.remove(mabank);
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
                            paintAdmin();
                            break;
                        }
                        }
                    }

                } while (!Captured);
            }
        }
    }
    system("cls");
}
void AppBanking::paintTongQuat()
{
    hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
    gotoXY(30, 0); wcout << L"╔════╦═══╦═══╗ ╔═══╦╦══╦═══╦═╔╗ ╔╦═══╦═══╦═╦═══╗";
    gotoXY(30, 1); wcout << L"║    ╠═══╬═══╣ ║   ║║  ║ ║ ║ ║╚═╝╠╣ ╠╣ ║ ║ ║   ║";
    gotoXY(30, 2); wcout << L"╠════╣   ║   ║ ╠═══╣╠══╣ ║ ║ ╠═══╬╣ ╠╣ ║ ║ ╠══ ║";
    gotoXY(30, 3); wcout << L"║ ╔╗ ║  ╔╣  ╔╝ ║   ║║╔╗║ ║ ║ ║╔═╗╠╣ ╠╣ ║ ║ ╠╦╦╦╣";
    gotoXY(30, 4); wcout << L"╚═╝╚═╩══╝╚══╝  ╚═══╩╩╚╩╩═╩═══╩╝ ╚╩═══╩═╩═══╩╩╩╩╝";
    if ((x >= 30 && x <= 50) && (y >= 5 && y <= 7))
    {
        gotoXY(30, 5);
        SetConsoleTextAttribute(hConsoleColor, 192);
        wcout << L"╔═══════════════════╗";
        gotoXY(30, 6);
        wcout << L"║";
        SetConsoleTextAttribute(hConsoleColor, 206);
        wcout << L"  Đăng nhập admin  ";
        SetConsoleTextAttribute(hConsoleColor, 192);
        wcout << L"║";
        gotoXY(30, 7);
        wcout << L"╚═══════════════════╝";
    }
    else
    {
        gotoXY(30, 5);
        SetConsoleTextAttribute(hConsoleColor, 224);
        wcout << L"╔═══════════════════╗";
        gotoXY(30, 6);
        wcout << L"║";
        SetConsoleTextAttribute(hConsoleColor, 228);
        wcout << L"  Đăng nhập admin  ";
        SetConsoleTextAttribute(hConsoleColor, 224);
        wcout << L"║";
        gotoXY(30, 7);
        wcout << L"╚═══════════════════╝";
    }
    if ((x >= 30 && x <= 50) && (y >= 9 && y <= 11))
    {
        gotoXY(30, 9);
        SetConsoleTextAttribute(hConsoleColor, 192);
        wcout << L"╔═══════════════════╗";
        gotoXY(30, 10);
        wcout << L"║";
        SetConsoleTextAttribute(hConsoleColor, 206);
        wcout << L"     Đăng nhập     ";
        SetConsoleTextAttribute(hConsoleColor, 192);
        wcout << L"║";
        gotoXY(30, 11);
        wcout << L"╚═══════════════════╝";
    }
    else
    {
        gotoXY(30, 9);
        SetConsoleTextAttribute(hConsoleColor, 224);
        wcout << L"╔═══════════════════╗";
        gotoXY(30, 10);
        wcout << L"║";
        SetConsoleTextAttribute(hConsoleColor, 228);
        wcout << L"     Đăng nhập     ";
        SetConsoleTextAttribute(hConsoleColor, 224);
        wcout << L"║";
        gotoXY(30, 11);
        wcout << L"╚═══════════════════╝";
    }
    if ((x >= 60 && x <= 81) && (y >= 9 && y <= 11))
    {
        gotoXY(60, 9);
        SetConsoleTextAttribute(hConsoleColor, 192);
        wcout << L"╔════════════════════╗";
        gotoXY(60, 10);
        wcout << L"║";
        SetConsoleTextAttribute(hConsoleColor, 206);
        wcout << L" Tạo tài khoản mới  ";
        SetConsoleTextAttribute(hConsoleColor, 192);
        wcout << L"║";
        gotoXY(60, 11);
        wcout << L"╚════════════════════╝";
    }
    else
    {
        gotoXY(60, 9);
        SetConsoleTextAttribute(hConsoleColor, 224);
        wcout << L"╔════════════════════╗";
        gotoXY(60, 10);
        wcout << L"║";
        SetConsoleTextAttribute(hConsoleColor, 228);
        wcout << L" Tạo tài khoản mới  ";
        SetConsoleTextAttribute(hConsoleColor, 224);
        wcout << L"║";
        gotoXY(60, 11);
        wcout << L"╚════════════════════╝";
    }
    if ((x >= 60 && x <= 81) && (y >= 5 && y <= 7))
    {
        gotoXY(60, 5);
        SetConsoleTextAttribute(hConsoleColor, 192);
        wcout << L"╔════════════════════╗";
        gotoXY(60, 6);
        wcout << L"║";
        SetConsoleTextAttribute(hConsoleColor, 206);
        wcout << L"       Thoát        ";
        SetConsoleTextAttribute(hConsoleColor, 192);
        wcout << L"║";
        gotoXY(60, 7);
        wcout << L"╚════════════════════╝";
        SetConsoleTextAttribute(hConsoleColor, 7);
    }
    else
    {
        gotoXY(60, 5);
        SetConsoleTextAttribute(hConsoleColor, 224);
        wcout << L"╔════════════════════╗";
        gotoXY(60, 6);
        wcout << L"║";
        SetConsoleTextAttribute(hConsoleColor, 228);
        wcout << L"       Thoát        ";
        SetConsoleTextAttribute(hConsoleColor, 224);
        wcout << L"║";
        gotoXY(60, 7);
        wcout << L"╚════════════════════╝";
        SetConsoleTextAttribute(hConsoleColor, 7);
    }
}
void AppBanking::displayTongQuat(HashTableThe& hashtb, int& access, HashTableBank& hashtbank, HashTableAdmin hashtad)
{
    ShowCur(false);
    int check = 1;
    // Vòng lặp để quét qua các event 
    HANDLE hConsoleColor;
    hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
    while (check)
    {
        gotoXY(30, 0); wcout << L"╔════╦═══╦═══╗ ╔═══╦╦══╦═══╦═╔╗ ╔╦═══╦═══╦═╦═══╗";
        gotoXY(30, 1); wcout << L"║    ╠═══╬═══╣ ║   ║║  ║ ║ ║ ║╚═╝╠╣ ╠╣ ║ ║ ║   ║";
        gotoXY(30, 2); wcout << L"╠════╣   ║   ║ ╠═══╣╠══╣ ║ ║ ╠═══╬╣ ╠╣ ║ ║ ╠══ ║";
        gotoXY(30, 3); wcout << L"║ ╔╗ ║  ╔╣  ╔╝ ║   ║║╔╗║ ║ ║ ║╔═╗╠╣ ╠╣ ║ ║ ╠╦╦╦╣";
        gotoXY(30, 4); wcout << L"╚═╝╚═╩══╝╚══╝  ╚═══╩╩╚╩╩═╩═══╩╝ ╚╩═══╩═╩═══╩╩╩╩╝";
        paintTongQuat();
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
                //int x, y;
            INPUT_RECORD Inrec;
            DWORD eventRead;
            HANDLE hStdIn;
            DWORD dwMode;
            hStdIn = GetStdHandle(STD_INPUT_HANDLE);
            dwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;

            //Kiểm tra xem console đã ở chế độ chấp nhận input từ chuột chưa
            if (SetConsoleMode(hStdIn, dwMode | ENABLE_MOUSE_INPUT) == TRUE)

                GetConsoleMode(hStdIn, &dwMode);
            SetConsoleMode(hStdIn, (dwMode & (ENABLE_MOUSE_INPUT)));

            if (GetAsyncKeyState(0x01))
            {
                bool Captured = false;
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
                            if ((x >= 30 && x <= 50) && (y >= 5 && y <= 7))
                            {
                                system("cls");
                                bool checkCount = true;
                                displayDangNhap(L"Admin.txt", checkCount, hashtad, hashtb);
                                if (checkCount)
                                {
                                    check = 0;
                                    access = 1;
                                }
                            }
                            else if ((x >= 30 && x <= 50) && (y >= 9 && y <= 11))
                            {
                                system("cls");
                                bool checkCount = true;
                                displayDangNhap(L"The.txt", checkCount, hashtad, hashtb);
                                if (checkCount)
                                {
                                    check = 0;
                                    access = 2;
                                }
                            }
                            else if ((x >= 60 && x <= 81) && (y >= 9 && y <= 11))
                            {
                                system("cls");
                                displayTaoTaiKhoan(hashtb, hashtbank);
                            }
                            else if ((x >= 60 && x <= 81) && (y >= 5 && y <= 7))
                            {
                                system("cls");
                                check = 0;
                            }
                            break;
                        }
                        }
                    }
                } while (!Captured);
            }
            else
            {
                bool Captured = false;
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
                            paintTongQuat();
                            break;
                        }
                        }
                    }
                } while (!Captured);
            }
        }
    }
}
void AppBanking::displayDangNhap(wstring nameFile, bool& checkCount, HashTableAdmin hashtad, HashTableThe hashtuser)
{
    ShowCur(false);
    HANDLE hConsoleColor;
    hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
    int count = 0;
    while (true)
    {
        if (count == 3)
        {
            paintKhung();
            gotoXY(35, 9);
            wcout << L"Bạn đã đăng nhập sai quá số lần cho phép!";
            gotoXY(35, 10);
            checkCount = false;
            system("pause");
            system("cls");
            break;
        }
        SetConsoleTextAttribute(hConsoleColor, 113);
        gotoXY(30, 0); wcout << L"╔════╦═══╦═══╗ ╔═══╦╦══╦═══╦═╔╗ ╔╦═══╦═══╦═╦═══╗";
        gotoXY(30, 1); wcout << L"║    ╠═══╬═══╣ ║   ║║  ║ ║ ║ ║╚═╝╠╣ ╠╣ ║ ║ ║   ║";
        gotoXY(30, 2); wcout << L"╠════╣   ║   ║ ╠═══╣╠══╣ ║ ║ ╠═══╬╣ ╠╣ ║ ║ ╠══ ║";
        gotoXY(30, 3); wcout << L"║ ╔╗ ║  ╔╣  ╔╝ ║   ║║╔╗║ ║ ║ ║╔═╗╠╣ ╠╣ ║ ║ ╠╦╦╦╣";
        gotoXY(30, 4); wcout << L"╚═╝╚═╩══╝╚══╝  ╚═══╩╩╚╩╩═╩═══╩╝ ╚╩═══╩═╩═══╩╩╩╩╝";
        SetConsoleTextAttribute(hConsoleColor, 7);
        paintKhung();
        gotoXY(35, 9);
        SetColor(10);
        wcout << L"Tài khoản: ";
        SetColor(7);
        gotoXY(35, 11);
        wcout << L"φ";
        gotoXY(35, 10);
        SetColor(9);
        wcout << L"Mật khẩu: ";
        SetColor(7);
        gotoXY(25, 12);
        wcout << L"(Nhấn tổ hợp phím Ctrl + E để hiện mật khẩu và ngược lại!)";
        gotoXY(45, 9);
        wstring account;
        getline(wcin, account);
        if (nameFile == L"The.txt")
            this->the.setSoTaiKhoan(account);
        if (nameFile == L"Admin.txt")
            this->ad.setMaAdmin(account);
        gotoXY(45, 10);
        wstring password;
        bool checkHiddenPassword = false;
        wchar_t ch;
        const wchar_t ENTER = 13;
        const wchar_t BACKSPACE = 8;
        const wchar_t CTRL_E = 5;
        while ((ch = _getch()) != ENTER)
        {
            if (ch == CTRL_E)
            {
                if (checkHiddenPassword)
                {
                    checkHiddenPassword = false;
                    gotoXY(35, 11);
                    wcout << L"φ";
                    gotoXY(45, 10);
                    for (int i = 1; i <= password.length(); i++)
                        wcout << L"●";
                }
                else
                {
                    checkHiddenPassword = true;
                    gotoXY(35, 11);
                    SetColor(9);
                    wcout << L"φ";
                    SetColor(7);
                    gotoXY(45, 10);
                    wcout << password;
                }
            }
            else if (ch == BACKSPACE && password.size() > 0)
            {
                password[password.size() - 1] = '\0';
                password.resize(password.size() - 1);
                gotoXY(whereX() - 1, whereY());
                wcout << L" ";
                gotoXY(whereX() - 1, whereY());
            }
            else if (ch != BACKSPACE)
            {
                if (!checkHiddenPassword)
                {
                    password += ch;
                    wcout << L'●';
                }
                else
                {
                    password += ch;
                    wcout << ch;
                }
            }
        }
        if (nameFile == L"The.txt")
        {
            this->the.setMatKhau(password);
            if (hashtuser.checkAccount(this->the.getSoTaiKhoan(), this->the.getMatKhau()))
            {
                the.setSoTaiKhoan(account);
                the.setMatKhau(password);
                break;
            }
        }
        if (nameFile == L"Admin.txt")
        {
            this->ad.setMatKhauAdmin(password);
            if (hashtad.checkAccount(this->ad.getMaAdmin(), this->ad.getMatKhauAdmin()))
            {
                ad.setMaAdmin(account);
                ad.setMatKhauAdmin(password);
                break;
            }
        }
        gotoXY(35, 13);
        wcout << L"Tài khoản hoặc mật khẩu sai!!!";
        count++;
        _getch();
        system("cls");
    }
}
void AppBanking::displayTaoTaiKhoan(HashTableThe& hashtb, HashTableBank& hashtbank)
{
    wstring stk;
    bool check1 = true, check2 = true;
    do
    {
        check1 = check2 = true;
        paintKhung();
        gotoXY(30, 7);
        wcout << L"Nhập số tài khoản: ";
        getline(wcin, stk);
        if (stk.length() == 0)
        {
            check1 = check2 = false;
            gotoXY(30, 8);
            wcout << L"Số tài khoản không hợp lệ!";
            gotoXY(30, 9);
            system("pause");
            system("cls");
        }
        if (hashtb.checkSTK(stk))
        {
            check1 = check2 = false;
            gotoXY(30, 8);
            wcout << L"Số tài khoản đã tồn tại!";
            gotoXY(30, 9);
            system("pause");
            system("cls");
        }
        if (check2)
        {
            for (int i = 0; i < stk.length(); i++)
            {
                if (stk[i] == L' ')
                {
                    check1 = false;
                    gotoXY(30, 8);
                    wcout << L"Tài khoản không hợp lệ!";
                    gotoXY(30, 9);
                    system("pause");
                    system("cls");
                    break;
                }
            }
        }
    } while (!check1);
    wstring mk;
    do
    {
        check1 = check2 = true;
        paintKhung();
        gotoXY(30, 7);
        wcout << L"Nhập số tài khoản: " << stk;
        gotoXY(30, 8);
        wcout << L"Nhập mật khẩu: ";
        getline(wcin, mk);
        if (mk.length() == 0)
        {
            check1 = check2 = false;
            gotoXY(30, 9);
            wcout << L"Mật khẩu không hợp lệ!";
            gotoXY(30, 10);
            system("pause");
            system("cls");
        }
        if (check2)
        {
            for (int i = 0; i < mk.length(); i++)
            {
                if (mk[i] == L' ')
                {
                    check1 = false;
                    gotoXY(30, 9);
                    wcout << L"Mật khẩu không hợp lệ!";
                    gotoXY(30, 10);
                    system("pause");
                    system("cls");
                    break;
                }
            }
        }
    } while (!check1);
    wstring mp;
    do
    {
        check1 = check2 = true;
        paintKhung();
        gotoXY(30, 7);
        wcout << L"Nhập số tài khoản: " << stk;
        gotoXY(30, 8);
        wcout << L"Nhập mật khẩu: " << mk;
        gotoXY(30, 9);
        wcout << L"Nhập mã pin: ";
        getline(wcin, mp);
        if (mp.length() == 0)
        {
            check1 = check2 = false;
            gotoXY(30, 10);
            wcout << L"Mã pin không hợp lệ!";
            gotoXY(30, 11);
            system("pause");
            system("cls");
        }
        if (check2)
        {
            for (int i = 0; i < mp.length(); i++)
            {
                if (mp[i] == L' ')
                {
                    check1 = false;
                    gotoXY(30, 10);
                    wcout << L"Mã pin không hợp lệ!";
                    gotoXY(30, 11);
                    system("pause");
                    system("cls");
                    break;
                }
            }
        }
    } while (!check1);
    wstring hvt;
    do
    {
        check1 = check2 = true;
        paintKhung();
        gotoXY(30, 7);
        wcout << L"Nhập số tài khoản: " << stk;
        gotoXY(30, 8);
        wcout << L"Nhập mật khẩu: " << mk;
        gotoXY(30, 9);
        wcout << L"Nhập mã pin: " << mp;
        gotoXY(30, 10);
        wcout << L"Nhập họ và tên: ";
        getline(wcin, hvt);
        if (hvt.length() == 0)
        {
            check1 = false;
            gotoXY(30, 11);
            wcout << L"Họ và tên không hợp lệ!";
            gotoXY(30, 12);
            system("pause");
            system("cls");
        }
    } while (!check1);
    wstring gt;
    do
    {
        check1 = true;
        paintKhung();
        gotoXY(30, 7);
        wcout << L"Nhập số tài khoản: " << stk;
        gotoXY(30, 8);
        wcout << L"Nhập mật khẩu: " << mk;
        gotoXY(30, 9);
        wcout << L"Nhập mã pin: " << mp;
        gotoXY(30, 10);
        wcout << L"Nhập họ và tên: " << hvt;
        gotoXY(30, 11);
        wcout << L"Nhập giới tính: ";
        getline(wcin, gt);
        if (gt.length() == 0)
        {
            check1 = false;
            gotoXY(30, 12);
            wcout << L"Giới tính không hợp lệ!";
            gotoXY(30, 13);
            system("pause");
            system("cls");
        }
    } while (!check1);
    wstring ns;
    int day, month, year;
    do
    {
        check1 = true, check2 = false;
        paintKhung();
        gotoXY(30, 12);
        wcout << L"Nhập ngày tháng năm sinh: ";
        wcin >> day >> month >> year;
        if (!kiemTraNgayHopLe(day, month, year))
        {
            check1 = false;
            gotoXY(30, 13);
            wcout << L"Ngày sinh không hợp lệ!";
            gotoXY(30, 14);
            system("pause");
            gotoXY(55, 12);
            wcout << L"                              ";
            gotoXY(30, 13);
            wcout << L"                       ";
            gotoXY(30, 14);
            wcout << L"                               ";
        }
    } while (!check1);
    wcin.ignore(256, '\n');
    ns = ns + to_wstring(day) + L"/" + to_wstring(month) + L"/" + to_wstring(year);
    wstring dc;
    do
    {
        check1 = true;
        paintKhung();
        gotoXY(30, 7);
        wcout << L"Nhập số tài khoản: " << stk;
        gotoXY(30, 8);
        wcout << L"Nhập mật khẩu: " << mk;
        gotoXY(30, 9);
        wcout << L"Nhập mã pin: " << mp;
        gotoXY(30, 10);
        wcout << L"Nhập họ và tên: " << hvt;
        gotoXY(30, 11);
        wcout << L"Nhập giới tính: " << gt;
        gotoXY(30, 12);
        wcout << L"Nhập ngày tháng năm sinh: " << day << L" " << month << L" " << year;
        gotoXY(30, 13);
        wcout << L"Nhập địa chỉ: ";
        getline(wcin, dc);
        if (dc.length() == 0)
        {
            check1 = false;
            gotoXY(30, 14);
            wcout << L"Địa chỉ không hợp lệ!";
            gotoXY(30, 15);
            system("pause");
            system("cls");
        }
    } while (!check1);
    long long sd = 0;
    long long sdtk = 0; // số dư tiết kiệm
    wstring mb;
    do
    {
        check1 = true;
        paintKhung();
        gotoXY(30, 7);
        wcout << L"Nhập số tài khoản: " << stk;
        gotoXY(30, 8);
        wcout << L"Nhập mật khẩu: " << mk;
        gotoXY(30, 9);
        wcout << L"Nhập mã pin: " << mp;
        gotoXY(30, 10);
        wcout << L"Nhập họ và tên: " << hvt;
        gotoXY(30, 11);
        wcout << L"Nhập giới tính: " << gt;
        gotoXY(30, 12);
        wcout << L"Nhập ngày tháng năm sinh: " << day << L" " << month << L" " << year;
        gotoXY(30, 13);
        wcout << L"Nhập địa chỉ: " << dc;
        gotoXY(30, 14);
        wcout << L"Nhập mã ngân hàng: ";
        getline(wcin, mb);
        if (mb.length() == 0)
        {
            check1 = false;
            gotoXY(30, 15);
            wcout << L"Địa chỉ không hợp lệ!";
            gotoXY(30, 16);
            system("pause");
            system("cls");
        }
    } while (!check1);
    The the(stk, mk, mp, hvt, gt, ns, dc, sd, sdtk, mb);
    Node<The>* k = new Node<The>(the);
    if (hashtb.add(k->data.getSoTaiKhoan(), k))
    {
        hashtbank.updateSoLuongUser(mb);
        gotoXY(30, 15);
        wcout << L"Tạo tài khoản thành công!";
    }
    wcin.ignore();
    system("cls");

}