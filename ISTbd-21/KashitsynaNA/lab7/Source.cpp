#include <iostream>
using namespace std;

//������� ����������� ������ ������
void moving(char firstPoint, char secondPoint);
//������� ����������� ���� �����
void towerMoving(int count, char firstPoint, char secondPoint, char freePoint);

int main()
{
	setlocale(LC_ALL, "rus");
	int count;
	cout << "��������� �����. ����� 3 ������� - �, �, �." << endl << "���������� ����� �� ������� � �� �������� �." << endl;
	cout << "������� ���������� �����: "; cin >> count;
	cout << endl << "��������:" << endl;
	towerMoving(count, '�', '�', '�');
	return 0;
}

void moving(char firstPoint, char secondPoint)
{
	cout << "�� ������� " << firstPoint << " � �������� " << secondPoint << endl;
}

void towerMoving(int count, char firstPoint, char secondPoint, char freePoint)
{
	if (count == 0) { return; } //���� ���������� ������ ����� 0, �� ������ �� �������

	towerMoving(count - 1, firstPoint, freePoint, secondPoint);
	moving(firstPoint, secondPoint);
	towerMoving(count - 1, freePoint, secondPoint, firstPoint);
}