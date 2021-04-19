#ifndef LIST_H
#define LIST_H

struct Elem
{
	int data; // ������
	Elem* next, * prev;
};

class List
{
public:

	// ������, �����
	Elem* Head, * Tail;
	// ���������� ���������
	int Count;


	// �����������
	List();

	// ����������
	~List();

	// �������� ����������
	int getCount();

	// ������� ���� ������
	void delAll();
	// �������� ��������, ���� �������� �� �����������,
	// �� ������� ��� �����������
	void del(int pos = 0);
	// ������� ��������, ���� �������� �� �����������,
	// �� ������� ��� �����������
	void insert(int pos = 0);
	// �����������
	void intersection(List&, List&);
	// �����������
	void merge(List&, List&);

	// ���������� � ����� ������
	void addTail(int n);

	// ���������� � ������ ������
	void addHead(int n);

	// ������ ������
	void print();
	// ������ ������������� ��������
	void print(int pos);
	// ����������
	void sort_info();
};

#endif // LINKEDLIST_H