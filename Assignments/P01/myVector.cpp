#include <iostream>
#include "myVector.h"

using namespace std;

//Constructor
myVector::myVector(int size) {
	nextEmpty = 0;
	arraySize = size;
	originalSize = size;
	theVector = new int[arraySize];
	//just so we have stuff to print!!!!!
	for (int i = 0; i<arraySize; i++) {
		theVector[i] = 0;
	}
}

//prints the whole vector, including "empty" slots
void myVector::printWhole() {
	for (int i = 0; i<arraySize; i++) {
		cout << theVector[i] << " ";
	}
}

//prints the used portion of the vector, omitting "empty" slots
void myVector::printExisting() {
	for (int i = 0; i<nextEmpty; i++) {
		cout << theVector[i] << " ";
	}
}

//add a variable to the array
void myVector::push(int i) {
	//if pushing onto a full array
	if (nextEmpty > arraySize) {
		theVector = expandArray();
	}
	theVector[nextEmpty] = i;
	nextEmpty++;
}

//laugh at them when they try to push a string
void myVector::push(string i) {
	cout << "You cannot add strings to the vector.";
}

//take a variable from the array
int myVector::pop() {
	if (nextEmpty == 0) { cout << "nothing to return. (returned false)" << endl; return false; }
	nextEmpty--;
	int popvalue = theVector[nextEmpty];
	theVector[nextEmpty] = 0;
	//if we need to shrink it
	if (((nextEmpty - 1) / (double)arraySize) <= 0.4 && arraySize>originalSize)
	{
		theVector = shrinkArray();
	}
	return popvalue;

}

//expand the array
int* myVector::expandArray() {
	int *newArray;
	int newSize = (int)(arraySize * 1.5);
	newArray = new int[newSize];
	//Initialize new array with zeros
	//for printing purposes
	for (int i = 0; i<newSize; i++) {
		newArray[i] = 0;
	}
	//copying old array into new
	for (int i = 0; i <= arraySize; i++) {
		newArray[i] = theVector[i];
	}

	arraySize = newSize;
	//return the pointer to the new array
	return newArray;
}

//expand the array
int* myVector::shrinkArray() {
	int *newArray;
	int newSize = arraySize/2;
	//set minimum on the size
	if (newSize < originalSize){
		newSize = originalSize;
	}
	newArray = new int[newSize];
	//Initialize new array with zeros
	//for printing purposes
	for (int i = 0; i<newSize; i++) {
		newArray[i] = 0;
	}
	//copying old array into new
	for (int i = 0; i < nextEmpty; i++) {
		newArray[i] = theVector[i];
	}

	arraySize = newSize;
	//return the pointer to the new array
	return newArray;
}

int myVector::getCount(){
	return nextEmpty;
}

int myVector::getMemory() {
	return arraySize;
}