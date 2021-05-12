#include "QS.h"


    void QS::sortAll() {
        int middle = -1;
        int pivot = -1;
        
        middle = medianOfThree(0, currentSize - 1);
        pivot = partition(0, currentSize - 1, middle);
        
        
    }
	int QS::medianOfThree(int left, int right) {
		int middle = -1;
		int temp = -1;
		
		if (currentSize != 0 && left < right 
			&& (left >= 0 && left <= currentSize) 
			&& (right >= 0 && right <= currentSize)) {
			middle = (left + right) / 2;
			if (myArray[left] > myArray[middle]) {
				temp = myArray[left];
				myArray[left] = myArray[middle];
				myArray[middle] = temp;
			}
			if (myArray[middle] > myArray[right]) {
				temp = myArray[middle];
				myArray[middle] = myArray[right];
				myArray[right] = temp;
			}
			if (myArray[left] > myArray[middle]) {
				temp = myArray[left];
				myArray[left] = myArray[middle];
				myArray[middle] = temp;
			}
		    return middle;
		}
		return -1;
	}
	int QS::partition(int left, int right, int pivotIndex) {
		int temp = -1;
		int middleIndex = -1;
		int up = -1;
		int down = -1;
		int upTemp = -1;
		int downTemp = -1;
		
		cout << "Pivot index: " << pivotIndex << endl;
		//middleIndex = medianOfThree(left, right);
		
		temp = myArray[left];
		myArray[left] = myArray[pivotIndex];
		myArray[pivotIndex] = temp;
		
		up = left + 1;
		down = right;
		upTemp = left + 1;
		downTemp = right;
		cout << left << " " << right << endl;
		do {
			//cout << "Up: " << up << "			 Down: " << down << endl;
			//cout << "Up Array: " << myArray[up] << "		 Down Array: " << myArray[down] << endl;
			if (myArray[up] > myArray[down]) {
				//cout << "up is bigger than down" << endl;
				temp = myArray[up];
				myArray[down] = myArray[up];
				myArray[up] = temp;
			} 	
			if (myArray[up] <= myArray[left]) {
				up++;	
			}
			if (myArray[down] > myArray[left]) {
				down--;	
			}
		} while (up < down);
		
		temp = myArray[left];
		myArray[left] = myArray[down];
		myArray[down] = temp;
		
		
	    return down;
	}
	string QS::getArray() const {
		stringstream ss;
		for(int i = 0; i < currentSize; i++) {
			ss << myArray[i];
			if (i != currentSize - 1) {
				ss << ",";
			}
		}
	    return ss.str();
	}
	int QS::getSize() const {
	    return currentSize;
	}
	bool QS::addToArray(int value) {
		if (currentSize >= finalSize) {
			return false;
		}
		myArray[currentSize] = value;
		currentSize++;
		return true;
	}
	bool QS::createArray(int capacity) {
		if (capacity > 0) {
			clear();
			finalSize = capacity;
			myArray = new int[capacity]();
			//int *array = new int[size];
			for (int i = 0; i < finalSize; i++) {
				//myArray = NULL;
			}
			cout << myArray[0] << endl;
			return true;
		}
		return false;
	}
	void QS::clear() {
		myArray = NULL;
		delete []myArray;
		currentSize = 0;
		finalSize = 0;
	}


// medianOfThree Instead of bubblesort, do two if statements  if first is greater than middle, swap them ...





//cout << array.size();
		
		/*
		array[index] = value;
		index++;
		*/


/*
	bool QS::createArray(int capacity) {
		if (capacity > 0) {
			clear();
			arraySize = capacity;
			array = new int[capacity];
			return true;
		}
		return false;
	}
	void QS::clear() {
		delete array;
		array = NULL;
	}
*/


//array = 0;
		
	    //for (int i = 0; i < arraySize; i++) {
	    	//delete array.at(i);
	    	//delete[] array;
	    	//array[i] = 0;
	    //}
	    
	    
	    
	    
	    /*
	    arraySize = capacity;
		clear();
		if (capacity > 0) {
			array = new int[capacity];
	    	return true;	
		}
		return false;
	    */