#pragma once
#include "QS.h"

using namespace std;

QS :: QS()
{
    array_size = 0;
    array_pointer = NULL;
    current_array = false;
    max_array_size = 0;
}
void QS :: print()
{
    cout << getArray() << endl;
}
void QS :: sort(int left, int right)
{
    if((right - left) > 0)
    {
        cout << "time for cout's.  Here's the first" << endl;
        int pivot = partition(left, right, left);
        //sort first half
        cout << "just before first sort" << endl;
        if(pivot != right)
        {
            sort(left, pivot);
        }
        else
        {
            sort(left, pivot - 1);
            //cout << "NNNNNNNNNNNNNNNOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO" << endl;
        }
        //sort second half
        cout << "after first sort, before second" << endl;
        sort(pivot + 1, right);
        cout << "after second sort " << endl;
    }
}
void QS :: sortAll()
{
    int left = 0;
    int right = array_size - 1;
    sort(left, right);
}
int QS :: medianOfThree(int left, int right)
{
    int middle_index = (left + right)/2;
    if(array_size == 0 || left >= right || (left < 0 || left > (array_size - 1)) || (right < 0 || right > (array_size - 1)))
    {
        return -1;
    }
    int temp;
    int* arrayptr = array_pointer;
    int middle = (right + left) / 2;
    if(*(arrayptr + left) > *(arrayptr + middle))
    {
        temp = *(arrayptr + left);
        *(arrayptr + left) = *(arrayptr + middle);
        *(arrayptr + middle) = temp;
    }
    if(*(arrayptr + middle) > *(arrayptr + right))
    {
        temp = *(arrayptr + middle);
        *(arrayptr + middle) = *(arrayptr + right);
        *(arrayptr + right) = temp;
    }
    if(*(arrayptr + left) > *(arrayptr + middle))
    {
        temp = *(arrayptr + left);
        *(arrayptr + left) = *(arrayptr + middle);
        *(arrayptr + middle) = temp;
    }
    
    return middle;
}
int QS :: partition(int left, int right, int pivotIndex)
{
    if(array_size == 0 || left < 0 || left > (array_size - 1) || right <= left || right < 0 || right > (array_size - 1) || pivotIndex < left || pivotIndex > right)
    {
        return -1;
    }
    int temp = *(array_pointer + left);
    int up = left + 1;
    int down = right;
    *(array_pointer + left) = *(array_pointer + pivotIndex);
    *(array_pointer + pivotIndex) = temp;
    int pivot = left;
    while(up < down)
    {
        cout << "currently up = " << up << " and down = " << down << endl;
        while(*(array_pointer + down) > *(array_pointer + pivot) && up < down)
        {
            down--;
        }
        while(*(array_pointer + up) <= *(array_pointer + pivot) && up < down)
        {
            up++;
        }
        if(up < down)
        {
            temp = *(array_pointer + up);
            *(array_pointer + up) = *(array_pointer + down);
            *(array_pointer + down) = temp;
        }
    }
    if(*(array_pointer + up) <= *(array_pointer + pivot))
    {
        temp = *(array_pointer + pivot);
        *(array_pointer + pivot) = *(array_pointer + up);
        *(array_pointer + up) = temp;
        pivot = up;
    }
    return pivot;
    /*
    cout << "left = " << left << " right = " << right << " pivotIndex = " << pivotIndex << " Start of partition: " << endl;
    print();
    *(array_pointer + left) = *(array_pointer + pivotIndex);
    print();
    *(array_pointer + pivotIndex) = temp;
    print();
    cout << "end the swap" << endl;
    int up = left + 1; // I'm not sure this should be plus one here
    int down = right;
    int pivot = left;
    while(*(array_pointer + down) > *(array_pointer + pivot) && down > up)
    {
        down--;
    }
    if(*(array_pointer + down) < *(array_pointer + pivot))
    {
        int temporary = *(array_pointer + pivot);
        *(array_pointer + pivot) = *(array_pointer + down);
        *(array_pointer + down) = temporary;
        pivot = down;
    }
    */
    /*while(up < down)
    {
        up++;
        if(*(array_pointer + up) < *(array_pointer + pivot))
        {
            cout << "up = " << up << " down = " << down << " pivot = " << pivot << endl;
            print();
            temp = *(array_pointer + up);
            *(array_pointer + up) = *(array_pointer + (pivot + 1));
            print();
            *(array_pointer + (pivot + 1)) = *(array_pointer + pivot);
            print();
            *(array_pointer + pivot) = temp;
            print();
            pivot++;
        }
    }*/
    //return pivot;
    
}
string QS :: getArray() const
{
    if(!current_array || array_size == 0)
    {
        return "";
    }
    stringstream return_val;
    string stuff = "does this even show up?";
    for(int i = 0; i < array_size - 1; i++)
    {
        return_val << *(array_pointer + i) << ",";
        stuff = return_val.str();
    }
    return_val << *(array_pointer + (array_size - 1));
    stuff = return_val.str();
    return return_val.str();
}
int QS :: getSize() const
{
    return array_size;
}
bool QS :: addToArray(int value)
{
    if(max_array_size > array_size)
    {
        *(array_pointer + array_size) = value;
        array_size++;
        return true;
    }
    return false;
    
}
bool QS :: createArray(int capacity)
{
    if(current_array)
    {
        clear();
    }
    
    if(capacity > 0)
    {
        array_pointer = new int[capacity];
        max_array_size = capacity;
        current_array = true;
        return true;
    }
    else return false;
}
void QS :: clear()
{
    if(current_array)
    {
        delete array_pointer;
    }
    array_pointer = NULL;
    current_array = false;
    array_size = 0;
    max_array_size = 0;
}