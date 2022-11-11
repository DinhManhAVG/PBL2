#pragma once
#include "HashTableUser.h"
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
	void chuyenKhoan(HashTableUser hashtb);
	void traNoKhoanVay();
	void hienThiTopKhachHang(HashTableUser hashtb, HashTableBank hashtbank);
	void doiMatKhau(HashTableUser& hashtb);
	void doiMatKhauAd(HashTableAdmin& hashtad);
	bool checkAccount(wstring acc, wstring pass, wstring nameFile);
	void paintKhung();
	void paintApp();
	void displayApp(HashTableUser& hashtb, HashTableBank hashtbank, HashTableAdmin hashtad);
	void paintAdmin();
	void displayAdmin(HashTableAdmin& hashtad, HashTableUser& hashtuser, HashTableBank& hashtbank);
	void paintTongQuat();
	void displayTongQuat(HashTableUser hashtb, int& access, HashTableAdmin hashtad);
	void displayDangNhap(wstring nameFile, bool& checkCount, HashTableAdmin hashtad, HashTableUser hashtuser);
	void displayTaoTaiKhoan(HashTableUser hashtb);
};
