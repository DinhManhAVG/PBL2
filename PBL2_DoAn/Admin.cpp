#include "Admin.h"
Admin::Admin() 
{

}
Admin::Admin(wstring maAdmin, wstring matKhauAdmin, wstring tenAdmin, wstring ngaySinh)
{
	this->maAdmin = maAdmin;
	this->matKhauAdmin = matKhauAdmin;
	this->tenAdmin = tenAdmin;
	this->ngaySinh = ngaySinh;
}
void Admin::setMaAdmin(wstring maAdmin)
{
	this->maAdmin = maAdmin;
}
wstring Admin::getMaAdmin() 
{
	return maAdmin;
}
void Admin::setMatKhauAdmin(wstring matKhauAdmin) 
{
	this->matKhauAdmin = matKhauAdmin;
}
wstring Admin::getMatKhauAdmin() 
{
	return matKhauAdmin;
}
void Admin::setTenAdmin(wstring tenAdmin) 
{
	this->tenAdmin = tenAdmin;
}
wstring Admin::getTenAdmin() 
{
	return tenAdmin;
}
void Admin::setNgaySinh(wstring ngaySinh) 
{
	this->ngaySinh = ngaySinh;
}
wstring Admin::getNgaySinh() 
{
	return ngaySinh;
}

void Admin::DanhSachThongTin(HashTableThe hashtbUser)
{
	hashtbUser.xuatHashTable();
	system("pause");
	system("cls");
}