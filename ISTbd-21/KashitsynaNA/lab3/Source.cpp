#include <iostream>
#include <ctime>
using namespace std;
const int SIZE = 15;

//������� ���������� ������� �����
void hoarSort(int* arr, int leftBorder, int rightBorder);

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
    hoarSort(massive, 0, (SIZE-1));

    //������ ��������������� �������� �������:
    cout << endl << "������������ ������:" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << massive[i] << " ";
    }
    system("pause");
    return 0;
}


void hoarSort(int* arr, int leftBorder, int rightBorder)
{
    int leftElem = leftBorder, rightElem = rightBorder;
    int newArr = arr[(leftBorder + rightBorder) / 2];

    do
    {
        while (arr[leftElem] < newArr)
        {
            leftElem++;
        }

        while (arr[rightElem] > newArr)
        {
            rightElem--;
        }

        if (leftElem <= rightElem)
        {
            if (arr[leftElem] > arr[rightElem])
            {
                int newValue = arr[leftElem];
                arr[leftElem] = arr[rightElem];
                arr[rightElem] = newValue;
            }
            leftElem++;
            rightElem--;
        }
    } while (leftElem <= rightElem);

    if (leftElem < rightBorder)
        hoarSort(arr, leftElem, rightBorder);
    if (rightElem > leftBorder)
        hoarSort(arr, leftBorder, rightElem);
}