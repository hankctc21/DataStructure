#pragma once
#include "QSInterface.h"
#include <sstream>

using namespace std;

class QS : public QSInterface
{
public:
    QS();
    ~QS()
    {
        clear();
    }
    void sortAll();
    int medianOfThree(int left, int right);
    int partition(int left, int right, int pivotIndex);
    string getArray() const;
    int getSize() const;
    bool addToArray(int value);
    bool createArray(int capacity);
    void clear();
    void print();
    void sort(int left, int right);
private:
    int* array_pointer;
    int the_array[];
    int array_size;
    int max_array_size;
    bool current_array;
  
};