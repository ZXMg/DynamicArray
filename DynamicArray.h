#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H


class DynamicArray
{
    public:
        DynamicArray(int a = 0);

        int bubbleSort();
        int selectSort();
        int insertSort();
        int shellSort();

        int directSearch(int);
        int binarySearch(int);

        int& operator[](int i){return ptr[i];}
        DynamicArray& operator=(const DynamicArray&);
        DynamicArray(DynamicArray&);

        virtual ~DynamicArray();
    protected:
    private:
        int *ptr;
        int size;
};

#endif // DYNAMICARRAY_H
