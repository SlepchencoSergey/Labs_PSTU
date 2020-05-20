#include <iostream>
#include "product.h"

int main()
{
    setlocale(LC_ALL, "rus");

    product prod1("Изделие 1");
    prod1.print();

    product prod2("Изделие 2", "444g", 10);
    prod2.print();
}
