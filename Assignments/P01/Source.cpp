#include <iostream>
#include "myVector.h"
using namespace std;

int main() {
	//create new vector with 10 size
	myVector w = myVector(10);
	//instantly try to pop
	w.pop();

	//push 3 specified values
	cout << "pushing 13" << endl;
	w.push(13);
	cout << "pushing 31" << endl;
	w.push(31);
	cout << "pushing 73" << endl;
	w.push(73);

	//add 10000 values to vector
	for (int i = 0; i < 10000; i++){
		w.push(1);
	}
	//print size of memory allocated
	cout << w.getMemory() << endl;

	//remove 9998 items from vector
	for (int i = 0; i < 9998; i++) {
		w.pop();
	}
	//print size of memory allocated
	cout << w.getMemory() << endl;

	//print values in the vector
	w.printExisting();

	system("pause");
}