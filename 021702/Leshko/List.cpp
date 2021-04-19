#include "List.h"
#include <iostream>
using namespace std;

List::List()
{
	// ���������� ������ ����
	Head = Tail = NULL;
	Count = 0;
}


List::~List()
{
	// ������� ��� ��������
	delAll();
}

void List::addHead(int n)
{
	// ����� �������
	Elem* temp = new Elem;

	// ����������� ���
	temp->prev = 0;
	// ��������� ������
	temp->data = n;
	// ��������� - ������ ������
	temp->next = Head;

	// ���� �������� ����?
	if (Head != 0)
		Head->prev = temp;

	// ���� ������� ������, �� �� ������������ � ������ � �����
	if (Count == 0)
		Head = Tail = temp;
	else
		// ����� ����� ������� - ��������
		Head = temp;

	Count++;
}

void List::addTail(int n)
{
	// ������� ����� �������
	Elem* temp = new Elem;
	// ���������� ���
	temp->next = 0;
	// ��������� ������
	temp->data = n;
	// ���������� - ������ �����
	temp->prev = Tail;

	// ���� �������� ����?
	if (Tail != 0)
		Tail->next = temp;

	// ���� ������� ������, �� �� ������������ � ������ � �����
	if (Count == 0)
		Head = Tail = temp;
	else
		// ����� ����� ������� - ���������
		Tail = temp;

	Count++;
}

void List::sort_info() {
	Elem* t = NULL, * t1;
	int r;
	do {
		for (t1 = Head; t1->next != t; t1 = t1->next)
			if (t1->data > t1->next->data) {
				r = t1->data;
				t1->data = t1->next->data;
				t1->next->data = r;
			}
		t = t1;
	} while (Head->next != t);
}

void List::insert(int pos)
{
	// ���� �������� ����������� ��� ����� 0, �� ����������� ���
	if (pos == 0)
	{
		cout << "Input position: ";
		cin >> pos;
	}

	// ������� �� 1 �� Count?
	if (pos < 1 || pos > Count + 1)
	{
		// �������� �������
		cout << "Incorrect position !!!\n";
		return;
	}

	// ���� ������� � ����� ������
	if (pos == Count + 1)
	{
		// ����������� ������
		int data;
		cout << "Input new number: ";
		cin >> data;
		// ���������� � ����� ������
		addTail(data);
		return;
	}
	else if (pos == 1)
	{
		// ����������� ������
		int data;
		cout << "Input new number: ";
		cin >> data;
		// ���������� � ������ ������
		addHead(data);
		return;
	}

	// �������
	int i = 1;

	// ����������� �� ������ n - 1 ���������
	Elem* Ins = Head;

	while (i < pos)
	{
		// ������� �� ��������,
		// ����� ������� �����������
		Ins = Ins->next;
		i++;
	}

	// ������� �� ��������,
	// ������� ������������
	Elem* PrevIns = Ins->prev;

	// ������� ����� �������
	Elem* temp = new Elem;

	// ������ ������
	cout << "Input new number: ";
	cin >> temp->data;

	// ��������� ������
	if (PrevIns != 0 && Count != 1)
		PrevIns->next = temp;

	temp->next = Ins;
	temp->prev = PrevIns;
	Ins->prev = temp;

	Count++;
}

void List::del(int pos)
{
	// ���� �������� ����������� ��� ����� 0, �� ����������� ���
	if (pos == 0)
	{
		cout << "Input position: ";
		cin >> pos;
	}
	// ������� �� 1 �� Count?
	if (pos < 1 || pos > Count)
	{
		// �������� �������
		cout << "Incorrect position !!!\n";
		return;
	}

	// �������
	int i = 1;

	Elem* Del = Head;

	while (i < pos)
	{
		// ������� �� ��������,
		// ������� ���������
		Del = Del->next;
		i++;
	}

	// ������� �� ��������,
	// ������� ������������ ����������
	Elem* PrevDel = Del->prev;
	// ������� �� ��������, ������� ������� �� ���������
	Elem* AfterDel = Del->next;

	// ���� ������� �� ������
	if (PrevDel != 0 && Count !=

		1)
		PrevDel->next = AfterDel;
	// ���� ������� �� �����
	if (AfterDel != 0 && Count != 1)
		AfterDel->prev = PrevDel;

	// ��������� �������?
	if (pos == 1)
		Head = AfterDel;
	if (pos == Count)
		Tail = PrevDel;

	// �������� ��������
	delete Del;

	Count--;
}

void List::print(int pos)
{
	// ������� �� 1 �� Count?
	if (pos < 1 || pos > Count)
	{
		// �������� �������
		cout << "List !!!\n";
		return;
	}

	Elem* temp;

	// ���������� � ����� �������
	// ������� ���������
	if (pos <= Count / 2)
	{
		// ������ � ������
		temp = Head;
		int i = 1;

		while (i < pos)
		{
			// ��������� �� ������� ��������
			temp = temp->next;
			i++;
		}
	}

	else
	{
		// ������ � ������
		temp = Tail;
		int i = 1;

		while (i <= Count - pos)
		{
			// ��������� �� ������� ��������
			temp = temp->prev;
			i++;
		}
	}
	// ����� ��������
	cout << pos << " element: ";
	cout << temp->data << endl;
}

void List::print()
{
	// ���� � ������ ������������ ��������, �� ��������� �� ����
	// � �������� ��������, ������� � ���������
	if (Count != 0)
	{
		Elem* temp = Head;
		cout << "( ";
		while (temp->next != 0)
		{
			cout << temp->data << ", ";
			temp = temp->next;
		}

		cout << temp->data << " )\n";
	}
}

void List::delAll()
{
	// ���� �������� ��������, ������� �� ������ � ������
	while (Count != 0)
		del(1);
}

int List::getCount()
{
	return Count;
}

void List::intersection(List& L, List& M)
{
	List Result;
	M.sort_info();
	L.sort_info();
	Elem* t = M.Head;
	Elem* p = L.Head;
	while (t != NULL && p != NULL)
	{
		if (t->data == p->data)
		{
			Result.addHead(t->data);
			t = t->next;
			p = p->next;
		}
		else
			if (t->data < p->data)
				t = t->next;
			else
				p = p->next;
	}
	Result.sort_info();
	Result.print();
}

void List::merge(List& L, List& M)
{
	List Result;

	Elem* p, * g;

	for (p = M.Head; p != NULL; p = p->next)
	{
		Result.addHead(p->data);
	}

	for (p = L.Head; p != NULL; p = p->next)
	{
		Result.addHead(p->data);
	}

	int m = 0;
	int counter1;
	for (p = Result.Head; p != NULL; p = p->next)
	{
		m++;
		counter1 = 0;
		for (g = Result.Head; g != NULL; g = g->next)
		{
			if (p->data == g->data)
			{
				counter1++;
			}

		}
		if (counter1 > 1)
		{
			if (p != Result.Head)
			{
				p = p->prev;
				Result.del(m);
				m--;
			}
		}
	}
	Result.sort_info();
	Result.print();
}