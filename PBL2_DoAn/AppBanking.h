#pragma once
#include "HashTableThe.h"
#include"HashTableAdmin.h"
class AppBanking
{
private:
	The the;
	Admin ad;
public:
	AppBanking()
	{
		
	}
	~AppBanking()
	{

	}
	void chuyenKhoan(HashTableThe& hashtb);
	void kiemTraThongTin(HashTableThe, HashTableBank);
	void hienThiTopKhachHang(HashTableThe hashtb, HashTableBank hashtbank);
	void doiMatKhau(HashTableThe& hashtb);
	void doiMatKhauAd(HashTableAdmin& hashtad);
	bool checkAccount(wstring acc, wstring pass, wstring nameFile);
	void paintKhung();
	void paintKhungDangKi(HashTableBank hashtbank);
	void paintApp();
	void displayApp(HashTableThe& hashtb, HashTableBank hashtbank, HashTableAdmin hashtad);
	void paintAdmin();
	void displayAdmin(HashTableAdmin& hashtad, HashTableThe& hashtuser, HashTableBank& hashtbank);
	void paintTongQuat();
	void displayTongQuat(HashTableThe& hashtb, int& access, HashTableBank& hashtbank, HashTableAdmin hashtad);
	void displayDangNhap(wstring nameFile, bool& checkCount, HashTableAdmin hashtad, HashTableThe hashtuser);
	void displayTaoTaiKhoan(HashTableThe& hashtb, HashTableBank& hashtbank);
};
