#include <iostream>
#include <ctime>
using namespace std;
const int SIZE = 15;

//������� �������������� � �������� ����
void podgotovSort(int* arr, int n, int i);
//������� ������������� ����������
void pyramidSort(int* arr, int n);

int main()
{
    setlocale(LC_ALL, "rus");
    int* massive = new int[SIZE];
    int minDiaposon = 0, maxDiaposon = 100;

    cout << "�������� ������:" << endl;
    srand(time(0));
    //�������� ������ ���������� �������:
    for (int i = 0; i < SIZE; i++)
    {
        massive[i] = minDiaposon + rand() % (maxDiaposon - minDiaposon + 1);
        //������ �������� ������� �� �����:
        cout << massive[i] << " ";
    }

    //������� ������� ����������:
    pyramidSort(massive, SIZE);

    //������ ��������������� �������� �������:
    cout << endl << "������������ ������:" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << massive[i] << " ";
    }
    system("pause");
    return 0;
}


void podgotovSort(int* arr, int n, int i)
{
    int biggest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[biggest])
    {
        biggest = left;
    }
    if (right < n && arr[right] > arr[biggest])
    {
        biggest = right;
    }
    if (biggest != i)
    {
        int newValue = arr[i];
        arr[i] = arr[biggest];
        arr[biggest] = newValue;
        
        podgotovSort(arr, n, biggest);
    }
}


void pyramidSort(int* arr, int n)
{
    for (int i = (n / 2 - 1); i >= 0; i--)
        podgotovSort(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        int newValue = arr[0];
        arr[0] = arr[i];
        arr[i] = newValue;
        podgotovSort(arr, i, 0);
    }
}