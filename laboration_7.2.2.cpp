#include <iostream>
#include <iomanip>
#include <time.h>


using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j);
void Print(int** a, const int rowCount, const int colCount);
int MaxMinCols(int** a, const int rowCount, const int colCount, int colNo, int max);
int MinCol(int** a, const int colNo, const int rowCount, int rowNo, int min);

int main() {
    srand((unsigned)time(NULL));
    int Low = 1;
    int High = 50;

    int colCount;
    cout << "colCount = "; cin >> colCount;

    int rowCount;
    cout << "rowCount = "; cin >> rowCount;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    Create(a, rowCount, colCount, Low, High, 0, 0);
    Print(a, rowCount, colCount);
    int max = MaxMinCols(a, rowCount, colCount, 0, Low);
    cout << "Max_Min = " << max << endl;

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j)
{
    a[i][j] = Low + rand() % (High - Low + 1);
    if (j < colCount - 1)
        Create(a, rowCount, colCount, Low, High, i, j + 1);
    else if (i < rowCount - 1)
        Create(a, rowCount, colCount, Low, High, i + 1, 0);
}

void Print(int** a, const int rowCount, const int colCount)
{
    cout << endl;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

int MinCol(int** a, const int colNo, const int rowCount, int rowNo, int min)
{
    if (a[rowNo][colNo] < min)
        min = a[rowNo][colNo];
    if (rowNo < rowCount - 1)
        return MinCol(a, colNo, rowCount, rowNo + 1, min);
    return min;
}


int MaxMinCols(int** a, const int rowCount, const int colCount, int colNo, int max)
{
    if (colNo % 2 == 0) {
        int min = MinCol(a, colNo, rowCount, 0, a[0][colNo]);

        if (min > max)
            max = min;
    }

    if (colNo < colCount - 1)
        return MaxMinCols(a, rowCount, colCount, colNo + 1, max);

    return max;
}
