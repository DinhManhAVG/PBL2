#pragma once
#include"HashTable.h"
class HashTableBank : public HashTable<Bank>
{
public:
	int sizeArrMB;
	wstring arrayMaBank[100];
	HashTableBank()
	{
		sizeArrMB = 0;
	}
	bool add(wstring key, Node<Bank>* p)
	{
		int hashValueIndex = hashFunction(key);
		bool check = true;
		Node<Bank>* k = buckets[hashValueIndex].head;
		while (k)
		{
			if (k->data.getMaBank() == key)
			{
				check = false;
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
		for (Node<Bank>* k = buckets[hashValueIndex].head; k != NULL; k = k->next)
		{
			if (k->data.getMaBank() == key)
			{
				if (k->data.getSoLuongUser() == 0)
				{
					gotoXY(30, 8);
					wcout << L"Đã xóa ngân hàng " << k->data.getTenBank() << L" thành công!" << endl;
					buckets[hashValueIndex].deleteNode(i);
					gotoXY(30, 9);
					system("pause");
				}
				else
				{
					gotoXY(30, 8);
					wcout << L"Ngân hàng đang tồn tại người dùng! Không thể xóa được!" << endl;
					gotoXY(30, 9);
					system("pause");
				}
				system("cls");
				break;
			}
			i++;
		}
	}
	Node<Bank>* get(wstring key)
	{
		int hashValueIndex = hashFunction(key);
		for (Node<Bank>* k = buckets[hashValueIndex].head; k != NULL; k = k->next)
		{
			if (k->data.getMaBank() == key)
			{
				return k;
			}
		}
		return NULL;
	}
	wstring getTenBank(wstring key)
	{
		int hashValueIndex = hashFunction(key);
		for (Node<Bank>* k = buckets[hashValueIndex].head; k != NULL; k = k->next)
		{
			if (k->data.getMaBank() == key)
			{
				return k->data.getTenBank();
			}
		}
		return NULL;
	}
	void updateSoLuongUser(wstring key)
	{
		int hashValueIndex = hashFunction(key);
		for (Node<Bank>* k = buckets[hashValueIndex].head; k != NULL; k = k->next)
		{
			if (k->data.getMaBank() == key)
			{
				k->data.setSoLuongUser(k->data.getSoLuongUser() + 1);
			}
		}
	}
	void xuatHashTable()
	{
		gotoXY(30, 5);
		for (int i = 0; i < SIZE; i++)
		{
			for (Node<Bank>* k = buckets[i].head; k != NULL; k = k->next)
			{
				wcout << k->data.getMaBank() << L" | " << k->data.getMaAdmin() << L" | " << k->data.getTenBank() << L" | " << k->data.getLaiSuat() << L" | " << k->data.getSoLuongUser() << L" | " << k->data.getDiaDiem() << L" |||" << endl;
			}
		}
	}
	void ghiFile()
	{
		wofstream output(L"Bank.txt");
		locale utf8_locale(locale(), new codecvt_utf8<wchar_t>);
		output.imbue(utf8_locale);
		output << L'\xFEFF';
		for (int i = 0; i < SIZE; i++)
		{
			if (buckets[i].head != NULL || buckets[i].tail != NULL)
			{
				for (Node<Bank>* k = buckets[i].head; k != NULL; k = k->next)
					output << k->data.getMaBank() << L" | " << k->data.getMaAdmin() << L" | " << k->data.getTenBank() << L" | " << k->data.getLaiSuat() << L" | " << k->data.getSoLuongUser() << L" | " << k->data.getDiaDiem() << L" |||" << endl;
			}
		}
		output.close();
	}
	void docFile()
	{
		wstring str[2000];
		std::wifstream input(L"Bank.txt");
		locale utf8_locale(locale(), new codecvt_utf8<wchar_t>);
		input.imbue(utf8_locale);
		wchar_t bom = L'\0';
		input.get(bom);
		wstring s;
		int n = 0;
		int count = 0;
		while (input >> s)
		{
			if (count != 6) {

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
		int temp = 0;
		wstring mad, mb, tb, dd;
		double ls = 0, slUser = 0;
		for (int i = 0; i < n; i++)
		{
			if (str[i] == L"|" && temp != 5)
			{
				temp++;
			}
			else if (temp == 5)
			{
				while (str[i] != L"|||")
				{
					dd = dd + str[i] + L" ";
					i++;
				}
				dd.pop_back();
				temp = 0;
				Bank bank(mad, mb, tb, ls, slUser, dd);
				Node<Bank>* p = new Node<Bank>(bank);
				add(p->data.getMaBank(), p);
				arrayMaBank[sizeArrMB] = mb;
				sizeArrMB++;
				if (str[i] == L"|||")
				{
					mad = L"";
					mb = L"";
					tb = L"";
					ls = 0;
					slUser = 0;
					dd = L"";
				}
				continue;
			}
			else if (str[i] != L"|" && temp == 0)
			{
				mb = str[i];
			}
			else if (str[i] != L"|" && temp == 1)
			{
				mad = str[i];
			}
			else if (str[i] != L"|" && temp == 2)
			{
				while (str[i] != L"|")
				{
					tb = tb + str[i] + L" ";
					i++;
				}
				tb.pop_back();
				i--;
			}
			else if (str[i] != L"|" && temp == 3)
			{
				ls += stod(str[i]);
			}
			else if (str[i] != L"|" && temp == 4)
			{
				slUser = slUser + stoi(str[i]);
			}
		}
	}
};
