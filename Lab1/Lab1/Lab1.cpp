#include <iostream>
#include "product.h"

int main()
{
    setlocale(LC_ALL, "rus");

    product prod1("������� 1");
    prod1.print();

    product prod2("������� 2", "444g", 10);
    prod2.print();
}
