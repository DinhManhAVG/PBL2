#pragma once
#include"AppBanking.h"
#include"ATM.h"

class Person : public The, public ATM , public AppBanking
{
public:
	Person() {

	}
	/*Person(wstring soTaiKhoan, wstring matKhau, wstring maPin, wstring hoVaTen, wstring gioiTinh, wstring diaChi, int soTienHienCo, int soTienTietKiem, wstring maBank) {
		The::setSoTaiKhoan(soTaiKhoan);
		The::setMatKhau(matKhau);
		The::setMaPin(maPin);
		The::setHoVaTen(hoVaTen);
		The::setGioiTinh(gioiTinh);
		The::setSoDu(soTienHienCo);
		The::setSoDuTietKiem(soTienTietKiem);
		The::setDiaChi(diaChi);
	}*/

};

