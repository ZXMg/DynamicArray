#include "DynamicArray.h"
#include <cstring>
#include <cmath>

DynamicArray::DynamicArray(int number):size(number)
{
    if(number != 0)
        ptr = new int[number];
    else
        ptr = NULL;
}

DynamicArray::DynamicArray(DynamicArray& a)
{
    if(!a.ptr)
    {
        ptr = NULL;
        size = 0;
        return;
    }
    ptr = new int[a.size];
    memcpy(ptr, a.ptr, sizeof(int) * a.size);
    size = a.size;
}

DynamicArray& DynamicArray::operator=(const DynamicArray& a)
{
    if(ptr == a.ptr)
        return *this;
    if(a.ptr == NULL)
    {
        if(ptr)
            delete[] ptr;
        ptr = NULL;
        size = 0;
        return *this;
    }
    if(size < a.size)
    {
        if(ptr)
            delete[] ptr;
        ptr = new int[a.size];
    }
    memcpy(ptr, a.ptr, sizeof(int) * a.size);
    size = a.size;
    return *this;
}

int DynamicArray::bubbleSort()
{
    int i, j, temp;
    for (j = 0; j < size - 1; j++)
        for (i = 0; i < size - 1 - j; i++)
        {
            if(ptr[i] > ptr[i + 1])
            {
                temp = ptr[i];
                ptr[i] = ptr[i + 1];
                ptr[i + 1] = temp;
            }
        }
    return 1;
}

int DynamicArray::selectSort()
{
    int i, j, min, temp;
    for (i = 0; i < size - 1; i++){
        min = i;
        for (j = i + 1; j < size; j++)
            if (ptr[j] < ptr[min])
                min = j;
        temp = ptr[i];
        ptr[i] = ptr[min];
        ptr[min] = temp;
    }
    return 1;
}

int DynamicArray::insertSort()
{
    int i, j, temp;
    for(i = 1; i < size - 1; i++)
    {
        temp = ptr[i];
        j = i - 1;
        while((j >= 0) && (ptr[j] > temp))
        {
            ptr[j+1]=ptr[j];
            j--;
        }
        if(j != i - 1)
        {
            ptr[j + 1] = temp;
        }
    }
    return 1;
}

int DynamicArray::shellSort()
{
    int gap, i, j, temp;
    for(gap = size / 2; gap > 0; gap /= 2)
    {
        for(i = gap; i < size; i++)
        {
            for(j = i - gap; j >= 0 && ptr[j] > ptr[j + gap];j -= gap)
            {
                temp = ptr[j];
                ptr[j] = ptr[j + gap];
                ptr[j + gap] = temp;
            }
        }
    }
    return 1;
}

int DynamicArray::directSearch(int a)
{
    int i;
    for(i = 0; i < size; i++)
    {
        if(ptr[i] == a)
            return i + 1;
    }
    return -1;
}

int DynamicArray::binarySearch(int a)
{
    int b = this->insertSort();
    int low = 0;
    int high = size - 1;
    int mid;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(ptr[mid] > a)
            high = mid - 1;
        else if(ptr[mid] < a)
            low = mid + 1;
        else
            return mid + 1;
    }
    return -1;
}

DynamicArray::~DynamicArray()
{
    if(ptr != NULL)
    {
        delete[] ptr;
        ptr = NULL;
    }
    size = 0;
}
