	#include "QS.h"

/*
* sortAll()
*
* Sorts elements of the array.  After this function is called, every
* element in the array is less than or equal its successor.
*
* Does nothing if the array is empty.
*/
void QS::sortAll() {
    if (getSize() == 0) {
        return;
    }
    //int middle = medianOfThree(0, getSize() - 1);
    //int middle = (0 + getSize() - 1)/2;
    recursiveSortAll(0, getSize() - 1, medianOfThree(0, getSize() - 1));
    //partition(0, getSize()-1, middle);
    
    recursiveSortAll(0, getSize() - 1, medianOfThree(0, getSize() - 1));
    recursiveSortAll(0, getSize() - 1, medianOfThree(0, getSize() - 1));
    for (int i = 0; i < getSize(); i++) {
        if (i != 0) {
            if (values[i] < values[i-1]) {
                swap(values[i], values[i-1]);
            }
        }
    }
}

void QS::recursiveSortAll(int left, int right, int pivit) {
    int returnValue = partition(left, right, pivit);
    if (returnValue == -1) {
        return;
    }
    else {
        return recursiveSortAll(left, returnValue - 1, medianOfThree(left, returnValue - 1));
        return recursiveSortAll(returnValue + 1, right, medianOfThree(returnValue + 1, right));
    }
}

/*
* medianOfThree()
*
* The median of three pivot selection has two parts:
*
* 1) Calculates the middle index by averaging the given left and right indices:
*
* middle = (left + right)/2
*
* 2) Then bubble-sorts the values at the left, middle, and right indices.
*
* After this method is called, data[left] <= data[middle] <= data[right].
* The middle index will be returned.
*
* Returns -1 if the array is empty, if either of the given integers
* is out of bounds, or if the left index is not less than the right
* index.
*
* @param left
* 		the left boundary for the subarray from which to find a pivot
* @param right
* 		the right boundary for the subarray from which to find a pivot
* @return
*		the index of the pivot (middle index); -1 if provided with invalid input
*/
int QS::medianOfThree(int left, int right) {
    if(getSize() == 0 || left >= right || left < 0 || right >= getSize()) {
        return -1;
    }
    int middle = (left + right)/2;
    int temp = 0;
    if (values[middle] < values[left]) {
        swap(values[middle], values[left]);
    }
    if (values[middle] > values[right]) {
        swap(values[middle], values[right]);
    }
    if (values[middle] < values[left]) {
        swap(values[middle], values[left]);
    }
    //cout << middle << endl;
    return middle;
}

void QS::swap(int &first, int &second) {
    int temp = first;
    first = second;
    second = temp;
}

/*
* Partitions a subarray around a pivot value selected according to
* median-of-three pivot selection.  Because there are multiple ways to partition a list,
* we will follow the algorithm on page 611 of the course text when testing this function.
*
* The values which are smaller than the pivot should be placed to the left
* of the pivot; the values which are larger than the pivot should be placed
* to the right of the pivot.
*
* Returns -1 if the array is null, if either of the given integers is out of
* bounds, or if the first integer is not less than the second integer, or if the
* pivot is not within the sub-array designated by left and right.
*
* @param left
* 		the left boundary for the subarray to partition
* @param right
* 		the right boundary for the subarray to partition
* @param pivotIndex
* 		the index of the pivot in the subarray
* @return
*		the pivot's ending index after the partition completes; -1 if
* 		provided with bad input
*/
int QS::partition(int left, int right, int pivotIndex) {
    if (getSize() == 0 || left < 0 || right >= getSize() || left >= right || pivotIndex > right || pivotIndex < left || pivotIndex < 0) {
        return -1;
    }
    swap(values[left], values[pivotIndex]);
    int up = left + 1;
    int down = right;
    do {
        while ((up != right) && !(values[left] < values[up])) {
            up++;
        }
        while (values[left] < values[down]) {
            --down;
        }
        if (up < down) {
            swap(values[up], values[down]);
        }
    } while (up < down);
    swap(values[left], values[down]);
    return down;
}

/*
* Produces a comma delimited string representation of the array. For example: if my array
* looked like {5,7,2,9,0}, then the string to be returned would look like "5,7,2,9,0"
* with no trailing comma.  The number of cells included equals the number of values added.
* Do not include the entire array if the array has yet to be filled.
*
* Returns an empty string, if the array is NULL or empty.
*
* @return
*		the string representation of the current array
*/
string QS::getArray() const {
    if (values == NULL || getSize() == 0) {
        return("");
    }
    ostringstream stream;
    stream.flush();
   
    for (int i = 0; i < getSize(); i++) {
        if (i < getSize() - 1) {
            stream << values[i] << ",";
        }
        else {
            stream << values[i];
        }
    }
    string str = stream.str();
    return str;
}

/*
* Returns the number of elements which have been added to the array.
*/
int QS::getSize() const {
    return arraySize;
}

/*
* Adds the given value to the end of the array starting at index 0.
* For example, the first time addToArray is called,
* the give value should be found at index 0.
* 2nd time, value should be found at index 1.
* 3rd, index 2, etc up to its max capacity.
*
* If the array is filled, do nothing.
* returns true if a value was added, false otherwise.
*/
bool QS::addToArray(int value) {
    if (timesAddCalled >= arrayCapacity) {
        return false;
    }
    else {
        values[timesAddCalled] = value;
        timesAddCalled++;
        arraySize++;
        return true;
    }
}

/*
* Dynamically allocates an array with the given capacity.
* If a previous array had been allocated, delete the previous array.
* Returns false if the given capacity is non-positive, true otherwise.
*
* @param
*		size of array
* @return
*		true if the array was created, false otherwise
*/
bool QS::createArray(int capacity) {
    if (capacity < 0) {
        return false;
    }
    if (values != NULL) {
        clear();
    }
    values = new int[capacity];
    arrayCapacity = capacity;
    return true;
}

/*
* Resets the array to an empty or NULL state.
*/
void QS::clear() {
    timesAddCalled = 0;
	arraySize = 0;
	arrayCapacity = 0;
	delete[] values;
	values = NULL;
}
