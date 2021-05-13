#include "QS.h"
	
	void QS::sortAll() {
	    cout << "in sortAll" << endl;
	}

	int QS::medianOfThree(int left, int right) {
	    cout << "in medianOfThree" << endl;
	}

	int QS::partition(int left, int right, int pivotIndex) {
	    cout << "in partition" << endl;
	}

	string QS::getArray() const {
	    cout << "in getArray" << endl;
	    if (arraySize == 0) {
	        return "";
	    }
        stringstream s;
        for (int i = 0; i < arraySize; i++) {
            if (i != 0) {
                s << ",";
            }
            s << QSarray[i];
        }
        return s.str();
	}

	int QS::getSize() const {
	    cout << "in getSize" << endl;
	    return arraySize;
	}

	bool QS::addToArray(int value) {
	    cout << "in addToArray" << endl;
	    if (QSarray == NULL) {
	        return false;
	    }
	    if (arraySize >= arrayCapacity) {
	        return false;
	    }
        QSarray[arraySize] = value;
        arraySize++;
        return true;
	}

	bool QS::createArray(int capacity) {
	    cout << "in createArray" << endl;
	    if (capacity <= 0) {
	        return false;
	    }
        if (QSarray != NULL) {
        	delete QSarray;
        }
        arrayCapacity = capacity;
        arraySize = 0;
        QSarray = new int[capacity];
        return true;
	}

	void QS::clear() {
	    cout << "in clear" << endl;
	    arraySize = 0;
	    arrayCapacity = 0;
	}