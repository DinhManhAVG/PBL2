#pragma once
#include"HashTable.h"
class HashTableAdmin : public HashTable<Admin>
{
public:
	HashTableAdmin()
	{

	}
	bool add(wstring key, Node<Admin>* p)
	{
		int hashValueIndex = hashFunction(key);
		bool check = true;
		Node<Admin>* k = buckets[hashValueIndex].head;
		while (k)
		{
			if (k->data.getMaAdmin() == key)
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
		for (Node<Admin>* k = buckets[hashValueIndex].head; k != NULL; k = k->next)
		{
			if (k->data.getMaAdmin() == key)
			{
				buckets[hashValueIndex].deleteNode(i);
			}
			i++;
		}
	}
	Node<Admin>* get(wstring key)
	{
		int hashValueIndex = hashFunction(key);
		for (Node<Admin>* k = buckets[hashValueIndex].head; k != NULL; k = k->next)
		{
			if (k->data.getMaAdmin() == key)
			{
				return k;
			}
		}
		return NULL;
	}
	void xuatHashTable()
	{
		for (int i = 0; i < SIZE; i++)
		{
			for (Node<Admin>* k = buckets[i].head; k != NULL; k = k->next)
			{
				wcout << k->data.getMaAdmin() << L" | " << k->data.getMatKhauAdmin() << L" | " << k->data.getTenAdmin() << L" | " << k->data.getNgaySinh()  << L" |||" << endl;
			}
		}
	}
	bool checkAccount(wstring acc, wstring pass)
	{
		int hashValueIndex = hashFunction(acc);
		for (Node<Admin>* k = buckets[hashValueIndex].head; k != NULL; k = k->next)
		{
			if (k->data.getMaAdmin() == acc && k->data.getMatKhauAdmin() == pass)
			{
				return true;
			}
		}
		return false;
	}
	void chinhSuaMatKhau(wstring maAdmin, wstring matKhauMoi)
	{
		int hashValueIndex = hashFunction(maAdmin);
		for (Node<Admin>* k = buckets[hashValueIndex].head; k != NULL; k = k->next)
		{
			if (k->data.getMaAdmin() == maAdmin)
			{
				k->data.setMatKhauAdmin(matKhauMoi);
			}
		}
	}
	void ghiFile()
	{
		wofstream output(L"Admin.txt");
		locale utf8_locale(locale(), new codecvt_utf8<wchar_t>);
		output.imbue(utf8_locale);
		output << L'\xFEFF';
		for (int i = 0; i < SIZE; i++)
		{
			if (buckets[i].head != NULL || buckets[i].tail != NULL)
			{
				for (Node<Admin>* k = buckets[i].head; k != NULL; k = k->next)
					output << k->data.getMaAdmin() << L" | " << k->data.getMatKhauAdmin() << L" | " << k->data.getTenAdmin() << L" | " << k->data.getNgaySinh() << L" |||" << endl;

			}
		}
		output.close();
	}
	bool docFile()
	{
		wstring str[2000];
		std::wifstream input(L"Admin.txt");
		locale utf8_locale(locale(), new codecvt_utf8<wchar_t>);
		input.imbue(utf8_locale);
		wchar_t bom = L'\0';
		input.get(bom);
		wstring s;
		int n = 0;
		int count = 0;
		while (input >> s)
		{
			if (count != 4) {

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
		wstring tk, mk, t, ns;
		for (int i = 0; i < n; i++)
		{
			if (str[i] == L"|" && temp != 3)
			{
				temp++;
			}
			else if (temp == 3)
			{
				ns = str[i];
				i++;
				temp = 0;
				Admin admin(tk, mk, t, ns);
				Node<Admin>* p = new Node<Admin>(admin);
				add(p->data.getMaAdmin(), p);
				if (str[i] == L"|||")
				{
					tk = L"";
					mk = L"";
					t = L"";
					ns = L"";
				}
				continue;
			}

			else if (str[i] != L"|" && temp == 0)
			{
				tk = str[i];
			}
			else if (str[i] != L"|" && temp == 1)
			{
				mk = str[i]; 
			}

			else if (str[i] != L"|" && temp == 2)
			{
				while (str[i] != L"|")
				{
					t = t + str[i] + L" ";
					i++;
				}
				t.pop_back();
				i--;
			}
			
		}
		return true;
	}
};
