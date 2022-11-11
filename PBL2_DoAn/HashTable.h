#pragma once
#include"List.h"
#include"The.h"
#include"Admin.h"
#define SIZE 307
template <typename T>
class HashTable
{
protected:
	List<T> buckets[SIZE];
	int hashFunction(wstring key)
	{
		int sum = 0, index = 0;
		for (int i = 0; i < key.length(); i++)
			sum += key[i];
		index = sum % SIZE;
		return index;
	}
public:
	virtual void add(wstring key, Node<T>* p) = 0;
	virtual void remove(wstring key) = 0;
	virtual Node<T>* get(wstring key) = 0;
	virtual void xuatHashTable() = 0;
	virtual void ghiFile() = 0;
	virtual void docFile() = 0;

};
