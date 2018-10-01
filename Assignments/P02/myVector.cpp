#include <iostream>
#include "myVector.h"
#include <string>

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
void myVector::push_back(int i) {
	//if push_backing onto a full array
	if (nextEmpty > arraySize) {
		theVector = expandArray();
	}
	theVector[nextEmpty] = i;
	nextEmpty++;
}

//laugh at them when they try to push_back a string
void myVector::push_back(string i) {
	cout << "X";
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
	int newSize = arraySize / 2;
	//set minimum on the size
	if (newSize < originalSize) {
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

int myVector::getCount() {
	return nextEmpty;
}

int myVector::getMemory() {
	return arraySize;
}

int myVector::operator [](int i) {
	return theVector[i];
}

ostream& operator<<(ostream& os, myVector& vec) {
	for (int i = 0; i < vec.nextEmpty; i++)
	{
		os << vec[i] << ", ";
	}
	return os;
}

myVector myVector::operator +(myVector v) {
	
	if (this->arraySize >= v.arraySize) {
		myVector tempVector(this->arraySize);
		int j = 0;
		for (int i = 0; i < v.arraySize; i++) {
			tempVector.push_back(this->theVector[i]+v[i]);
			j = i;
		}
		for (int i = j; i < this->arraySize; i++) {
			tempVector.push_back(this->theVector[i]);
		}
		return tempVector;
	}
	else {
		myVector tempVector(v.arraySize);
		int j = 0;
		for (int i = 0; i < this->arraySize; i++) {
			tempVector.push_back(this->theVector[i] + v[i]);
			j = i;
		}
		for (int i = j; i < v.arraySize; i++) {
			tempVector.push_back(v[i]);
		}
		return tempVector;
	}
}

myVector myVector::operator -(myVector v) {

	if (this->arraySize >= v.arraySize) {
		myVector tempVector(this->arraySize);
		int j = 0;
		for (int i = 0; i < v.arraySize; i++) {
			tempVector.push_back(this->theVector[i] - v[i]);
			j = i;
		}
		for (int i = j; i < this->arraySize; i++) {
			tempVector.push_back(this->theVector[i]);
		}
		return tempVector;
	}
	else {
		myVector tempVector(v.arraySize);
		int j = 0;
		for (int i = 0; i < this->arraySize; i++) {
			tempVector.push_back(this->theVector[i] - v[i]);
			j = i;
		}
		for (int i = j; i < v.arraySize; i++) {
			tempVector.push_back(0-v[i]);
		}
		return tempVector;
	}
}

myVector myVector::operator *(myVector v) {

	if (this->arraySize >= v.arraySize) {
		myVector tempVector(this->arraySize);
		int j = 0;
		for (int i = 0; i < v.arraySize; i++) {
			tempVector.push_back(this->theVector[i] * v[i]);
			j = i;
		}
		for (int i = j; i < this->arraySize; i++) {
			tempVector.push_back(0);
		}
		return tempVector;
	}
	else {
		myVector tempVector(v.arraySize);
		int j = 0;
		for (int i = 0; i < this->arraySize; i++) {
			tempVector.push_back(this->theVector[i] * v[i]);
			j = i;
		}
		for (int i = j; i < v.arraySize; i++) {
			tempVector.push_back(0);
		}
		return tempVector;
	}
}

myVector myVector::operator *(int v){
	myVector tempVector(this->arraySize);
	for (int i = 0; i < this->arraySize; i++) {
		tempVector.push_back(this->theVector[i] * v);
	}
	return tempVector;
}

myVector myVector::operator /(myVector v) {

	if (this->arraySize >= v.arraySize) {
		myVector tempVector(this->arraySize);
		int j = 0;
		for (int i = 0; i < v.arraySize; i++) {
			tempVector.push_back(this->theVector[i] / v[i]);
			j = i;
		}
		for (int i = j; i < this->arraySize; i++) {
			tempVector.push_back(0);
		}
		return tempVector;
	}
	else {
		myVector tempVector(v.arraySize);
		int j = 0;
		for (int i = 0; i < this->arraySize; i++) {
			tempVector.push_back(this->theVector[i] / v[i]);
			j = i;
		}
		for (int i = j; i < v.arraySize; i++) {
			tempVector.push_back(0);
		}
		return tempVector;
	}
}

myVector myVector::operator /(int v){
	myVector tempVector(this->arraySize);
	for (int i = 0; i < this->arraySize; i++) {
		tempVector.push_back(this->theVector[i] / v);
	}
	return tempVector;
}

myVector myVector::operator ==(myVector v){
	if (this->arraySize == v.arraySize){
		for (int i = 0; i < this->arraySize; i++) {
			if (this->theVector[i] != v[i]){
				return false;
			}
		}
		return true;
	}
	return false;
}

void myVector::operator =(myVector v){
	int thisthingssize = this->arraySize;
	for (int i = this->arraySize; i > 1; i--){
		//fake this.pop();
		silentpop();
	}
	for (int i = 0; i < v.arraySize; i++) {
		this->push_back(v[i]);
	}
}

void myVector::push_back(int v[], int n) {
	for (int i=0; i < n; i++) {
		this->push_back(v[i]);
	}
}


void myVector::silentpop() {
	if (this->nextEmpty != 0) {
		nextEmpty--;
		int popvalue = theVector[nextEmpty];
		theVector[nextEmpty] = 0;
		//if we need to shrink it
		if (((nextEmpty - 1) / (double)arraySize) <= 0.4 && arraySize > originalSize)
		{
			theVector = shrinkArray();
		}
	
	}
	
}
