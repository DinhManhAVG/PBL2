#pragma once
#include"HashTableThe.h"
using namespace std;
class ATM
{
private:
    The the;
    static long long soTienHienCo;

public:
    void kiemTraThongTin(HashTableThe, HashTableBank, wstring);// dựa vào số tài khoản để in ra 
    void rutTien(HashTableThe&, wstring);
    void rutTienTietKiem(HashTableThe& ht, wstring getSoTaiKhoan);
    void chuyenTien(HashTableThe&, wstring);
    void chuyenTienTietKiem(HashTableThe&, wstring);
    void kiemTraSoDu(HashTableThe, wstring);
    void kiemTraSoDuTietKiem(HashTableThe ht, HashTableBank htbank, wstring soTaiKhoan);
    void hienThiGiaoDien();
    void doiMaPin(HashTableThe&, wstring);
    void luaChonChucNang(HashTableThe& ht, HashTableBank htbank);
    void hienThi(HashTableThe hashtb);
};