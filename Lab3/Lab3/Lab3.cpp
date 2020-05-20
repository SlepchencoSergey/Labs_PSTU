#include <iostream>
#include "Pair.h"
#include "Ellipse.h"

void change(Pair* p)
{
    p->set_first(p->get_first() + 1);
    p->set_second(p->get_second() + 1);
}

Pair* create(int k)
{
    Pair* p = nullptr;
    int first = rand() % 50 + 5;
    int second = rand() % 50 + 5;

    if (k == 1)
        p = new Pair(first, second);
    else
        p = new Ellipse(first, second);

    return p;
}

int main()
{
    setlocale(LC_ALL, "rus");

    Pair p1;
    cout << "¬ведите два числа: ";
    cin >> p1;

    Ellipse el1;
    cout << "¬ведите длины большой и малой полуоси: ";
    cin >> el1;

    cout << "ѕара чисел: " << p1 << endl;
    cout << "Ёллипс: " << el1 << endl;

    change(&p1);
    change(&el1);

    cout << "ѕара чисел: " << p1 << endl;
    cout << "Ёллипс: " << el1 << endl;

    Pair* p2 = create(1);
    p2->print();
    Pair* el2 =  create(2);
    el2->print();
}
