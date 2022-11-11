#include "The.h"
The::The()
{
	
}
The::The(wstring soTaiKhoan, wstring matKhau, wstring maPin, wstring hoVaTen, wstring gioiTinh, wstring ngaySinh, wstring diaChi, long long soDu, long long soDuTietKiem,wstring maBank)
{
	this->soTaiKhoan = soTaiKhoan;
	this->matKhau = matKhau;
	this->maPin = maPin;
	this->hoVaTen = hoVaTen;
	this->gioiTinh = gioiTinh;
	this->ngaySinh = ngaySinh;
	this->diaChi = diaChi;
	this->soDu = soDu;
	this->soDuTietKiem = soDuTietKiem;
	this->maBank = maBank;
}
void The::setHoVaTen(wstring hoVaTen)
{
	this->hoVaTen = hoVaTen;
}
wstring The::getHoVaTen()
{
	return this->hoVaTen;
}
void The::setGioiTinh(wstring gioiTinh)
{
	this->gioiTinh = gioiTinh;
}
wstring The::getGioiTinh()
{
	return this->gioiTinh;
}
void The::setDiaChi(wstring diaChi) {
	this->diaChi = diaChi;
}
wstring The::getDiaChi()
{
	return this->diaChi;
}
void The::setSoTaiKhoan(wstring soTaiKhoan) {
	this->soTaiKhoan = soTaiKhoan;
}
wstring The::getSoTaiKhoan()
{
	return soTaiKhoan;
}
void The::setMatKhau(wstring matKhau) {
	this->matKhau = matKhau;
}
wstring The::getMatKhau() {
	return matKhau;
}
void The::setMaPin(wstring maPin) {
	this->maPin = maPin;
}
wstring The::getMaPin() {
	return maPin;
}
void The::setNgaySinh()
{
	this->ngaySinh = ngaySinh;
}
wstring The::getNgaySinh()
{
	return ngaySinh;
}
void The::setSoDu(long long soDu) {
	this->soDu = soDu;
}
long long The::getSoDu() {
	return soDu;
}
void The::setSoDuTietKiem(long long soDuTietKiem) {
	this->soDuTietKiem = soDuTietKiem;
}
long long The::getSoDuTietKiem() {
	return soDuTietKiem;
}


void The::setMaBank(wstring maBank)
{
	this->maBank = maBank;
}
wstring The::getMaBank()
{
	return this->maBank;
}