#pragma once
#include"Bank.h"
using namespace std;
static int count = 0;
class The
{
private:
	wstring hoVaTen;
	wstring gioiTinh;
	wstring ngaySinh;
	wstring diaChi;
	wstring soTaiKhoan;
	wstring matKhau;
	wstring maPin;
	long long soDu;
	long long soDuTietKiem;
	wstring maBank;
public:
	The();
	The(wstring, wstring, wstring, wstring, wstring, wstring, wstring, long long, long long,wstring);
	void setHoVaTen(wstring);
	wstring getHoVaTen();
	void setGioiTinh(wstring);
	wstring getGioiTinh();
	void setDiaChi(wstring);
	wstring getDiaChi();
	void setSoTaiKhoan(wstring);
	wstring getSoTaiKhoan();
	void setMatKhau(wstring);
	wstring getMatKhau();
	void setMaPin(wstring);
	wstring getMaPin();
	void setNgaySinh();
	wstring getNgaySinh();
	void setSoDu(long long);
	long long getSoDu();
	void setSoDuTietKiem(long long);
	long long getSoDuTietKiem();
	void setMaBank(wstring);
	wstring getMaBank();
	
};