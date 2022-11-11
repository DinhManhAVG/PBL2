#include "Bank.h"
Bank::Bank()
{

}
Bank::Bank(wstring maAdmin,wstring maBank, wstring tenBank, double laiSuat,int soLuongUser, wstring diaDiem)
{
	this->maAdmin = maAdmin;
	this->maBank = maBank;
	this->tenBank = tenBank;
	this->laiSuat = laiSuat;
	this->soLuongUser = soLuongUser;
	this->diaDiem = diaDiem;
}
void Bank::setMaAdmin(wstring maAdmin) {
	this->maAdmin = maAdmin;
}
wstring Bank::getMaAdmin() {
	return maAdmin;
}
long long Bank::getSoTienCungCapATM()
{
	return soTienCungCapATM;
}
void Bank::setSoLuongUser(int soLuongUser) {
	this->soLuongUser = soLuongUser;
}
int Bank::getSoLuongUser()
{
	return soLuongUser;
}
void Bank::setMaBank(wstring maBank)
{
	this->maBank = maBank;
}
wstring Bank::getMaBank()
{
	return maBank;
}
void Bank::setTenBank(wstring tenBank)
{
	this->tenBank = tenBank;
}
wstring Bank::getTenBank()
{
	return tenBank;
}
void Bank::setLaiSuat(double)
{
	this->laiSuat = laiSuat;
}
double Bank::getLaiSuat()
{
	return laiSuat;
}
void Bank::setDiaDiem(wstring diaDiem)
{
	this->diaDiem = diaDiem;
}
wstring Bank::getDiaDiem()
{
	return this->diaDiem;
}
long long Bank::tinhTongSoTienTietKiem(long long soDuTietKiem, int soThang, double laiSuat)
{
	return soDuTietKiem * pow(1 + laiSuat, soThang);
}
const Bank& Bank::operator = (const Bank& bank)
{
	this->maAdmin = bank.maAdmin;
	this->maBank = bank.maBank;
	this->tenBank = bank.tenBank;
	this->laiSuat = bank.laiSuat;
	this->soLuongUser = bank.soLuongUser;
	this->diaDiem = bank.diaDiem;
	return *this;
}