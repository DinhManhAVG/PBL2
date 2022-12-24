#pragma once
#include"HashTable.h"
#include"HashTableBank.h"
class HashTableThe : public HashTable<The>
{
public:
	HashTableThe()
	{

	}
	bool add(wstring key, Node<The>* p)
	{
		int hashValueIndex = hashFunction(key);
		bool check = true;
		Node<The>* k = buckets[hashValueIndex].head;
		while (k)
		{
			if (k->data.getSoTaiKhoan() == key)
			{
				check = false;
				gotoXY(30, 15);
				wcout << L"Số tài khoản đã tồn tại! ";
				break;
			}
			k = k->next;

		}
		if (check)
			buckets[hashValueIndex].Insert_Back(p);
		return check;
	}
	void remove(wstring key)
	{
		int hashValueIndex = hashFunction(key);
		int i = 0;
		for (Node<The>* k = buckets[hashValueIndex].head; k != NULL; k = k->next)
		{
			if (k->data.getSoTaiKhoan() == key)
			{
				gotoXY(30, 8);
				wcout << L"Đã xóa số tài khoản " << k->data.getSoTaiKhoan() << L" thành công!" << endl;
				buckets[hashValueIndex].deleteNode(i);
				gotoXY(30, 9);
				system("pause");
				system("cls");
				break;
			}
			i++;
		}
	}
	void napTienUser(wstring key, long long soTien)
	{
		int hashValueIndex = hashFunction(key);
		for (Node<The>* k = buckets[hashValueIndex].head; k != NULL; k = k->next)
		{
			if (k->data.getSoTaiKhoan() == key)
			{
				k->data.setSoDu(k->data.getSoDu() + soTien);
			}
		}
	}
	bool checkDeleteBank(wstring key) {
		int hashValueIndex = hashFunction(key);
	}
	Node<The>* get(wstring key)
	{
		int hashValueIndex = hashFunction(key);
		for (Node<The>* k = buckets[hashValueIndex].head; k != NULL; k = k->next)
		{
			if (k->data.getSoTaiKhoan() == key)
			{
				return k;
			}
		}
		return NULL;
	}
	void xuatHashTable()
	{
		Bank bank;
		HashTableBank htbank;
		htbank.docFile();
		wcout << setw(9) << left << L"Số tài khoản\t"  << setw(9) << left << L"Mật khẩu\t" <<setw(6) << left <<L"Mã pin\t"<< setw(9) << left << L"Họ và tên\t" << setw(10) << left << L"Giới tính\t" << setw(10) << left << L"Ngày sinh\t" << setw(16) << left << L"Địa chỉ\t" << setw(10) << left << L"Số dư\t" << setw(19) << left << L"Tên ngân hàng" << endl;
		for (int i = 0; i < SIZE; i++)
		{
			for (Node<The>* k = buckets[i].head; k != NULL; k = k->next)
			{
				bank = htbank.get(k->data.getMaBank())->getNode();
				wcout << setw(9) << left << k->data.getSoTaiKhoan() << L"\t" << setw(15) << left << k->data.getMatKhau() << L"\t"  << setw(6) << left << k->data.getMaPin() << L"\t" << setw(9) << left << k->data.getHoVaTen() << L"\t" << setw(10) << left << k->data.getGioiTinh() << L"\t" << setw(10) << left << k->data.getNgaySinh() << L"\t" << setw(10) << left << k->data.getDiaChi() << L"\t" << setw(10) << left << k->data.getSoDu() << L"\t" << setw(10) << left << bank.getTenBank() << endl;
			}
		}
	}
	bool checkSTK(wstring key)
	{
		int hashValueIndex = hashFunction(key);
		for (Node<The>* k = buckets[hashValueIndex].head; k != NULL; k = k->next)
		{
			if (k->data.getSoTaiKhoan() == key)
			{
				return true;
			}
		}
		return false;
	}
	bool checkAccount(wstring acc, wstring pass)
	{
		int hashValueIndex = hashFunction(acc);
		for (Node<The>* k = buckets[hashValueIndex].head; k != NULL; k = k->next)
		{
			if (k->data.getSoTaiKhoan() == acc && k->data.getMatKhau() == pass)
			{
				return true;
			}
		}
		return false;
	}
	bool checkLoginATM(wstring acc, wstring maPin)
	{
		int hashValueIndex = hashFunction(acc);
		for (Node<The>* k = buckets[hashValueIndex].head; k != NULL; k = k->next)
		{
			if (k->data.getSoTaiKhoan() == acc && k->data.getMaPin() == maPin)
			{
				return true;
			}
		}
		return false;
	}
	void timKiemNguoiNhan(wstring soTaiKhoanNguoiChuyen, wstring soTaiKhoanNguoiNhan, int soTien)
	{
		int hashValueIndex = hashFunction(soTaiKhoanNguoiChuyen);
		bool check = false;
		for (Node<The>* k = buckets[hashValueIndex].head; k != NULL; k = k->next)
		{
			if (k->data.getSoTaiKhoan() == soTaiKhoanNguoiChuyen)
			{
				if (soTien > k->data.getSoDu())
				{
					gotoXY(30, 16);
					wcout << L"Số dư không đủ. Yêu cầu nhập lại" << endl; return;
				}
				else
				{
					int posHash = hashFunction(soTaiKhoanNguoiNhan);
					for (Node<The>* j = buckets[posHash].head; j != NULL; j = j->next)
					{
						if (j->data.getSoTaiKhoan() == soTaiKhoanNguoiNhan)
						{
							check = true;
							j->data.setSoDu(j->data.getSoDu() + soTien);
							k->data.setSoDu(k->data.getSoDu() - soTien);
							break;
						}
					}
				}
			}
		}
		if (check == false)
		{
			gotoXY(30, 16);
			wcout << L"Không tìm thấy số tài khoản này!" << endl;
		}
		else
		{
			gotoXY(30, 16);
			wcout << L"Đã chuyển thành công!" << endl;
		}
	}
	void timKiemNguoiNhanTK(wstring soTaiKhoanNguoiChuyen, wstring soTaiKhoanNguoiNhan, int soTien)
	{
		int hashValueIndex = hashFunction(soTaiKhoanNguoiChuyen);
		bool check = false;
		for (Node<The>* k = buckets[hashValueIndex].head; k != NULL; k = k->next)
		{
			if (k->data.getSoTaiKhoan() == soTaiKhoanNguoiChuyen)
			{
				if (soTien > k->data.getSoDuTietKiem())
				{
					gotoXY(30, 18);
					wcout << L"Số dư không đủ. Yêu cầu nhập lại" << endl; return;
				}
				else
				{
					int posHash = hashFunction(soTaiKhoanNguoiNhan);
					for (Node<The>* j = buckets[posHash].head; j != NULL; j = j->next)
					{
						if (j->data.getSoTaiKhoan() == soTaiKhoanNguoiNhan)
						{
							check = true;
							j->data.setSoDuTietKiem(j->data.getSoDuTietKiem() + soTien);
							k->data.setSoDuTietKiem(k->data.getSoDuTietKiem() - soTien);
							break;
						}
					}
				}
			}
		}
		if (check == false)
		{
			gotoXY(30, 18);
			wcout << L"Không tìm thấy số tài khoản này!" << endl;
		}
		else
		{
			gotoXY(30, 18);
			wcout << L"Đã chuyển thành công!" << endl;
		}
	}
	void timKiemSoDu(wstring soTaiKhoan, int soTien)
	{
		int hashValueIndex = hashFunction(soTaiKhoan);
		for (Node<The>* k = buckets[hashValueIndex].head; k != NULL; k = k->next)
		{
			if (k->data.getSoTaiKhoan() == soTaiKhoan)
			{
				if (soTien > k->data.getSoDu()) {
					wcout << L"Số dư không đủ. Yêu cầu nhập lại" << endl; break;
				}
				else {
					k->data.setSoDu(k->data.getSoDu() - soTien);
					break;
				}
			}
		}
	}
	void timKiemSoDuTietKiem(wstring soTaiKhoan, int soTien)
	{
		int hashValueIndex = hashFunction(soTaiKhoan);
		for (Node<The>* k = buckets[hashValueIndex].head; k != NULL; k = k->next)
		{
			if (k->data.getSoTaiKhoan() == soTaiKhoan)
			{
				if (soTien > k->data.getSoDuTietKiem()) {
					wcout << L"Số dư không đủ. Yêu cầu nhập lại" << endl; break;
				}
				else {
					k->data.setSoDuTietKiem(k->data.getSoDuTietKiem() - soTien);
					break;
				}
			}
		}
	}
	void timKiemNguoiDung(wstring soTaiKhoan, HashTableBank htbank)
	{
		Bank bank;
		int hashValueIndex = hashFunction(soTaiKhoan);
		for (Node<The>* k = buckets[hashValueIndex].head; k != NULL; k = k->next)
		{
			if (k->data.getSoTaiKhoan() == soTaiKhoan)
			{
				bank = htbank.get(k->data.getMaBank())->getNode();
				SetColor(11);
				gotoXY(59, 25);
				wcout << L"Số tài khoản: " << k->data.getSoTaiKhoan() << endl;
				gotoXY(59, 27);
				wcout << L"Mã Pin: " << k->data.getMaPin() << endl;
				gotoXY(59, 29);
				wcout << L"Tên người dùng: " << k->data.getHoVaTen() << endl;
				gotoXY(59, 31);
				wcout << L"Giới tính: " << k->data.getGioiTinh() << endl;
				gotoXY(59, 33);
				wcout << L"Ngày sinh: " << k->data.getNgaySinh() << endl;
				gotoXY(59, 35);
				wcout << L"Địa chỉ: " << k->data.getDiaChi() << endl;
				gotoXY(59, 36);
				wcout << L"Số dư hiện tại: " << k->data.getSoDu() << endl;
				gotoXY(59, 37);
				wcout << L"Số dư tiết kiệm: " << k->data.getSoDuTietKiem() << endl;
				gotoXY(59, 38);
				wcout << L"Tên ngân hàng: " << bank.getTenBank() << endl;
				break;
			}
		}
	}
	void chinhSuaMatKhau(wstring soTaiKhoan, wstring matKhauMoi)
	{
		int hashValueIndex = hashFunction(soTaiKhoan);
		for (Node<The>* k = buckets[hashValueIndex].head; k != NULL; k = k->next)
		{
			if (k->data.getSoTaiKhoan() == soTaiKhoan)
			{
				k->data.setMatKhau(matKhauMoi);
			}
		}
	}
	void sapXepTheoSoTaiKhoan(HashTableBank htbank)
	{
		Bank bank;
		Node<The>* danhSachNode[1000];
		for (int i = 0; i < 1000; i++)
		{
			The the(L"", L"", L"", L"", L"", L"", L"", 0, 0, L"");
			danhSachNode[i] = new Node<The>(the);
		}
		int index = 0;
		for (int i = 0; i < SIZE; i++)
		{
			for (Node<The>* k = buckets[i].head; k != NULL; k = k->next)
			{
				danhSachNode[index] = k;
				index++;
			}
		}
		for (int i = 0; i <= index; i++)
		{
			int vitrimin = i;
			for (int j = i; j < index; j++)
			{
				if (danhSachNode[j]->data.getSoDu() > danhSachNode[vitrimin]->data.getSoDu())
				{
					vitrimin = j;
				}
			}
			The the(L"", L"", L"", L"", L"", L"", L"", 0, 0, L"");
			Node<The>* temp = new Node<The>(the);
			temp = danhSachNode[i];
			danhSachNode[i] = danhSachNode[vitrimin];
			danhSachNode[vitrimin] = temp;
		}
		wcout << setw(26) << left << L"Họ và tên\t" << setw(30) << left << L"Số dư\t" << setw(26) << left << L"Tên ngân hàng\t" << endl;
		for (int i = 0; i < index; i++)
		{
			bank = htbank.get(danhSachNode[i]->data.getMaBank())->getNode();
			wcout << setw(30) << left << danhSachNode[i]->data.getHoVaTen() << L"\t" << setw(30) << left << danhSachNode[i]->data.getSoDu() << L"\t" << setw(30) << left << bank.getTenBank() << endl;
		}
	}
	long long layRaSoDu(wstring soTaiKhoan)
	{
		int hashValueIndex = hashFunction(soTaiKhoan);
		for (Node<The>* k = buckets[hashValueIndex].head; k != NULL; k = k->next)
		{
			if (k->data.getSoTaiKhoan() == soTaiKhoan)
			{
				return k->data.getSoDu();
			}
		}
	}
	void ktraSoDu(wstring soTaiKhoan)
	{
		int hashValueIndex = hashFunction(soTaiKhoan);
		for (Node<The>* k = buckets[hashValueIndex].head; k != NULL; k = k->next)
		{
			if (k->data.getSoTaiKhoan() == soTaiKhoan)
			{
				SetColor(11);
				gotoXY(59, 26);
				wcout << L"Tên người dùng: " << k->data.getHoVaTen() << endl;
				gotoXY(59, 28);
				wcout << L"Số tài khoản: " << k->data.getSoTaiKhoan() << endl;
				gotoXY(59, 30);
				wcout << L"Số dư hiện tại: " << k->data.getSoDu() << endl; break;
			}
		}
	}
	void ktraSoDuTietKiem(wstring soTaiKhoan, HashTableBank htbank)
	{
		Bank bank;
		SetColor(11);
		gotoXY(59, 26);
		int soNam;
		wcout << L"Nhập số năm muốn gửi vào ngân hàng: "; wcin >> soNam;
		int hashValueIndex = hashFunction(soTaiKhoan);
		for (Node<The>* k = buckets[hashValueIndex].head; k != NULL; k = k->next)
		{
			if (k->data.getSoTaiKhoan() == soTaiKhoan)
			{
				bank = htbank.get(k->data.getMaBank())->getNode();
				SetColor(11);
				gotoXY(59, 28);
				wcout << L"Tên người dùng: " << k->data.getHoVaTen() << endl;
				gotoXY(59, 30);
				wcout << L"Số tài khoản: " << k->data.getSoTaiKhoan() << endl;
				gotoXY(59, 32);
				k->data.setSoDuTietKiem(bank.tinhTongSoTienTietKiem(k->data.getSoDuTietKiem(), soNam, bank.getLaiSuat()));
				wcout << L"Số dư tiết kiệm hiện tại: " << k->data.getSoDuTietKiem() << endl; break;
			}
		}
	}
	void doiMaPin(wstring soTaiKhoan, wstring maPinMoi)
	{
		// cần thêm tính năng ẩn mã pin và phải có thêm chức năng xem được mật khẩu 
		int hashValueIndex = hashFunction(soTaiKhoan);
		for (Node<The>* k = buckets[hashValueIndex].head; k != NULL; k = k->next)
		{
			if (k->data.getSoTaiKhoan() == soTaiKhoan)
			{
				k->data.setMaPin(maPinMoi);
			}
		}
	}
	void ghiFile()
	{
		wofstream output(L"The.txt");
		locale utf8_locale(locale(), new codecvt_utf8<wchar_t>);
		output.imbue(utf8_locale);
		output << L'\xFEFF';
		for (int i = 0; i < SIZE; i++)
		{
			if (buckets[i].head != NULL || buckets[i].tail != NULL)
			{
				for (Node<The>* k = buckets[i].head; k != NULL; k = k->next)
					output << k->data.getSoTaiKhoan() << L" | " << k->data.getMatKhau() << L" | " << k->data.getMaPin() << L" | " << k->data.getHoVaTen() << L" | " << k->data.getGioiTinh() << L" | " << k->data.getNgaySinh() << L" | " << k->data.getDiaChi() << L" | " << k->data.getSoDu() << L" | " << k->data.getSoDuTietKiem() << L" | " << k->data.getMaBank() << L" |||" << endl;
			}
		}
		output.close();
	}
	bool docFile()
	{
		wstring str[2000];
		std::wifstream input(L"The.txt");
		locale utf8_locale(locale(), new codecvt_utf8<wchar_t>);
		input.imbue(utf8_locale);
		wchar_t bom = L'\0';
		input.get(bom);
		wstring s;
		int n = 0;
		int count = 0;
		while (input >> s)
		{
			if (count != 10) {

				++count;
			}
			else {

				count = 0;

				input.get(bom);

			}
			str[n] = s;
			n++;
		}
		input.close();
		if (count == 0 && n == 0)
			return false;
		int temp = 0;
		wstring stk, mk, mp, hvt, gt, ns, dc, mb;
		long long sd = 0, sdtk = 0;
		for (int i = 0; i < n; i++)
		{
			if (str[i] == L"|" && temp != 9)
			{
				temp++;
			}
			else if (temp == 9)
			{
				mb = str[i];
				i++;
				temp = 0;
				The the(stk, mk, mp, hvt, gt, ns, dc, sd, sdtk, mb);
				Node<The>* p = new Node<The>(the);
				add(p->data.getSoTaiKhoan(), p);
				if (str[i] == L"|||")
				{
					stk = L"";
					mk = L"";
					mp = L"";
					hvt = L"";
					gt = L"";
					ns = L"";
					dc = L"";
					sd = 0;
					sdtk = 0;
					mb = L"";
				}
				continue;
			}

			else if (str[i] != L"|" && temp == 0)
			{
				stk = str[i];
			}
			else if (str[i] != L"|" && temp == 1)
			{
				mk = str[i];
			}
			else if (str[i] != L"|" && temp == 2)
			{
				mp = str[i];
			}
			else if (str[i] != L"|" && temp == 3)
			{
				while (str[i] != L"|")
				{
					hvt = hvt + str[i] + L" ";
					i++;
				}
				hvt.pop_back();
				i--;
			}
			else if (str[i] != L"|" && temp == 4)
			{
				while (str[i] != L"|")
				{
					gt = gt + str[i] + L" ";
					i++;
				}
				gt.pop_back();
				i--;
			}
			else if (str[i] != L"|" && temp == 5)
			{
				ns = str[i];
			}
			else if (temp == 6)
			{
				while (str[i] != L"|")
				{
					dc = dc + str[i] + L" ";
					i++;
				}
				dc.pop_back();
				--i;
			}

			else if (str[i] != L"|" && temp == 7)
			{
				sd = sd + stoll(str[i]);
			}
			else if (str[i] != L"|" && temp == 8)
			{
				sdtk = sdtk + stoll(str[i]);
			}
		}
		return true;
	}
};