#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;

#define SIZE 6

int main()
{
    setlocale(LC_ALL, "rus");

    int a[SIZE][SIZE]; // матрица связей
    int d[SIZE]; // минимальное расстояние
    int v[SIZE]; // посещенные вершины
    int temp, minindex, min;
    int begin_index = 1;

    ifstream file("matrix.txt");
   
    // Инициализация матрицы связей
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++) {
            file >> a[i][j];
        }
    }
    file.close();

    // Вывод матрицы связей
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            cout << a[i][j] << "\t";
        cout << endl;
    }
    //Инициализация вершин и расстояний
    for (int i = 0; i < SIZE; i++)
    {
        d[i] = 10000;
        v[i] = 1;
    }
    d[begin_index] = 0;
    // Шаг алгоритма
    do {
        minindex = 10000;
        min = 10000;
        for (int i = 0; i < SIZE; i++)
        { // Если вершину ещё не обошли и вес меньше min
            if ((v[i] == 1) && (d[i] < min))
            { // Переприсваиваем значения
                min = d[i];
                minindex = i;
            }
        }
        // Добавляем найденный минимальный вес
        // к текущему весу вершины
        // и сравниваем с текущим минимальным весом вершины
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
    // Вывод кратчайших расстояний до вершин
    cout << "\nКратчайшие расстояния до вершин:" << endl;
    for (int i = 0; i < SIZE; i++)
        cout << d[i] << "\t";

    // Восстановление пути
    int ver[SIZE]; // массив посещенных вершин
    int endPoint;
    cout << "\nВведите номер вершины до которой найти кратчайший путь ";
    cin >> endPoint;
    int end = endPoint - 1; // индекс конечной вершины = 5 - 1
    ver[0] = end + 1; // начальный элемент - конечная вершина
    int k = 1; // индекс предыдущей вершины
    int weight = d[end]; // вес конечной вершины

    while (end != begin_index) // пока не дошли до начальной вершины
    {
        for (int i = 0; i < SIZE; i++) // просматриваем все вершины
            if (a[i][end] != 0)   // если связь есть
            {
                int temp = weight - a[i][end]; // определяем вес пути из предыдущей вершины
                if (temp == d[i]) // если вес совпал с рассчитанным
                {                 // значит из этой вершины и был переход
                    weight = temp; // сохраняем новый вес
                    end = i;       // сохраняем предыдущую вершину
                    ver[k] = i + 1; // и записываем ее в массив
                    k++;
                }
            }
    }
    // Вывод пути (начальная вершина оказалась в конце массива из k элементов)
    cout << "\nВывод кратчайшего пути" << endl;
    for (int i = k - 1; i >= 0; i--)
       cout << ver[i] << "  ";
}