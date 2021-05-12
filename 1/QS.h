#pragma once
#include "QSInterface.h"
#include <iostream>
#include <sstream>
using namespace std;

class QS : public QSInterface {
public:
    QS() {myArray = NULL; currentSize = 0; finalSize = 0;}
	virtual ~QS() {delete myArray; myArray = NULL;}
    
    void sortAll();
	int medianOfThree(int left, int right);
	int partition(int left, int right, int pivotIndex);
	string getArray() const;
	int getSize() const;
	bool addToArray(int value);
	bool createArray(int capacity);
	void clear();
private:
	int *myArray;
	int currentSize;
	int finalSize;
};