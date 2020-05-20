#include <iostream>
#include "Time.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");

    int min1, sec1;
    cout << "Введите время (минуты и секунды): ";
    cin >> min1 >> sec1;

    Time time1(min1, sec1);
    Time time2;
    cout << "Введите время (минуты и секунды): ";
    cin >> time2;
  
    cout << "Первое время: " << time1 << endl;
    cout << "Второе время: " << time2 << endl;

    bool equal = time1 == time2;
    if (equal)
        cout << "Время одинаковое" << endl;
    else
        cout << "Время не одинаковое" << endl;

    cout << "Сколько секунд добавить к первому времени: ";
    int sec_add;
    cin >> sec_add;

    Time time3 = time1 + sec_add;
    cout << "Третье время: " << time3 << endl;

    bool notequal = time2 != time3;
    cout << "Результат сравнения второго и третьего времени" << endl;
    if (notequal)
        cout << "Время не одинаковое" << endl;
    else
        cout << "Время одинаковое" << endl;

    Time time4 = time3;
    cout << "Четвертое время (результат присваивания) ";
    cout << time4;
}
