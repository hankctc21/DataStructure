#pragma once

#include "QSInterface.h"
#include <iostream>
#include <sstream> 
#include <string>

using namespace std;

class QS : public QSInterface {
public:

    QS() {QSarray = NULL; arraySize = 0; arrayCapacity = 0;}
    virtual ~QS() {clear();}

	void sortAll();

	int medianOfThree(int left, int right);

	int partition(int left, int right, int pivotIndex);

	string getArray() const;

	int getSize() const;

	bool addToArray(int value);

	bool createArray(int capacity);

	void clear();

protected:
int* QSarray;
int arraySize;
int arrayCapacity;
};