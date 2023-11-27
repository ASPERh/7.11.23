﻿#include <iostream>
using namespace std;

void AddRow(int**& array, int& rows, int columns, int rowIndex) 
{
    int** newArray = new int* [rows + 1];

    for (int i = 0; i < rowIndex; ++i) 
    {
        newArray[i] = new int[columns];
        for (int j = 0; j < columns; ++j) 
        {
            newArray[i][j] = array[i][j];
        }
    }
    newArray[rowIndex] = new int[columns] {0, 0, 0, 0};
    for (int i = rowIndex + 1; i <= rows; ++i) 
    {
        newArray[i] = new int[columns];
        for (int j = 0; j < columns; ++j) 
        {
            newArray[i][j] = array[i - 1][j];
        }
    }
    ++rows;
    array = newArray;
}

void AddColumn(int**& array, int rows, int& columns, int columnIndex) 
{
    int** newArray = new int* [rows];
    for (int i = 0; i < rows; ++i) 
    {
        newArray[i] = new int[columns + 1];
    }
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < columnIndex; ++j) 
        {
            newArray[i][j] = array[i][j];
        }
        newArray[i][columnIndex] = (array[i][columnIndex - 1] + 1) % 10;
        for (int j = columnIndex + 1; j <= columns; ++j) 
        {
            newArray[i][j] = array[i][j - 1];
        }
    }

    ++columns;
    array = newArray;
}

int main() 
{
    setlocale(LC_ALL, "Russian");
    int rows = 4;
    int columns = 4;
    int** ar = new int* [rows];
    for (int y = 0; y < rows; y++) 
    {
        ar[y] = new int[columns];
        for (int x = 0; x < columns; x++) 
        {
            ar[y][x] = y * columns + x + 1;
        }
    }

    cout << "До:\n";
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < columns; ++j) 
        {
            cout << ar[i][j] << ' ';
        }
        cout << '\n';
    }

    int rowIndex;
    cout << "\nВведите где будет новый ряд: ";
    cin >> rowIndex;
    AddRow(ar, rows, columns, rowIndex);

    cout << "\nПосле:\n";
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < columns; ++j) 
        {
            cout << ar[i][j] << ' ';
        }
        cout << '\n';
    }

    int columnIndex;
    cout << "\nВведите где будет новая столбец: ";
    cin >> columnIndex;
    AddColumn(ar, rows, columns, columnIndex);

    cout << "\nПосле:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) 
        {
            cout << ar[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}