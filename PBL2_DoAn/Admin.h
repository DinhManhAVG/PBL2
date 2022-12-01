#pragma once
#include "Bank.h"
#include "HashTableThe.h"
class Admin
{
private:
	wstring maAdmin;
	wstring matKhauAdmin;
	wstring tenAdmin;
	wstring ngaySinh;
public:
	Admin();
	Admin(wstring, wstring, wstring, wstring);
	void setMaAdmin(wstring);
	wstring getMaAdmin();
	void setMatKhauAdmin(wstring);
	wstring getMatKhauAdmin();
	void setTenAdmin(wstring);
	wstring getTenAdmin();
	void setNgaySinh(wstring);
	wstring getNgaySinh();
	void DanhSachThongTin(HashTableThe hashtbUser);
};

