#pragma once
#include"My_lib.h"
using namespace std;

template <typename T>
class Node
{
public:
	T data;
	Node<T>* next;
	inline Node()
	{
		next = nullptr;
	}
	inline Node(T data)
	{
		this->data = data;
		this->next = nullptr;
	}
	T getNode()
	{
		return data;
	}
};

template <typename T>
class List
{
private:
	Node<T>* head;
	Node<T>* tail;
public:
	friend class HashTableUser;
	friend class HashTableBank;
	friend class HashTableAdmin;
	List()
	{
		head = tail = nullptr;
	}
	~List()
	{

	}
	void Insert_Back(Node<T>* p)
	{
		if (head == nullptr)
		{
			head = tail = p;
			return;
		}
		else
		{
			tail->next = p;
			tail = p;
		}
	}
	void deleteNode(int index)
	{
		if (head == NULL)
		{
			wcout << L"List empty!";
			return;
		}
		int count = 0;
		for (Node<T>* k = head; k != NULL; k = k->next)
		{
			count++;
		}
		if (count < index)
		{
			wcout << L"Index is out of range!";
			return;
		}
		Node<T>* temp = head;
		if (index == 1 || head->next == NULL)
		{
			head = head->next;
			delete temp;
			return;
		}
		if (count == index)
		{
			for (Node<T>* k = head; k != NULL; k = k->next)
			{
				if (k->next = tail)
				{
					delete tail;
					k->next = NULL;
					tail = k;
					return;
				}
			}
		}
		int i = 1;
		for (Node<T>* k = head; k != NULL; k = k->next)
		{
			if (index == i)
			{
				Node<T>* g = k->next;
				k->next = g->next;
				delete g;
				return;
			}
			i++;
		}
	}
};