#pragma once
#include"My_lib.h"
using namespace std;
class Bank
{
private:
	// liên kết bằng số tài khoản
	wstring maAdmin;
	wstring maBank;
	wstring tenBank;
	double laiSuat;
	int soLuongUser;
	wstring diaDiem;
	const long long soTienCungCapATM = 5000000000;
public:
	Bank();
	Bank(wstring,wstring, wstring, double, int,wstring);
	void setMaAdmin(wstring maAdmin);
	wstring getMaAdmin();
	long long getSoTienCungCapATM();
	void setMaBank(wstring maBank);
	wstring getMaBank();
	void setTenBank(wstring);
	wstring getTenBank();
	void setLaiSuat(double);
	double getLaiSuat();
	void setDiaDiem(wstring);
	wstring getDiaDiem();
	void setSoLuongUser(int);
	int getSoLuongUser();
	long long tinhTongSoTienTietKiem(long long soDuTietKiem, int soThang, double laiSuat);
	const Bank& operator = (const Bank& bank);
};