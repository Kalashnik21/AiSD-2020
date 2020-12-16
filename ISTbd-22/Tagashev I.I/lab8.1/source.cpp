#include <iostream>
#include "list.h"

int main()
{
	setlocale(LC_ALL, "RUS");

	std::cout << "���� ������." << std::endl;

	List<int>* list1 = new List<int>;
	list1->print_list();
	unsigned long var = 5;
	unsigned long var2 = 1;
	unsigned long var3 = 2;
	unsigned long var4 = 7;

	std::cout << "��������� ��-� " << var << std::endl;
	list1->append(var);
	std::cout << "��������� ��-� " << var2 << std::endl;
	list1->append(var2);
	std::cout << "��������� ��-� " << var3 << std::endl;
	list1->append(var3);
	std::cout << std::endl;

	std::cout << "������ ������:" << std::endl;
	list1->print_list();
	std::cout << std::endl;

	std::cout << "��������� ��-� " << var4 << " �� ������ �����" << std::endl;
	list1->insert(var4, 3);

	std::cout << "������ ������:" << std::endl;
	list1->print_list();
	std::cout << std::endl;

	std::cout << "������� ��-� � ������� " << 2 << std::endl;
	list1->delete_ind(2);

	std::cout << "������ ������:" << std::endl;
	list1->print_list();
	std::cout << std::endl;

	std::cout << "������ ��������� ������:" << std::endl;
	list1->print_list_reverse();
	std::cout << std::endl;

	std::cout << "������ �������� ��-�� " << var3 << " ����� " << list1->search_ind(var3) << std::endl;

	std::cout << "���-�� ��-��: " << std::endl << list1->get_size() << std::endl;

	list1->properties_list();

	std::cout << "�������� ������" << std::endl;
	list1->delete_front();
	std::cout << "������ ������:" << std::endl;
	list1->print_list();

}