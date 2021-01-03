#include <iostream>
#include <fstream>
using namespace std;

//���������� ������� �������� �������
void sliyanieSort(char* nazvanie);

int main()
{
	setlocale(LC_ALL, "rus");
	char nazvanie[] = "Array.txt";
	sliyanieSort(nazvanie);
	cout << "���������� ������� ���������";
	return 0;
}


void sliyanieSort(char* nazvanie)
{
	int first, second; //��������������� �����
	int k = 1, i, j, size = -1;
	fstream fs;
	fstream fs_first, fs_second; //��������������� �����
	fs.open(nazvanie, fstream::in);

	while (fs) 
	{
		fs >> first;
		size++; //���������� �����
	}
	fs.close();

	while (k < size)
	{
		fs.open(nazvanie, fstream::in); //����� ����� �����
		fs_first.open("first.txt", fstream::out);
		fs_second.open("second.txt", fstream::out); //�������� ������ ������

		if (fs) 
		{  
			fs >> first; //����� ������ �����
		}

		while (fs) //���� �� ����
		{
			for (i = 0; i < k && fs; i++) {
				fs_first << first << " ";
				fs >> first;
			}
			for (j = 0; j < k && fs; j++) {
				fs_second << first << " ";
				fs >> first;
			}
		}
		fs.close();
		fs_first.close();
		fs_second.close(); //�������� ������

		fs.open(nazvanie, fstream::out);
		fs_first.open("first.txt", fstream::in);
		fs_second.open("second.txt", fstream::in);
		if (fs_first) {
			fs_first >> first; //����� �����
		}
		if (fs_second) {
			fs_second >> second;
		}

		while (fs_first && fs_second) {
			i = 0;
			j = 0;

			while ((i < k) && (j < k) && (fs_first && fs_second)) { //����� ���������
				if (first < second) {
					fs << first << " ";
					fs_first >> first;
					i++;
				}
				else {
					fs << second << " ";
					fs_second >> second;
					j++;
				}
			}

			while (i < k && fs_first) { //�������� ���������� ����������� �������
				fs << first << " ";
				fs_first >> first;
				i++;
			}
			while (j < k && fs_second) {
				fs << second << " ";
				fs_second >> second;
				j++;
			}
		}

		while (fs_first) { //�������� ���������� ����������������� ��������
			fs << first << " ";
			fs_first >> first;

		}
		while (fs_second) {
			fs << second << " ";
			fs_second >> second;
		}
		fs_second.close();
		fs_first.close();
		fs.close();
		k *= 2;
	}
}