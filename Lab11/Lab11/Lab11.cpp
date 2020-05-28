#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;

#define SIZE 6

int main()
{
    setlocale(LC_ALL, "rus");

    int a[SIZE][SIZE]; // ������� ������
    int d[SIZE]; // ����������� ����������
    int v[SIZE]; // ���������� �������
    int temp, minindex, min;
    int begin_index = 1;

    ifstream file("matrix.txt");
   
    // ������������� ������� ������
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++) {
            file >> a[i][j];
        }
    }
    file.close();

    // ����� ������� ������
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            cout << a[i][j] << "\t";
        cout << endl;
    }
    //������������� ������ � ����������
    for (int i = 0; i < SIZE; i++)
    {
        d[i] = 10000;
        v[i] = 1;
    }
    d[begin_index] = 0;
    // ��� ���������
    do {
        minindex = 10000;
        min = 10000;
        for (int i = 0; i < SIZE; i++)
        { // ���� ������� ��� �� ������ � ��� ������ min
            if ((v[i] == 1) && (d[i] < min))
            { // ��������������� ��������
                min = d[i];
                minindex = i;
            }
        }
        // ��������� ��������� ����������� ���
        // � �������� ���� �������
        // � ���������� � ������� ����������� ����� �������
        if (minindex != 10000)
        {
            for (int i = 0; i < SIZE; i++)
            {
                if (a[minindex][i] > 0)
                {
                    temp = min + a[minindex][i];
                    if (temp < d[i])
                    {
                        d[i] = temp;
                    }
                }
            }
            v[minindex] = 0;
        }
    } while (minindex < 10000);
    // ����� ���������� ���������� �� ������
    cout << "\n���������� ���������� �� ������:" << endl;
    for (int i = 0; i < SIZE; i++)
        cout << d[i] << "\t";

    // �������������� ����
    int ver[SIZE]; // ������ ���������� ������
    int endPoint;
    cout << "\n������� ����� ������� �� ������� ����� ���������� ���� ";
    cin >> endPoint;
    int end = endPoint - 1; // ������ �������� ������� = 5 - 1
    ver[0] = end + 1; // ��������� ������� - �������� �������
    int k = 1; // ������ ���������� �������
    int weight = d[end]; // ��� �������� �������

    while (end != begin_index) // ���� �� ����� �� ��������� �������
    {
        for (int i = 0; i < SIZE; i++) // ������������� ��� �������
            if (a[i][end] != 0)   // ���� ����� ����
            {
                int temp = weight - a[i][end]; // ���������� ��� ���� �� ���������� �������
                if (temp == d[i]) // ���� ��� ������ � ������������
                {                 // ������ �� ���� ������� � ��� �������
                    weight = temp; // ��������� ����� ���
                    end = i;       // ��������� ���������� �������
                    ver[k] = i + 1; // � ���������� �� � ������
                    k++;
                }
            }
    }
    // ����� ���� (��������� ������� ��������� � ����� ������� �� k ���������)
    cout << "\n����� ����������� ����" << endl;
    for (int i = k - 1; i >= 0; i--)
       cout << ver[i] << "  ";
}