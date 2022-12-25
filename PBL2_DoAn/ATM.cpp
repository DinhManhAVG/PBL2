#include"ATM.h"
Bank bank;
const long long soTienHienCoPre = bank.getSoTienCungCapATM();
long long ATM::soTienHienCo = soTienHienCoPre;
enum MOVE { LEFT = 75, RIGHT = 77, DOWN = 80, UP = 72, ENTER = 13 };
enum LUACHON { CHUCNANG1 = 1, CHUCNANG2 = 2, CHUCNANG3 = 3, CHUCNANG4 = 4, CHUCNANG5 = 5, CHUCNANG6 = 6 };

// SANG TRAI 75
// SANG PHAI 77
// XUONG 80
// LEN 72
// ENTER 13


void ATM::kiemTraThongTin(HashTableThe ht, HashTableBank htbank, wstring getSoTaiKhoan)
{
    ht.timKiemNguoiDung(getSoTaiKhoan, htbank);
    char c = _getch();
    system("cls");
    hienThiGiaoDien();
}
//void ATM::setHoVaTen(wstring hoVaTen)
//{
//    this->hoVaTen = hoVaTen;
//}
//string ATM::getHoVaTen()
//{
//    return hoVaTen;
//}
//void ATM::setgioiTinh(wstring gioiTinh)
//{
//    return gioiTinh;
//}
//string ATM::getGioiTinh()
//{
//    return gioiTinh;
//}
//void ATM::setngaySinh(wstring ngaySinh)
//{
//    this->ngaySinh = ngaySinh;
//}
//string ATM::getNgaySinh()
//{
//    return ngaySinh;
//}
void ATM::hienThiGiaoDien()
{
    system("cls");
    gotoXY(33, 5);
    SetColor(10);
    gotoXY(33, 6); wcout << "          **         ********     ***     ***" << endl;
    gotoXY(33, 7); wcout << "         ****          ***        *** *** ***" << endl;
    gotoXY(33, 8); wcout << "        ******         ***        *** *** ***" << endl;
    gotoXY(33, 9); wcout << "       **    **        ***        ***     ***" << endl;
    gotoXY(33, 10); wcout << "      **      **       ***        ***     ***" << endl;
    SetColor(7);
}
void ATM::rutTien(HashTableThe& ht, wstring getSoTaiKhoan)
{
    wchar_t ch;
    const wchar_t ENTER = 13;
    const wchar_t BACKSPACE = 8;
    hienThiGiaoDien();
    SetColor(11);
    gotoXY(30, 14);
    wstring str;
    wcout << L"Nhập số tiền muốn rút: ";
    while ((ch = _getch()) != ENTER)
    {
        if (ch == BACKSPACE && str.size() > 0)
        {
            str[str.size() - 1] = '\0';
            str.resize(str.size() - 1);
            gotoXY(whereX() - 1, whereY());
            wcout << L" ";
            gotoXY(whereX() - 1, whereY());
        }
        else if (ch != BACKSPACE)
        {
            if (str.length() <= 9)
            {
                str += ch;
                wcout << ch;
            }
        }
    }
    if (str.length() == 0)
    {
        gotoXY(30, 16);
        wcout << L"Bạn chưa nhập gì!" << endl;
        gotoXY(30, 17);
        system("pause");
        system("cls");
        hienThiGiaoDien();
        return;
    }
    long long soTien;
    bool checkstr = true;
    for (int i = 0; i < str.length(); ++i) {
        if (!isdigit(str[i])) {
            soTien = -1;
            checkstr = false;
        }
    }
    if (checkstr)
    {
        soTien = stoll(str);
    }
    else
    {
        soTien = -1;
    }
    if (soTien < 0) 
    {
        gotoXY(30, 16);
        wcout << L"Số tiền nhập không thỏa mãn!" << endl;
        gotoXY(30, 17);
        system("pause");
        system("cls");
        hienThiGiaoDien();
        return;
    }
    else if (soTienHienCo < soTien) {
        gotoXY(30, 16);
        wcout << L"Không đủ tiền trong ATM !" << endl;
        if (soTienHienCo < 1000000) {
            soTienHienCo += bank.getSoTienCungCapATM();
        }
        gotoXY(30, 17);
        system("pause");
        system("cls");
        hienThiGiaoDien();
        return;
    }
    ht.timKiemSoDu(getSoTaiKhoan, soTien);
    gotoXY(30, 18);
    system("pause");
    system("cls");
    hienThiGiaoDien();
    SetColor(7);
}
void ATM::rutTienTietKiem(HashTableThe& ht, wstring getSoTaiKhoan)
{
    wchar_t ch;
    const wchar_t ENTER = 13;
    const wchar_t BACKSPACE = 8;
    const wchar_t CTRL_E = 5;
    hienThiGiaoDien();
    SetColor(11);
    gotoXY(30, 14);
    wstring str;
    wcout << L"Nhập số tiền muốn rút: ";
    while ((ch = _getch()) != ENTER)
    {
        if (ch == BACKSPACE && str.size() > 0)
        {
            str[str.size() - 1] = '\0';
            str.resize(str.size() - 1);
            gotoXY(whereX() - 1, whereY());
            wcout << L" ";
            gotoXY(whereX() - 1, whereY());
        }
        else if (ch != BACKSPACE)
        {
            if (str.length() <= 9)
            {
                str += ch;
                wcout << ch;
            }
        }
    }
    if (str.length() == 0)
    {
        gotoXY(30, 16);
        wcout << L"Bạn chưa nhập gì!" << endl;
        gotoXY(30, 17);
        system("pause");
        system("cls");
        hienThiGiaoDien();
        return;
    }
    long long soTien;
    bool checkstr = true;
    for (int i = 0; i < str.length(); ++i) {
        if (!isdigit(str[i])) {
            soTien = -1;
            checkstr = false;
        }
    }
    if (checkstr)
    {
        soTien = stoll(str);
    }
    else
    {
        soTien = -1;
    }
    if (soTien < 0) 
    {
        gotoXY(30, 16);
        wcout << L"Số tiền nhập không thỏa mãn!" << endl;
        gotoXY(30, 17);
        system("pause");
        system("cls");
        hienThiGiaoDien();
        return;
    }
    else if (soTienHienCo < soTien) {
        gotoXY(30, 16);
        wcout << L"Không đủ tiền trong ATM !" << endl;
        if (soTienHienCo < 1000000) {
            soTienHienCo += bank.getSoTienCungCapATM();
        }
        gotoXY(30, 17);
        system("pause");
        system("cls");
        hienThiGiaoDien();
        return;
    }
    
    ht.timKiemSoDuTietKiem(getSoTaiKhoan, soTien);
    gotoXY(30, 17);
    system("pause");
    system("cls");
    hienThiGiaoDien();
    SetColor(7);
}
void ATM::chuyenTien(HashTableThe& ht, wstring soTaiKhoanNguoiChuyen)
{
    wchar_t ch;
    const wchar_t ENTER = 13;
    const wchar_t BACKSPACE = 8;
    const wchar_t CTRL_E = 5;
    hienThiGiaoDien();
    SetColor(11);
    gotoXY(30, 14); wcin.ignore(0);
    wstring soTaiKhoanNguoiNhan;
    hienThiGiaoDien();
    gotoXY(30, 14);
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
        gotoXY(30, 15);
        wcout << L"Số tài khoản không hợp lệ!";
        gotoXY(30, 16);
        system("pause");
        system("cls");
        hienThiGiaoDien();
        return;
    }
    else if (soTaiKhoanNguoiChuyen == soTaiKhoanNguoiNhan)
    {
        gotoXY(30, 15);
        wcout << L"Số tài khoản trùng với chính mình!";
        gotoXY(30, 16);
        system("pause");
        system("cls");
        hienThiGiaoDien();
        return;
    }
    else if (!ht.checkSTK(soTaiKhoanNguoiNhan))
    {
        gotoXY(30, 15);
        wcout << L"Số tài khoản không tồn tại!";
        gotoXY(30, 16);
        system("pause");
        system("cls");
        hienThiGiaoDien();
        return;
    }
    gotoXY(30, 15);
    wstring str;
    wcout << L"Nhập số tiền cần chuyển: ";
    while ((ch = _getch()) != ENTER)
    {
        if (ch == BACKSPACE && str.size() > 0)
        {
            str[str.size() - 1] = '\0';
            str.resize(str.size() - 1);
            gotoXY(whereX() - 1, whereY());
            wcout << L" ";
            gotoXY(whereX() - 1, whereY());
        }
        else if (ch != BACKSPACE)
        {
            if (str.length() <= 9)
            {
                str += ch;
                wcout << ch;
            }
        }
    }
    if (str.length() == 0)
    {
        gotoXY(30, 16);
        wcout << L"Bạn chưa nhập gì!" << endl;
        gotoXY(30, 17);
        system("pause");
        system("cls");
        hienThiGiaoDien();
        return;
    }
    long long soTien;
    bool checkstr = true;
    for (int i = 0; i < str.length(); ++i) {
        if (!isdigit(str[i])) {
            soTien = -1;
            checkstr = false;
        }
    }
    if (checkstr)
    {
        soTien = stoll(str);
    }
    else
    {
        soTien = -1;
    }
    if (soTien < 0) {
        gotoXY(30, 16);
        wcout << L"Số tiền nhập không thỏa mãn. Yêu cầu nhập lại" << endl;
        gotoXY(30, 17);
        system("pause");
        system("cls");
        hienThiGiaoDien();
        return;
    }

    ht.timKiemNguoiNhan(soTaiKhoanNguoiChuyen, soTaiKhoanNguoiNhan, soTien); // con trỏ hàm
    system("pause");
    system("cls");
    hienThiGiaoDien();
    SetColor(7);
}
void ATM::chuyenTienTietKiem(HashTableThe& ht, wstring soTaiKhoanNguoiChuyen)
{
    wchar_t ch;
    const wchar_t ENTER = 13;
    const wchar_t BACKSPACE = 8;
    const wchar_t CTRL_E = 5;
    hienThiGiaoDien();
    SetColor(11);
    gotoXY(30, 14); wcin.ignore(0);
    wstring soTaiKhoanNguoiNhan;
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
        gotoXY(30, 15);
        wcout << L"Số tài khoản không hợp lệ!";
        gotoXY(30, 16);
        system("pause");
        system("cls");
        hienThiGiaoDien();
        return;
    }
    else if (soTaiKhoanNguoiChuyen == soTaiKhoanNguoiNhan)
    {
        gotoXY(30, 15);
        wcout << L"Số tài khoản trùng với chính mình!";
        gotoXY(30, 16);
        system("pause");
        system("cls");
        hienThiGiaoDien();
        return;
    }
    else if (!ht.checkSTK(soTaiKhoanNguoiNhan))
    {
        gotoXY(30, 15);
        wcout << L"Số tài khoản không tồn tại!";
        gotoXY(30, 16);
        system("pause");
        system("cls");
        hienThiGiaoDien();
        return;
    }
    gotoXY(30, 16);
    wstring str;
    wcout << L"Nhập số tiền cần chuyển: ";
    while ((ch = _getch()) != ENTER)
    {
        if (ch == BACKSPACE && str.size() > 0)
        {
            str[str.size() - 1] = '\0';
            str.resize(str.size() - 1);
            gotoXY(whereX() - 1, whereY());
            wcout << L" ";
            gotoXY(whereX() - 1, whereY());
        }
        else if (ch != BACKSPACE)
        {
            if (str.length() <= 9)
            {
                str += ch;
                wcout << ch;
            }
        }
    }
    if (str.length() == 0)
    {
        gotoXY(30, 16);
        wcout << L"Bạn chưa nhập gì!" << endl;
        gotoXY(30, 17);
        system("pause");
        system("cls");
        hienThiGiaoDien();
        return;
    }
    long long soTien;
    bool checkstr = true;
    for (int i = 0; i < str.length(); ++i) {
        if (!isdigit(str[i])) {
            soTien = -1;
            checkstr = false;
        }
    }
    if (checkstr)
    {
        soTien = stoll(str);
    }
    else
    {
        soTien = -1;
    }
    if (soTien < 0) {
        gotoXY(30, 18);
        wcout << L"Số tiền nhập không thỏa mãn. Yêu cầu nhập lại" << endl;
        gotoXY(30, 19);
        system("pause");
        system("cls");
        hienThiGiaoDien();
        return;
    }

    ht.timKiemNguoiNhanTK(soTaiKhoanNguoiChuyen, soTaiKhoanNguoiNhan, soTien);
    system("pause");
    system("cls");
    hienThiGiaoDien();
    SetColor(7);
}

void ATM::kiemTraSoDu(HashTableThe ht, wstring soTaiKhoan)
{
    SetColor(11);
    gotoXY(30, 14);
    ht.ktraSoDu(soTaiKhoan);
    char c = _getch();
    system("cls");
    hienThiGiaoDien();
}
void ATM::kiemTraSoDuTietKiem(HashTableThe ht, HashTableBank htbank, wstring soTaiKhoan)
{
    SetColor(11);
    gotoXY(30, 14);
    ht.ktraSoDuTietKiem(soTaiKhoan, htbank);
    char c = _getch();
    system("cls");
    hienThiGiaoDien();
}
void ATM::doiMaPin(HashTableThe& ht, wstring getSoTaiKhoan)
{
    hienThiGiaoDien();
    SetColor(11);
    int count = 0;
    int d = 14;
    while (1)
    {
        gotoXY(40, d);
        wstring maPinCu;
        if (count == 0) {
            wcout << L"Xác nhận mã pin cũ: ";
            wcin >> maPinCu;
        }
        else {
            wcout << L"Xác nhận lại mã pin cũ: ";
            wcin >> maPinCu;
        }

        if (the.getMaPin() == maPinCu) {
            wcout << endl;
            gotoXY(40, d + 2);
            wcout << L"Yêu cầu nhập mã pin mới: ";
            wstring maPinMoi; wcin >> maPinMoi;
            wcout << endl;
            ht.doiMaPin(the.getSoTaiKhoan(), maPinMoi);
            gotoXY(40, d + 4);
            wcout << L"Đổi mã pin thành công!" << endl;
            the.setMaPin(maPinMoi);
            system("pause");
            system("cls");
            hienThiGiaoDien();
            SetColor(7);
            break;
        }
        else {
            ++count;
            gotoXY(40, d + 2);
            wcout << L"Xác nhận mã pin sai! Yêu cầu nhập lại!" << endl;
            d += 4;
            if (count == 3) {
                wcout << L"Bạn đã nhập quá số lần cho phép!!!" << endl;
                system("cls");
                break;
            }
            _getch();
        }
    }
    hienThiGiaoDien();
}
void ATM::luaChonChucNang(HashTableThe& ht, HashTableBank htbank)
{
    int luaChon = 1, check = 1, in = 1;
    HANDLE hConsoleColor;
    hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
    while (check)
    {
        if (in) {
            SetColor(10);
            hienThiGiaoDien();


            gotoXY(40, 12);
            SetConsoleTextAttribute(hConsoleColor, 224);
            wcout << L"╔═══════════════════════╗";
            gotoXY(40, 13);
            wcout << L"║";
            SetConsoleTextAttribute(hConsoleColor, 228);
            wcout << L" 1.Kiểm tra tài khoản  ";
            SetConsoleTextAttribute(hConsoleColor, 224);
            //wcout << L"║";
            gotoXY(40, 14);
            wcout << L"╚═══════════════════════╝";

            gotoXY(40, 17);
            wcout << L"╔═══════════════════════╗";
            gotoXY(40, 18);
            wcout << L"║";
            SetConsoleTextAttribute(hConsoleColor, 224);
            wcout << L" 2.Tài khoản tiết kiệm   ";
            gotoXY(64, 19);
            //wcout << L"║";
            gotoXY(40, 19);
            wcout << L"╚═══════════════════════╝";


            gotoXY(40, 22);
            wcout << L"╔═══════════════════════╗";
            gotoXY(40, 23);
            wcout << L"║";
            SetConsoleTextAttribute(hConsoleColor, 224);
            wcout << L" 3.Thoát ";
            //wcout << L"║";
            gotoXY(40, 24);
            wcout << L"╚═══════════════════════╝";
            SetConsoleTextAttribute(hConsoleColor, 7);


            in = 0;
        }
        SetConsoleTextAttribute(hConsoleColor, 7);
        SetColor(2);
        gotoXY(20, 3);
        wcout << L"╔══════════════════════════════════════════════════════════════════╗";

        gotoXY(20, 4); wcout << L"║";
        gotoXY(20, 5); wcout << L"║";
        gotoXY(20, 6); wcout << L"║";
        gotoXY(20, 7); wcout << L"║";
        gotoXY(87, 4); wcout << L"║";
        gotoXY(87, 5); wcout << L"║";
        gotoXY(87, 6); wcout << L"║";
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
        gotoXY(20, 18); wcout << L"║";
        gotoXY(20, 19); wcout << L"║";
        gotoXY(20, 20); wcout << L"║";
        gotoXY(20, 21); wcout << L"║";
        gotoXY(20, 22); wcout << L"║";
        gotoXY(20, 23); wcout << L"║";
        gotoXY(20, 24); wcout << L"║";
        gotoXY(20, 25); wcout << L"║";
        gotoXY(87, 17); wcout << L"║";
        gotoXY(87, 18); wcout << L"║";
        gotoXY(87, 19); wcout << L"║";
        gotoXY(87, 20); wcout << L"║";
        gotoXY(87, 21); wcout << L"║";
        gotoXY(87, 22); wcout << L"║";
        gotoXY(87, 23); wcout << L"║";
        gotoXY(87, 24); wcout << L"║";
        gotoXY(20, 25);
        wcout << L"╚══════════════════════════════════════════════════════════════════╝";
        SetColor(7);

        gotoXY(40, 12);
        if (luaChon == CHUCNANG1)
        {
            SetConsoleTextAttribute(hConsoleColor, 224);
            wcout << L"╔═════════════════════════╗";
            gotoXY(40, 13); wcout << L"║";
            gotoXY(41, 13);
            SetConsoleTextAttribute(hConsoleColor, 228);
            wcout << L"   1.Kiểm tra tài khoản  ";
            SetConsoleTextAttribute(hConsoleColor, 224);
            gotoXY(66, 13); wcout << L"║";
            gotoXY(40, 14);
            wcout << L"╚═════════════════════════╝";
            SetConsoleTextAttribute(hConsoleColor, 7);
        }
        else
        {
            // t� n?u l�n xu?ng th� in l?i m�u tr?ng
            SetConsoleTextAttribute(hConsoleColor, 112);
            wcout << L"╔═════════════════════════╗";
            gotoXY(40, 13); wcout << L"║";
            gotoXY(41, 13);
            wcout << L"   1.Kiểm tra tài khoản  ";
            gotoXY(66, 13); wcout << L"║";
            gotoXY(40, 14);
            wcout << L"╚═════════════════════════╝";
            SetConsoleTextAttribute(hConsoleColor, 7);
        }
        gotoXY(40, 17);
        if (luaChon == CHUCNANG2)
        {
            SetConsoleTextAttribute(hConsoleColor, 224);
            wcout << L"╔═════════════════════════╗";
            gotoXY(40, 18); wcout << L"║";
            gotoXY(41, 18);
            SetConsoleTextAttribute(hConsoleColor, 228);
            wcout << L"   2.Tài khoản tiết kiệm ";
            SetConsoleTextAttribute(hConsoleColor, 224);
            gotoXY(66, 18); wcout << L"║";
            gotoXY(40, 19);
            wcout << L"╚═════════════════════════╝";
            SetConsoleTextAttribute(hConsoleColor, 7);
        }
        else
        {
            SetConsoleTextAttribute(hConsoleColor, 112);
            wcout << L"╔═════════════════════════╗";
            gotoXY(40, 18); wcout << L"║";
            gotoXY(41, 18);
            wcout << L"   2.Tài khoản tiết kiệm ";
            gotoXY(66, 18); wcout << L"║";
            gotoXY(40, 19);
            wcout << L"╚═════════════════════════╝";
            SetConsoleTextAttribute(hConsoleColor, 7);
        }
        gotoXY(40, 22);
        if (luaChon == CHUCNANG3)
        {
            SetConsoleTextAttribute(hConsoleColor, 224);
            wcout << L"╔═════════════════════════╗";
            gotoXY(40, 23); wcout << L"║";
            gotoXY(41, 23);
            SetConsoleTextAttribute(hConsoleColor, 228);
            wcout << L"         3.Thoát         ";
            SetConsoleTextAttribute(hConsoleColor, 224);
            gotoXY(66, 23); wcout << L"║";
            gotoXY(40, 24);
            wcout << L"╚═════════════════════════╝";
            SetConsoleTextAttribute(hConsoleColor, 7);
        }
        else
        {
            SetConsoleTextAttribute(hConsoleColor, 112);
            wcout << L"╔═════════════════════════╗";
            gotoXY(40, 23); wcout << L"║";
            gotoXY(41, 23);
            wcout << L"         3.Thoát         ";
            gotoXY(66, 23); wcout << L"║";
            gotoXY(40, 24);
            wcout << L"╚═════════════════════════╝";
            SetConsoleTextAttribute(hConsoleColor, 7);
        }
        char kitu = _getch();
        if (kitu == UP)
        { // di l�n
            if (luaChon == CHUCNANG2 || luaChon == CHUCNANG3)
            {
                luaChon--;
            }
        }
        else if (kitu == DOWN) // di xu?ng
        {
            if (luaChon == CHUCNANG1 || luaChon == CHUCNANG2)
            {
                luaChon++;
            }
        }
        else if (kitu == ENTER)
        {
            bool inGiaoDien = true;
            switch (luaChon)
            {
            case CHUCNANG1:
            {
                luaChon = CHUCNANG1;
                hienThiGiaoDien();
                int kiemTra = 1;
                while (kiemTra)
                {
                    gotoXY(30, 12);
                    if (luaChon == CHUCNANG1)
                    {
                        SetConsoleTextAttribute(hConsoleColor, 224);
                        wcout << L"╔═════════════════════════╗";
                        gotoXY(30, 13); wcout << L"║";
                        gotoXY(31, 13);
                        SetConsoleTextAttribute(hConsoleColor, 228);
                        wcout << L"   1.Thông tin cá nhân    ";
                        SetConsoleTextAttribute(hConsoleColor, 224);
                        gotoXY(56, 13); wcout << L"║";
                        gotoXY(30, 14);
                        wcout << L"╚═════════════════════════╝";
                        SetConsoleTextAttribute(hConsoleColor, 7);
                    }
                    else
                    {
                        // t� n?u l�n xu?ng th� in l?i m�u tr?ng
                        SetConsoleTextAttribute(hConsoleColor, 112);
                        wcout << L"╔═════════════════════════╗";
                        gotoXY(30, 13); wcout << L"║";
                        gotoXY(31, 13);
                        wcout << L"   1.Thông tin cá nhân    ";
                        gotoXY(56, 13); wcout << L"║";
                        gotoXY(30, 14);
                        wcout << L"╚═════════════════════════╝";
                        SetConsoleTextAttribute(hConsoleColor, 7);
                    }
                    gotoXY(30, 17);
                    if (luaChon == CHUCNANG2)
                    {
                        SetConsoleTextAttribute(hConsoleColor, 224);
                        wcout << L"╔═════════════════════════╗";
                        gotoXY(30, 18); wcout << L"║";
                        gotoXY(31, 18);
                        SetConsoleTextAttribute(hConsoleColor, 228);
                        wcout << L"        2.Rút tiền        ";
                        SetConsoleTextAttribute(hConsoleColor, 224);
                        gotoXY(56, 18); wcout << L"║";
                        gotoXY(30, 19);
                        wcout << L"╚═════════════════════════╝";
                        SetConsoleTextAttribute(hConsoleColor, 7);
                    }
                    else
                    {
                        SetConsoleTextAttribute(hConsoleColor, 112);
                        wcout << L"╔═════════════════════════╗";
                        gotoXY(30, 18); wcout << L"║";
                        gotoXY(31, 18);
                        wcout << L"        2.Rút tiền        ";
                        gotoXY(56, 18); wcout << L"║";
                        gotoXY(30, 19);
                        wcout << L"╚═════════════════════════╝";
                        SetConsoleTextAttribute(hConsoleColor, 7);
                    }
                    gotoXY(30, 22);
                    if (luaChon == CHUCNANG3)
                    {
                        SetConsoleTextAttribute(hConsoleColor, 224);
                        wcout << L"╔═════════════════════════╗";
                        gotoXY(30, 23); wcout << L"║";
                        gotoXY(31, 23);
                        SetConsoleTextAttribute(hConsoleColor, 228);
                        wcout << L"      3.Chuyển tiền       ";
                        SetConsoleTextAttribute(hConsoleColor, 224);
                        gotoXY(56, 23); wcout << L"║";
                        gotoXY(30, 24);
                        wcout << L"╚═════════════════════════╝";
                        SetConsoleTextAttribute(hConsoleColor, 7);
                    }
                    else
                    {
                        SetConsoleTextAttribute(hConsoleColor, 112);
                        wcout << L"╔═════════════════════════╗";
                        gotoXY(30, 23); wcout << L"║";
                        gotoXY(31, 23);
                        wcout << L"      3.Chuyển tiền       ";
                        gotoXY(56, 23); wcout << L"║";
                        gotoXY(30, 24);
                        wcout << L"╚═════════════════════════╝";
                        SetConsoleTextAttribute(hConsoleColor, 7);
                    }
                    gotoXY(70, 12);
                    if (luaChon == CHUCNANG4)
                    {
                        SetConsoleTextAttribute(hConsoleColor, 224);
                        wcout << L"╔═════════════════════════╗";
                        gotoXY(70, 13); wcout << L"║";
                        gotoXY(71, 13);
                        SetConsoleTextAttribute(hConsoleColor, 228);
                        wcout << L"      4.Đổi mã pin       ";
                        SetConsoleTextAttribute(hConsoleColor, 224);
                        gotoXY(96, 13); wcout << L"║";
                        gotoXY(70, 14);
                        wcout << L"╚═════════════════════════╝";
                        SetConsoleTextAttribute(hConsoleColor, 7);
                    }
                    else
                    {
                        SetConsoleTextAttribute(hConsoleColor, 112);
                        wcout << L"╔═════════════════════════╗";
                        gotoXY(70, 13); wcout << L"║";
                        gotoXY(71, 13);
                        wcout << L"      4.Đổi mã pin       ";
                        gotoXY(96, 13); wcout << L"║";
                        gotoXY(70, 14);
                        wcout << L"╚═════════════════════════╝";
                        SetConsoleTextAttribute(hConsoleColor, 7);
                    }
                    gotoXY(70, 17);
                    if (luaChon == CHUCNANG5)
                    {
                        SetConsoleTextAttribute(hConsoleColor, 224);
                        wcout << L"╔═════════════════════════╗";
                        gotoXY(70, 18); wcout << L"║";
                        gotoXY(71, 18);
                        SetConsoleTextAttribute(hConsoleColor, 228);
                        wcout << L"    5.Kiểm tra số dư      ";
                        SetConsoleTextAttribute(hConsoleColor, 224);
                        gotoXY(96, 18); wcout << L"║";
                        gotoXY(70, 19);
                        wcout << L"╚═════════════════════════╝";
                        SetConsoleTextAttribute(hConsoleColor, 7);
                    }
                    else
                    {
                        SetConsoleTextAttribute(hConsoleColor, 112);
                        wcout << L"╔═════════════════════════╗";
                        gotoXY(70, 18); wcout << L"║";
                        gotoXY(71, 18);
                        wcout << L"    5.Kiểm tra số dư      ";
                        gotoXY(96, 18); wcout << L"║";
                        gotoXY(70, 19);
                        wcout << L"╚═════════════════════════╝";
                        SetConsoleTextAttribute(hConsoleColor, 7);
                    }
                    gotoXY(70, 22);
                    if (luaChon == CHUCNANG6)
                    {
                        SetConsoleTextAttribute(hConsoleColor, 224);
                        wcout << L"╔═════════════════════════╗";
                        gotoXY(70, 23); wcout << L"║";
                        gotoXY(71, 23);
                        SetConsoleTextAttribute(hConsoleColor, 228);
                        wcout << L"   6.Trở về trang chủ     ";
                        SetConsoleTextAttribute(hConsoleColor, 224);
                        gotoXY(96, 23); wcout << L"║";
                        gotoXY(70, 24);
                        wcout << L"╚═════════════════════════╝";
                        SetConsoleTextAttribute(hConsoleColor, 7);
                    }
                    else
                    {
                        SetConsoleTextAttribute(hConsoleColor, 112);
                        wcout << L"╔═════════════════════════╗";
                        gotoXY(70, 23); wcout << L"║";
                        gotoXY(71, 23);
                        wcout << L"   6.Trở về trang chủ     ";
                        gotoXY(96, 23); wcout << L"║";
                        gotoXY(70, 24);
                        wcout << L"╚═════════════════════════╝";
                        SetConsoleTextAttribute(hConsoleColor, 7);
                    }
                    char CHUCNANGCON = _getch();
                    if (CHUCNANGCON == UP)
                    {
                        if (luaChon == CHUCNANG3 || luaChon == CHUCNANG2 || luaChon == CHUCNANG6 || luaChon == CHUCNANG5)
                        {
                            --luaChon;
                        }
                    }
                    else if (CHUCNANGCON == DOWN)
                    {
                        if (luaChon == CHUCNANG1 || luaChon == CHUCNANG2 || luaChon == CHUCNANG4 || luaChon == CHUCNANG5)
                        {
                            ++luaChon;
                        }
                    }
                    else if (CHUCNANGCON == RIGHT)
                    {
                        // sang ph?i
                        if (luaChon == CHUCNANG1 || luaChon == CHUCNANG2 || luaChon == CHUCNANG3)
                        {
                            luaChon += 3;
                        }
                    }
                    else if (CHUCNANGCON == LEFT)
                    {
                        // sang tr�i
                        if (luaChon == CHUCNANG4 || luaChon == CHUCNANG5 || luaChon == CHUCNANG6)
                        {
                            luaChon -= 3;
                        }
                    }
                    else if (CHUCNANGCON == ENTER)
                    {
                        wstring getSoTaiKhoan = the.getSoTaiKhoan();
                        wstring getMaPin = the.getMaPin();
                        switch (luaChon)
                        {
                        case CHUCNANG1:
                        {
                            kiemTraThongTin(ht, htbank, getSoTaiKhoan);
                            break;
                        }
                        case CHUCNANG2:
                        {
                            rutTien(ht, getSoTaiKhoan);
                            break;
                        }
                        case CHUCNANG3:
                        {
                            chuyenTien(ht, getSoTaiKhoan);
                            break;
                        }
                        case CHUCNANG4:
                        {
                            doiMaPin(ht, getSoTaiKhoan);
                            break;
                        }
                        case CHUCNANG5:
                        {
                            kiemTraSoDu(ht, getSoTaiKhoan);
                            break;
                        }
                        case CHUCNANG6:
                        {
                            kiemTra = 0;
                            system("cls");
                            hienThiGiaoDien();

                            luaChon = CHUCNANG1; // reset l?i b?i v� t� v�o t?ng l?a ch?n s? b? thay d?i
                            in = 1; // reset d? in l?i h�nh ATM
                            break;
                        }
                        }
                    }
                }
                break;
            }
            case CHUCNANG2:
            {
                luaChon = CHUCNANG1;
                hienThiGiaoDien();
                int kiemTra = 1;
                while (kiemTra)
                {
                    gotoXY(30, 12);
                    if (luaChon == CHUCNANG1)
                    {
                        SetConsoleTextAttribute(hConsoleColor, 224);
                        wcout << L"╔══════════════════════════╗";
                        gotoXY(30, 13); wcout << L"║";
                        gotoXY(31, 13);
                        SetConsoleTextAttribute(hConsoleColor, 228);
                        wcout << L"   1.Thông tin cá nhân     ";
                        SetConsoleTextAttribute(hConsoleColor, 224);
                        gotoXY(57, 13); wcout << L"║";
                        gotoXY(30, 14);
                        wcout << L"╚══════════════════════════╝";
                        SetConsoleTextAttribute(hConsoleColor, 7);
                    }
                    else
                    {
                        // t� n?u l�n xu?ng th� in l?i m�u tr?ng
                        SetConsoleTextAttribute(hConsoleColor, 112);
                        wcout << L"╔══════════════════════════╗";
                        gotoXY(30, 13); wcout << L"║";
                        gotoXY(31, 13);
                        wcout << L"   1.Thông tin cá nhân     ";
                        gotoXY(57, 13); wcout << L"║";
                        gotoXY(30, 14);
                        wcout << L"╚══════════════════════════╝";
                        SetConsoleTextAttribute(hConsoleColor, 7);
                    }
                    gotoXY(30, 17);
                    if (luaChon == CHUCNANG2)
                    {
                        SetConsoleTextAttribute(hConsoleColor, 224);
                        wcout << L"╔══════════════════════════╗";
                        gotoXY(30, 18); wcout << L"║";
                        gotoXY(31, 18);
                        SetConsoleTextAttribute(hConsoleColor, 228);
                        wcout << L"   2.Rút tiền tiết kiệm    ";
                        SetConsoleTextAttribute(hConsoleColor, 224);
                        gotoXY(57, 18); wcout << L"║";
                        gotoXY(30, 19);
                        wcout << L"╚══════════════════════════╝";
                        SetConsoleTextAttribute(hConsoleColor, 7);
                    }
                    else
                    {
                        SetConsoleTextAttribute(hConsoleColor, 112);
                        wcout << L"╔══════════════════════════╗";
                        gotoXY(30, 18); wcout << L"║";
                        gotoXY(31, 18);
                        wcout << L"   2.Rút tiền tiết kiệm    ";
                        gotoXY(57, 18); wcout << L"║";
                        gotoXY(30, 19);
                        wcout << L"╚══════════════════════════╝";
                        SetConsoleTextAttribute(hConsoleColor, 7);
                    }
                    gotoXY(30, 22);
                    if (luaChon == CHUCNANG3)
                    {
                        SetConsoleTextAttribute(hConsoleColor, 224);
                        wcout << L"╔══════════════════════════╗";
                        gotoXY(30, 23); wcout << L"║";
                        gotoXY(31, 23);
                        SetConsoleTextAttribute(hConsoleColor, 228);
                        wcout << L" 3.Chuyển tiền tiết kiệm   ";
                        SetConsoleTextAttribute(hConsoleColor, 224);
                        gotoXY(57, 23); wcout << L"║";
                        gotoXY(30, 24);
                        wcout << L"╚══════════════════════════╝";
                        SetConsoleTextAttribute(hConsoleColor, 7);
                    }
                    else
                    {
                        SetConsoleTextAttribute(hConsoleColor, 112);
                        wcout << L"╔══════════════════════════╗";
                        gotoXY(30, 23); wcout << L"║";
                        gotoXY(31, 23);
                        wcout << L" 3.Chuyển tiền tiết kiệm   ";
                        gotoXY(57, 23); wcout << L"║";
                        gotoXY(30, 24);
                        wcout << L"╚══════════════════════════╝";
                        SetConsoleTextAttribute(hConsoleColor, 7);
                    }
                    gotoXY(70, 12);
                    if (luaChon == CHUCNANG4)
                    {
                        SetConsoleTextAttribute(hConsoleColor, 224);
                        wcout << L"╔══════════════════════════╗";
                        gotoXY(70, 13); wcout << L"║";
                        gotoXY(71, 13);
                        SetConsoleTextAttribute(hConsoleColor, 228);
                        wcout << L"      4.Đổi mã pin        ";
                        SetConsoleTextAttribute(hConsoleColor, 224);
                        gotoXY(97, 13); wcout << L"║";
                        gotoXY(70, 14);
                        wcout << L"╚══════════════════════════╝";
                        SetConsoleTextAttribute(hConsoleColor, 7);
                    }
                    else
                    {
                        SetConsoleTextAttribute(hConsoleColor, 112);
                        wcout << L"╔══════════════════════════╗";
                        gotoXY(70, 13); wcout << L"║";
                        gotoXY(71, 13);
                        wcout << L"      4.Đổi mã pin        ";
                        gotoXY(97, 13); wcout << L"║";
                        gotoXY(70, 14);
                        wcout << L"╚══════════════════════════╝";
                        SetConsoleTextAttribute(hConsoleColor, 7);
                    }
                    gotoXY(70, 17);
                    if (luaChon == CHUCNANG5)
                    {
                        SetConsoleTextAttribute(hConsoleColor, 224);
                        wcout << L"╔══════════════════════════╗";
                        gotoXY(70, 18); wcout << L"║";
                        gotoXY(71, 18);
                        SetConsoleTextAttribute(hConsoleColor, 228);
                        wcout << L"5.Kiểm tra số dư tiết kiệm";
                        SetConsoleTextAttribute(hConsoleColor, 224);
                        gotoXY(97, 18); wcout << L"║";
                        gotoXY(70, 19);
                        wcout << L"╚══════════════════════════╝";
                        SetConsoleTextAttribute(hConsoleColor, 7);
                    }
                    else
                    {
                        SetConsoleTextAttribute(hConsoleColor, 112);
                        wcout << L"╔══════════════════════════╗";
                        gotoXY(70, 18); wcout << L"║";
                        gotoXY(71, 18);
                        wcout << L"5.Kiểm tra số dư tiết kiệm";
                        gotoXY(97, 18); wcout << L"║";
                        gotoXY(70, 19);
                        wcout << L"╚══════════════════════════╝";
                        SetConsoleTextAttribute(hConsoleColor, 7);
                    }
                    gotoXY(70, 22);
                    if (luaChon == CHUCNANG6)
                    {
                        SetConsoleTextAttribute(hConsoleColor, 224);
                        wcout << L"╔══════════════════════════╗";
                        gotoXY(70, 23); wcout << L"║";
                        gotoXY(71, 23);
                        SetConsoleTextAttribute(hConsoleColor, 228);
                        wcout << L"    6.Trở về trang chủ     ";
                        SetConsoleTextAttribute(hConsoleColor, 224);
                        gotoXY(97, 23); wcout << L"║";
                        gotoXY(70, 24);
                        wcout << L"╚══════════════════════════╝";
                        SetConsoleTextAttribute(hConsoleColor, 7);
                    }
                    else
                    {
                        SetConsoleTextAttribute(hConsoleColor, 112);
                        wcout << L"╔══════════════════════════╗";
                        gotoXY(70, 23); wcout << L"║";
                        gotoXY(71, 23);
                        wcout << L"    6.Trở về trang chủ     ";
                        gotoXY(97, 23); wcout << L"║";
                        gotoXY(70, 24);
                        wcout << L"╚══════════════════════════╝";
                        SetConsoleTextAttribute(hConsoleColor, 7);
                    }

                    char CHUCNANGCON = _getch();
                    if (CHUCNANGCON == UP)
                    {
                        if (luaChon == CHUCNANG3 || luaChon == CHUCNANG2 || luaChon == CHUCNANG6 || luaChon == CHUCNANG5)
                        {
                            --luaChon;
                        }
                    }
                    else if (CHUCNANGCON == DOWN)
                    {
                        if (luaChon == CHUCNANG1 || luaChon == CHUCNANG2 || luaChon == CHUCNANG4 || luaChon == CHUCNANG5)
                        {
                            ++luaChon;
                        }
                    }
                    else if (CHUCNANGCON == RIGHT)
                    {
                        if (luaChon == CHUCNANG1 || luaChon == CHUCNANG2 || luaChon == CHUCNANG3)
                        {
                            luaChon += 3;
                        }
                    }
                    else if (CHUCNANGCON == LEFT)
                    {
                        if (luaChon == CHUCNANG4 || luaChon == CHUCNANG5 || luaChon == CHUCNANG6)
                        {
                            luaChon -= 3;
                        }
                    }
                    else if (CHUCNANGCON == ENTER)
                    {
                        wstring getSoTaiKhoan = the.getSoTaiKhoan();
                        wstring getMaPin = the.getMaPin();
                        switch (luaChon)
                        {
                        case CHUCNANG1:
                        {
                            kiemTraThongTin(ht, htbank, getSoTaiKhoan);
                            break;
                        }
                        case CHUCNANG2:
                        {
                            rutTienTietKiem(ht, getSoTaiKhoan);
                            break;
                        }
                        case CHUCNANG3:
                        {
                            chuyenTienTietKiem(ht, getSoTaiKhoan);
                            break;
                        }
                        case CHUCNANG4:
                        {
                            doiMaPin(ht, getSoTaiKhoan);
                            break;
                        }
                        case CHUCNANG5:
                        {
                            kiemTraSoDuTietKiem(ht, htbank, getSoTaiKhoan);
                            break;
                        }
                        case CHUCNANG6:
                        {
                            kiemTra = 0;
                            system("cls");
                            hienThiGiaoDien();

                            luaChon = CHUCNANG1; // reset l?i b?i v� t� v�o t?ng l?a ch?n s? b? thay d?i
                            in = 1; // reset d? in l?i h�nh ATM
                            break;
                        }
                        }
                    }
                }
                break;
            }
            case CHUCNANG3:
            {
                system("cls");
                check = 0;
                break;
            }
            }
        }
    }
}
void ATM::hienThi(HashTableThe hashtb, bool& checklogin)
{
    ShowCur(false);
    wchar_t ch;
    const wchar_t ENTER = 13;
    const wchar_t BACKSPACE = 8;
    const wchar_t CTRL_E = 5;
    int count = 0;
    while (true)
    {
        if (count == 1)
        {
            gotoXY(45, 16);
            wcout << L"Tài khoản đăng nhập không thành công!";
            gotoXY(45, 17);
            checklogin = false;
            system("pause");
            system("cls");
            break;
        }
        SetColor(10);
        hienThiGiaoDien();
        wstring soTaiKhoan;
        bool check1 = true;
        do
        {
            check1 = true;
            hienThiGiaoDien();
            gotoXY(45, 13);
            SetColor(10);
            wcout << L"Tài khoản: ";
            SetColor(7);
            while ((ch = _getch()) != ENTER)
            {
                if (ch == BACKSPACE && soTaiKhoan.size() > 0)
                {
                    soTaiKhoan[soTaiKhoan.size() - 1] = '\0';
                    soTaiKhoan.resize(soTaiKhoan.size() - 1);
                    gotoXY(whereX() - 1, whereY());
                    wcout << L" ";
                    gotoXY(whereX() - 1, whereY());
                }
                else if (ch != BACKSPACE)
                {
                    if (soTaiKhoan.length() < 9)
                    {
                        soTaiKhoan += ch;
                        wcout << ch;
                    }
                }
            }
            if (soTaiKhoan.length() == 0)
            {
                check1 = false;
                gotoXY(45, 14);
                wcout << L"Số tài khoản không hợp lệ!";
                gotoXY(45, 15);
                system("pause");
                system("cls");
            }
        } while (!check1);
        the.setSoTaiKhoan(soTaiKhoan);
        gotoXY(45, 15);
        SetColor(9);
        wcout << L"Mật khẩu: ";
        SetColor(7);
        wstring maPin;
        wchar_t ch;
        const wchar_t ENTER = 13;
        const wchar_t BACKSPACE = 8;
        while ((ch = _getch()) != ENTER)
        {
            if (ch != BACKSPACE)
            {
                maPin += ch;
                wcout << L'*';
            }
            else if (ch == BACKSPACE && maPin.size() != 0)
            {
                maPin[maPin.size() - 1] = '\0';
                maPin.resize(maPin.size() - 1);
                gotoXY(whereX() - 1, whereY());
                wcout << L" ";
                gotoXY(whereX() - 1, whereY());
            }
        }
        //the.getMaPin() = maPin;
        the.setMaPin(maPin);
        if (hashtb.checkLoginATM(the.getSoTaiKhoan(), the.getMaPin())) {
            break;
        }
        count++;
        
    }
}