#include <iostream>
#include "Time.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");

    int min1, sec1;
    cout << "������� ����� (������ � �������): ";
    cin >> min1 >> sec1;

    Time time1(min1, sec1);
    Time time2;
    cout << "������� ����� (������ � �������): ";
    cin >> time2;
  
    cout << "������ �����: " << time1 << endl;
    cout << "������ �����: " << time2 << endl;

    bool equal = time1 == time2;
    if (equal)
        cout << "����� ����������" << endl;
    else
        cout << "����� �� ����������" << endl;

    cout << "������� ������ �������� � ������� �������: ";
    int sec_add;
    cin >> sec_add;

    Time time3 = time1 + sec_add;
    cout << "������ �����: " << time3 << endl;

    bool notequal = time2 != time3;
    cout << "��������� ��������� ������� � �������� �������" << endl;
    if (notequal)
        cout << "����� �� ����������" << endl;
    else
        cout << "����� ����������" << endl;

    Time time4 = time3;
    cout << "��������� ����� (��������� ������������) ";
    cout << time4;
}
