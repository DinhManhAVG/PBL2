#pragma once
#include"HashTableUser.h"
using namespace std;
class ATM
{
private:
    The the;
    static long long soTienHienCo;

public:
    void kiemTraThongTin(HashTableUser, wstring);// dựa vào số tài khoản để in ra 
    /*void setHoVaTen(wstring);
    string getHoVaTen();
    void setgioiTinh(wstring);
    string getGioiTinh();
    void setngaySinh(wstring);
    string getNgaySinh();*/

    void rutTien(HashTableUser, wstring);
    void rutTienTietKiem(HashTableUser ht, wstring getSoTaiKhoan);
    void chuyenTien(HashTableUser, wstring);
    void chuyenTienTietKiem(HashTableUser, wstring);

    void kiemTraSoDu(HashTableUser, wstring);
    void kiemTraSoDuTietKiem(HashTableUser ht, wstring soTaiKhoan);
    void hienThiGiaoDien();
    void doiMaPin(HashTableUser, wstring);
    void luaChonChucNang(HashTableUser ht);
    bool kiemTraTaiKhoan(wstring soTaiKhoan, wstring maPin);
    void hienThi();
};