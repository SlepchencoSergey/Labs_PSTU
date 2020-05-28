#include <iostream>
#include <fstream>
using namespace std;

const int nm = 4;


int a[nm][nm];
int n;

void makebase(int ik, int jk)
{
    int i, j;
    for (i = 0; i < n; i++) if (a[i][jk] >= 0) a[i][jk] = -1;
    for (j = 0; j < n; j++) if (a[ik][j] >= 0) a[ik][j] = -1;
    a[ik][jk] = -2;
}

void print()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] < 0)
                cout << "нн";
            else
                cout << a[i][j];
            cout << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void main()
{
    setlocale(LC_ALL, "rus");

    int i, j, c, i2, j2, i3, j3;
    int cnt;
    int minv, miniv, minjv, maxv;
    int flag;
    ifstream f("matrix.txt");
    f >> n;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            f >> a[i][j];
    f.close();

    for (i = 0; i < n; i++)
        a[i][i] = -1;

    print();

    for (c = 0; c < n; c++)
    {
        // looking for one-in-row or one-in-col element
        flag = 0;
        for (i = 0; (i < n) && (flag == 0); i++)
        {
            cnt = 0;
            for (j = 0; j < n; j++) if (a[i][j] >= 0)
            {
                i2 = i;
                j2 = j;
                cnt++;
            }
            if (cnt == 1) flag = 1;
        }
        for (j = 0; (j < n) && (flag == 0); j++)
        {
            cnt = 0;
            for (i = 0; i < n; i++) if (a[i][j] >= 0)
            {
                i2 = i;
                j2 = j;
                cnt++;
            }
            if (cnt == 1) flag = 1;
        }
        if (flag == 1)
        {
            makebase(i2, j2);
            print();
            continue;
        }

        // minus mins
        for (i = 0; i < n; i++)
        {
            minv = 30000;
            for (j = 0; j < n; j++)
                if ((a[i][j] >= 0) && (a[i][j] < minv))
                    minv = a[i][j];
            for (j = 0; j < n; j++)
                if (a[i][j] >= 0)
                    a[i][j] -= minv;
            print();
        }
        for (j = 0; j < n; j++)
        {
            minv = 30000;
            for (i = 0; i < n; i++)
                if ((a[i][j] >= 0) && (a[i][j] < minv)) minv = a[i][j];
            for (i = 0; i < n; i++) if (a[i][j] >= 0) a[i][j] -= minv;
        }

        // checking nulls and looking for base values

        maxv = -1;
        for (i = 0; i < n; i++) for (j = 0; j < n; j++) if (a[i][j] == 0)
        {
            miniv = 30000;
            minjv = 30000;
            for (i2 = 0; i2 < n; i2++) if ((a[i2][j] >= 0) && (i2 != i) && (a[i2][j] < miniv)) miniv = a[i2][j];
            for (j2 = 0; j2 < n; j2++) if ((a[i][j2] >= 0) && (j2 != j) && (a[i][j2] < minjv)) minjv = a[i][j2];
            if (miniv + minjv > maxv)
            {
                maxv = miniv + minjv;
                i3 = i;
                j3 = j;
            }
        }

        print();
        makebase(i3, j3);
        print();
    }

    i2 = 0;

    for (c = 0; c < n; c++)
    {
        for (j = 0; j < n; j++)
            if (a[c][j] == -2)
            {
                cout << "->" << j + 1;
                i2 = j;
                break;
            }
    }

}
