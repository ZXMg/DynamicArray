#include <iostream>
#include "DynamicArray.h"

using namespace std;

int main()
{
    int num;
    cout << "��������������";
    cin >> num;
    DynamicArray a(num);
    cout << "\n��������Ԫ�أ�";
    for(int i = 0; i < num; i++)
            cin >> a[i];
    cout << "\n��������֮������" << endl;
    int b = a.insertSort();
    for(int i = 0; i < num; i ++)
        cout << a[i] << " ";
    cout <<endl;
    int c = a.binarySearch(10);
    cout << "\n���ҵ������磺10����λ�ã�" << c <<endl;
}
