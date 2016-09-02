#include <iostream>
using namespace std;
 
void iniArray(int *arr[])
{
    cout << typeid(arr).name() << endl;    // arr已经退化成int**，即一个二级指针
    int row = sizeof(arr)/sizeof(arr[0]);
    cout << row << endl;
}
 
void initArray(int* arr[], int length)
{
    cout << length << endl;
}
 
int main(void)
{
    int a = 1;
    int b = 2;
    int c = 3;
 
    int* arr[] = {&a, &b, &c};
    cout << sizeof(arr) / sizeof(arr[0]) << endl;    // 会输出3
 
    iniArray(arr);    // 会输出1，因为arr作为参数传入时，已经退化成了int**
                                                                   // 因为这样的原因，所以在用数组作为函数的参数时，通常还会再多加一个参数，
    initArray(arr, sizeof(arr) / sizeof(arr[0]));    // 用来说明数组的长度，就像initArray这样。
 
    return 0;
}