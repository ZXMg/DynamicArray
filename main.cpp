#include <iostream>
#include "DynamicArray.h"

using namespace std;

int main()
{
    int num;
    cout << "输入数组数量：";
    cin >> num;
    DynamicArray a(num);
    cout << "\n输入数组元素：";
    for(int i = 0; i < num; i++)
            cin >> a[i];
    cout << "\n插入排序之后的情况" << endl;
    int b = a.insertSort();
    for(int i = 0; i < num; i ++)
        cout << a[i] << " ";
    cout <<endl;
    int c = a.binarySearch(10);
    cout << "\n查找的数（如：10）的位置：" << c <<endl;
}
