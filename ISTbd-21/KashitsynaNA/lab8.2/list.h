#pragma once
#include <iostream>
#include "Elem.h"
#include "OwnIterator.h"
#include "Generator.h"


class List
{
	Elem* Head;
	Elem* Tail;
	int Count; //���������� ���������

public:
	typedef OwnIterator iterator;
	typedef OwnIterator const_iterator;

	iterator begin()
	{
		return iterator(Head);
	};

	iterator end()
	{
		return iterator(nullptr);
	};

	const_iterator begin() const
	{
		return const_iterator(Head);
	};

	const_iterator end() const
	{
		return const_iterator(nullptr);
	};

	
	List()
	{
		Head = NULL;
		Tail = NULL;
		Count = 0;
	};

	
	//������� ����������
	void Add(long data)
	{
		Elem* temp = new Elem(data, NULL);
		if (Head != NULL) //���� ������ �� ����
		{
			Tail->Next = temp; //�������� ����� ���������� �� ������� ��������
			Tail = temp;
			Count += 1; //����� ����� ������
		}
		else //���� ������ ������
		{
			//���������� ������� ��������� � �������
			Head = Tail = temp;
		}
	};


	//������� ���������� �������� �� �������
	void Insert(long data, int index)
	{
		if (index <= 0 && !(this->Head)) {
			Add(data); ++(this->Count); return;
		}
		Elem* tf = this->Head;
		for (int i = 1; i < index && tf->Next; ++i)
			tf = tf->Next;
		Elem* temp = new Elem(data, tf->Next);
		tf->Next = temp;
		++(this->Count);
	};


	//������� ��������
	void Delete(int x) //x - ������� ���������� ��������
	{
		if ((Head != NULL) && (x < Count) && (x >= 0))
		{
			Elem* temp = Head;
			Elem* helping = Head;

			for (int i = 0; i < x; i++)
			{
				helping = temp; // ���������� �������� temp
				temp = temp->Next;
			}

			if (temp == Head) // ���� ������� ������� ���� ������� ������
			{
				Head = temp->Next;
			}
			else
			{
				helping->Next = temp->Next;
			}
			free(temp);
			Count--; // ��������� ������ ������
		}
	};


	//������ ������� ����������
	void Clear()
	{
		while (Head) {
			Delete(0);
		}
	};
};

