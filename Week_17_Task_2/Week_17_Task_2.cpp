// Week_17_Task_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Написать функцию, удаляющую столбец двухмерного массива по указанному номеру

#include <iostream>

int** AddColumArray(int** Array, int rows, int &cols, int* arr, int pos);
int** DellColumArray(int** Array, int rows, int &cols, int pos);
int** init_array(int rows, int cols);
void complate_array(int** Array, int rows, int cols);
void print_array(int** Array, int rows, int cols);

using namespace std;
int main()
{
    using namespace std;
    int rows = 5;
    int cols = 5;
    int** Array1;
    Array1 = init_array(rows, cols);
    int Array2[5] = { 0 };

    complate_array(Array1, rows, cols);
    print_array(Array1, rows, cols);
    cout << endl;
    int** Array3;

    int position = 3;

    Array3 = DellColumArray(Array1, rows, cols, position - 1);

    print_array(Array3, rows, cols);

    
}

int** init_array(int rows, int cols) {
    int** pparr = new int* [rows];
    for (int i = 0; i < rows; i++) {
        pparr[i] = new int[cols];
    };
    return pparr;
}

void complate_array(int** Array, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            Array[i][j] = rand() % 10;
        }
    }
}

void print_array(int** Array, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << Array[i][j] << " ";
        }
        cout << endl;
    }
}

int** AddColumArray(int** Array, int rows, int& cols, int* arr, int pos) {

    int** new_arr = new int* [rows];
    for (int i = 0; i < rows; i++) {
        new_arr[i] = new int[cols + 1];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < pos; j++) {
            new_arr[i][j] = Array[i][j];
        };
    }
    for (int i = 0; i < cols; i++) {
        new_arr[i][pos] = arr[i];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = pos + 1; j < cols + 1; j++) {
            new_arr[i][j] = Array[i][j - 1];
        };
    }
    cols++;
    return new_arr;

}
int** DellColumArray(int** Array, int rows, int &cols, int pos) {

    int** new_arr = new int* [rows];
    for (int i = 0; i < rows; i++) {
        new_arr[i] = new int[cols - 1];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < pos; j++) {
            new_arr[i][j] = Array[i][j];
        };
    }
    for (int i = 0; i < rows; i++) {
        for (int j = pos; j < cols - 1; j++) {
            new_arr[i][j] = Array[i][j + 1];
        };
    }
    cols--;
    return new_arr;
}