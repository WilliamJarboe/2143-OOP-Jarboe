#include <iostream>
using namespace std;

class myVector {
private:
	//reference variables
	int *theVector;
	int nextEmpty = 0;
	int arraySize;
	int originalSize;

	//dynamically allocating functions that work on push
	//and pop as needed
	int* expandArray();
	int* shrinkArray();

public:
	//constructor
	myVector(int size);
	//publically accessible methods
	void printExisting();
	void printWhole();
	void push(int val);
	void push(string val);//troll
	int pop();
	int getCount();
	int getMemory();

}; 
