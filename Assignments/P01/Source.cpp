#include <iostream>
#include "myVector.h"
using namespace std;

int main() {
	//create new vector with 10 size
	myVector w = myVector(10);
	//instantly try to pop
	w.pop();

	//push 3 specified values
	w.push(13);
	w.push(31);
	w.push(73);

	//add 10000 values to vector
	for (int i = 0; i < 10000; i++){
		w.push(1);
	}
	//print size of memory allocated
	cout << w.getMemory() << endl;
	//print number of values in vector
	cout << w.getCount() << endl;

	//remove 9998 items from vector
	for (int i = 0; i < 9998; i++) {
		w.pop();
	}
	//print size of memory allocated
	cout << w.getMemory() << endl;
	//print number of values in vector
	cout << w.getCount() << endl;

	//print values in the vector
	w.printExisting();

	system("pause");
}
