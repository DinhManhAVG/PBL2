 #include "AppBanking.h"
void AppBanking::chuyenKhoan(HashTableThe hashtb)
{
    wchar_t ch;
    const wchar_t ENTER = 13;
    const wchar_t BACKSPACE = 8;
    const wchar_t CTRL_E = 5;
    SetColor(11);
    wstring soTaiKhoanNguoiNhan;
    bool check1 = true;
    do
    {
        paintKhung();
        gotoXY(30, 7);
        wcout << L"Nhập số tài khoản cần chuyển: ";
        while ((ch = _getch()) != ENTER)
        {
            if (ch == BACKSPACE && soTaiKhoanNguoiNhan.size() > 0)
            {
                soTaiKhoanNguoiNhan[soTaiKhoanNguoiNhan.size() - 1] = '\0';
                soTaiKhoanNguoiNhan.resize(soTaiKhoanNguoiNhan.size() - 1);
                gotoXY(whereX() - 1, whereY());
                wcout << L" ";
                gotoXY(whereX() - 1, whereY());
            }
            else if (ch != BACKSPACE)
            {
                if (soTaiKhoanNguoiNhan.length() < 9)
                {
                    soTaiKhoanNguoiNhan += ch;
                    wcout << ch;
                }
            }
        }
        if (soTaiKhoanNguoiNhan.length() == 0)
        {
            check1 = false;
            gotoXY(30, 8);
            wcout << L"Số tài khoản không hợp lệ!";
            gotoXY(30, 9);
            system("pause");
            system("cls");
        }
    } while (!check1);
    int soTien;
    gotoXY(30, 8);
    wcout << L"Nhập số tiền cần chuyển: "; wcin >> soTien;
    hashtb.timKiemNguoiNhan(the.getSoTaiKhoan(), soTaiKhoanNguoiNhan, soTien);
    gotoXY(30, 17);
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
    if (matKhauHienTai == the.getMatKhau())
    {
        gotoXY(30, 8);
        wcout << L"Nhập mật khẩu mới: ";
        wcin >> matKhauMoi;
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
    gotoXY(30, 10);
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
    if (matKhauHienTai == ad.getMatKhauAdmin())
    {
        gotoXY(30, 8);
        wcout << L"Nhập mật khẩu mới: ";
        wcin >> matKhauMoi;
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
    gotoXY(30, 10);
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
void AppBanking::paintKhungDangKi(HashTableBank hashtbank)
{
    SetColor(12);
    gotoXY(20, 4);
    wcout << L"Để thoát, đừng nhập gì và nhấn CTRL + Q sau đó nhấn phím enter ở mỗi mục nhập thông tin!";
    SetColor(7);
    SetColor(8);
    gotoXY(20, 5);
    wcout << L"Nhập số tài khoản đủ 9 kí tự và 3 đầu số theo yêu cầu như danh sách bên.";
    SetColor(7);
    SetColor(9);
    gotoXY(45, 0);
    for (int i = 0; i < hashtbank.sizeArrMB; i++)
    {
        gotoXY(95, i + 5);
        wcout << hashtbank.arrayMaBank[i];
        gotoXY(100, i + 5);
        wcout << hashtbank.getTenBank(hashtbank.arrayMaBank[i]);
    }
    SetColor(7);
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
    wchar_t ch;
    const wchar_t ENTER = 13;
    const wchar_t BACKSPACE = 8;
    const wchar_t CTRL_E = 5;
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
                                wstring stk;
                                bool check1 = true;
                                paintKhung();
                                gotoXY(30, 7);
                                wcout << L"Nhập số tài khoản người dùng cần xóa:";
                                while ((ch = _getch()) != ENTER)
                                {
                                    if (ch == BACKSPACE && stk.size() > 0)
                                    {
                                        stk[stk.size() - 1] = '\0';
                                        stk.resize(stk.size() - 1);
                                        gotoXY(whereX() - 1, whereY());
                                        wcout << L" ";
                                        gotoXY(whereX() - 1, whereY());
                                    }
                                    else if (ch != BACKSPACE)
                                    {
                                        if (stk.length() < 9)
                                        {
                                            stk += ch;
                                            wcout << ch;
                                        }
                                    }
                                }
                                if (stk.length() == 0)
                                {
                                    check1 = false;
                                    gotoXY(30, 8);
                                    wcout << L"Số tài khoản không hợp lệ!";
                                    gotoXY(30, 9);
                                    system("pause");
                                    system("cls");
                                }
                                else if (!hashtuser.checkSTK(stk))
                                {
                                    check1 = false;
                                    stk = L"";
                                    gotoXY(30, 8);
                                    wcout << L"Số tài khoản không tồn tại!";
                                    gotoXY(30, 9);
                                    system("pause");
                                    system("cls");
                                }
                                if (check1)
                                    hashtuser.remove(stk);
                            }
                            else if ((x >= 25 && x <= 51) && (y >= 10 && y <= 12))
                            {
                                system("cls");
                                paintKhung();
                                wstring stk;
                                bool check1 = true;
                                gotoXY(30, 7);
                                wcout << L"Nhập số tài khoản người dùng cần thêm tiền: ";
                                while ((ch = _getch()) != ENTER)
                                {
                                    if (ch == BACKSPACE && stk.size() > 0)
                                    {
                                        stk[stk.size() - 1] = '\0';
                                        stk.resize(stk.size() - 1);
                                        gotoXY(whereX() - 1, whereY());
                                        wcout << L" ";
                                        gotoXY(whereX() - 1, whereY());
                                    }
                                    else if (ch != BACKSPACE)
                                    {
                                        if (stk.length() < 9)
                                        {
                                            stk += ch;
                                            wcout << ch;
                                        }
                                    }
                                }
                                if (stk.length() == 0)
                                {
                                    check1 = false;
                                    gotoXY(30, 8);
                                    wcout << L"Số tài khoản không hợp lệ!";
                                    gotoXY(30, 9);
                                    system("pause");
                                    system("cls");
                                }
                                else if (!hashtuser.checkSTK(stk))
                                {
                                    check1 = false;
                                    stk = L"";
                                    gotoXY(30, 8);
                                    wcout << L"Số tài khoản không tồn tại!";
                                    gotoXY(30, 9);
                                    system("pause");
                                    system("cls");
                                }
                                if (check1)
                                {
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
                                ad.DanhSachThongTin(hashtuser);
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
        if (count == 1)
        {
            paintKhung();
            gotoXY(35, 9);
            wcout << L"Tài khoản hoặc mật khẩu sai!!!";
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
        gotoXY(45, 9);
        bool checkHiddenPassword = false;
        wchar_t ch;
        const wchar_t ENTER = 13;
        const wchar_t BACKSPACE = 8;
        const wchar_t CTRL_E = 5;
        while ((ch = _getch()) != ENTER)
        {
            if (ch == BACKSPACE && account.size() > 0)
            {
                account[account.size() - 1] = '\0';
                account.resize(account.size() - 1);
                gotoXY(whereX() - 1, whereY());
                wcout << L" ";
                gotoXY(whereX() - 1, whereY());
            }
            else if (ch != BACKSPACE)
            {
                if (account.length() < 9)
                {
                    account += ch;
                    wcout << ch;
                }
            }
        }
        if (nameFile == L"The.txt")
            this->the.setSoTaiKhoan(account);
        if (nameFile == L"Admin.txt")
            this->ad.setMaAdmin(account);
        gotoXY(45, 10);
        wstring password;
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
        count++;
        system("cls");
    }
}
void AppBanking::displayTaoTaiKhoan(HashTableThe& hashtb, HashTableBank& hashtbank)
{
    bool checkOut = true;
    wstring stk, substk;
    bool check1 = true, check2 = true, check3 = true;
    wchar_t ch;
    const wchar_t ENTER = 13;
    const wchar_t BACKSPACE = 8;
    const wchar_t CTRL_Q = 17;
    do
    {
        paintKhungDangKi(hashtbank);
        check1 = check2 = check3 = true;
        gotoXY(30, 7);
        wcout << L"Nhập số tài khoản: ";
        while ((ch = _getch()) != ENTER)
        {
            if (ch == BACKSPACE && stk.size() > 0)
            {
                stk[stk.size() - 1] = L'\0';
                stk.resize(stk.size() - 1);
                gotoXY(whereX() - 1, whereY());
                wcout << L" ";
                gotoXY(whereX() - 1, whereY());
            }
            else if (ch != BACKSPACE) 
            {
                if (stk.length() < 9)
                {
                    stk += ch;
                    if (stk.length() < 4)
                        substk += ch;
                    wcout << ch;
                }
            }
        }
        if (stk.length() == 1 && stk[0] == CTRL_Q)
        {
            checkOut = false;
            break;
        }
        if (stk.length() < 9)
        {
            stk = L"";
            substk = L"";
            check1 = check2 = false;
            gotoXY(30, 8);
            wcout << L"Số tài khoản bị trống hoặc không đủ 9 số theo yêu cầu!";
            gotoXY(30, 9);
            system("pause");
            system("cls");
        }
        else if(stk.length() == 9)
        {
            if (hashtb.checkSTK(stk))
            {
                stk = L"";
                substk = L"";
                check1 = check2 = false;
                gotoXY(30, 8);
                wcout << L"Số tài khoản đã tồn tại!";
                gotoXY(30, 9);
                system("pause");
                system("cls");
            }
            else
            {
                for (int i = 0; i < hashtbank.sizeArrMB; i++)
                {
                    if (substk == hashtbank.arrayMaBank[i])
                        break;
                    if (i == hashtbank.sizeArrMB - 1)
                        check3 = false;
                }
                if (!check3)
                {
                    stk = L"";
                    substk = L"";
                    check1 = check2 = false;
                    gotoXY(30, 8);
                    wcout << L"3 đầu số tài khoản không có trong danh sách mã ngân hàng!";
                    gotoXY(30, 9);
                    system("pause");
                    system("cls");
                }
            }
        }
        if (check2)
        {
            for (int i = 0; i < stk.length(); i++)
            {
                if (stk[i] == L' ')
                {
                    stk = L"";
                    substk = L"";
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
    if (checkOut)
    {
        do
        {
            check1 = check2 = true;
            paintKhungDangKi(hashtbank);
            gotoXY(30, 7);
            wcout << L"Nhập số tài khoản: " << stk;
            gotoXY(30, 8);
            wcout << L"Nhập mật khẩu: ";
            getline(wcin, mk);
            if (mk.length() == 1 && mk[0] == CTRL_Q)
            {
                checkOut = false;
                break;
            }
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
    }
    wstring mp;
    if (checkOut)
    {
        do
        {
            check1 = check2 = true;
            paintKhungDangKi(hashtbank);
            gotoXY(30, 7);
            wcout << L"Nhập số tài khoản: " << stk;
            gotoXY(30, 8);
            wcout << L"Nhập mật khẩu: " << mk;
            gotoXY(30, 9);
            wcout << L"Nhập mã pin: ";
            getline(wcin, mp);
            if (mp.length() == 1 && mp[0] == CTRL_Q)
            {
                checkOut = false;
                break;
            }
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
    }
    wstring hvt;
    if (checkOut)
    {
        do
        {
            check1 = check2 = true;
            paintKhungDangKi(hashtbank);
            gotoXY(30, 7);
            wcout << L"Nhập số tài khoản: " << stk;
            gotoXY(30, 8);
            wcout << L"Nhập mật khẩu: " << mk;
            gotoXY(30, 9);
            wcout << L"Nhập mã pin: " << mp;
            gotoXY(30, 10);
            wcout << L"Nhập họ và tên: ";
            getline(wcin, hvt);
            if (hvt.length() == 1 && hvt[0] == CTRL_Q)
            {
                checkOut = false;
                break;
            }
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
    }
    wstring gt;
    if (checkOut)
    {
        do
        {
            check1 = true;
            paintKhungDangKi(hashtbank);
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
            if (gt.length() == 1 && gt[0] == CTRL_Q)
            {
                checkOut = false;
                break;
            }
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
    }
    wstring ns;
    int day, month, year;
    bool check_svalid = true;
    int count_ignored = 0;
    if (checkOut)
    {
        do
        {
            check1 = true;
            wstring sday;
            paintKhungDangKi(hashtbank);
            do
            {
                check_svalid = true;
                gotoXY(30, 12);
                wcout << L"Nhập ngày tháng năm sinh: ";
                if (count_ignored != 0)
                    wcin.ignore();
                getline(wcin, sday);
                if (sday.length() == 1 && sday[0] == CTRL_Q)
                {
                    checkOut = false;
                    break;
                }
                for (int i = 0; i < sday.length(); i++)
                {
                    if (sday[i] < L'0' || sday[i] > L'9')
                    {
                            check_svalid = false;
                        break;
                    }
                }
                if(check_svalid)
                    day = stoi(sday);
                if (!check_svalid)
                {
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
            } while (!check_svalid);
            if (checkOut)
            {
                wcin >> month >> year;
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
                    gotoXY(0, 13);
                    wcout << L"                       ";
                    gotoXY(0, 14);
                    wcout << L"                       ";
                    count_ignored = 1;
                }
            }
        } while (!check1);
    }
    if (checkOut)
    {
        wcin.ignore(256, '\n');
        ns = ns + to_wstring(day) + L"/" + to_wstring(month) + L"/" + to_wstring(year);
        gotoXY(0, 13);
        wcout << L"                       ";
        gotoXY(0, 14);
        wcout << L"                       ";
    }
    wstring dc;
    if (checkOut)
    {
        do
        {
            check1 = true;
            paintKhungDangKi(hashtbank);
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
            if (dc.length() == 1 && dc[0] == CTRL_Q)
            {
                checkOut = false;
                break;
            }
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
    }
    if (checkOut)
    {
        long long sd = 0;
        long long sdtk = 0; // số dư tiết kiệm
        The the(stk, mk, mp, hvt, gt, ns, dc, sd, sdtk, substk);
        Node<The>* k = new Node<The>(the);
        if (hashtb.add(k->data.getSoTaiKhoan(), k))
        {
            hashtbank.updateSoLuongUser(substk);
            gotoXY(30, 15);
            wcout << L"Tạo tài khoản thành công!";
        }
        wcin.ignore();
    }
    system("cls");

}