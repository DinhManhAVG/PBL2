#pragma once
#include"HashTableUser.h"
using namespace std;
class ATM
{
private:
    The the;
    static long long soTienHienCo;

public:
    void kiemTraThongTin(HashTableUser, HashTableBank, wstring);// dựa vào số tài khoản để in ra 
    void rutTien(HashTableUser&, wstring);
    void rutTienTietKiem(HashTableUser& ht, wstring getSoTaiKhoan);
    void chuyenTien(HashTableUser&, wstring);
    void chuyenTienTietKiem(HashTableUser&, wstring);
    void kiemTraSoDu(HashTableUser, wstring);
    void kiemTraSoDuTietKiem(HashTableUser ht, HashTableBank htbank, wstring soTaiKhoan);
    void hienThiGiaoDien();
    void doiMaPin(HashTableUser&, wstring);
    void luaChonChucNang(HashTableUser& ht, HashTableBank htbank);
    void hienThi(HashTableUser hashtb);
};