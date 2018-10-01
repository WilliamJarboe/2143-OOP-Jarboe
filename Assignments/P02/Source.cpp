#include <iostream>
#include "myVector.h"
using namespace std;



int main() {
	myVector v1(10);
	myVector v2(10);

	v1.push_back(8);
	// v1 contains: [8]

	v2.push_back(10);
	v2.push_back(20);
	v2.push_back(30);
	// v2 contains: [10,20,30]

	// Declare some int array
	int A[] = { 1,2,3,4,5 };


	v1.push_back(A, 5);
	// v1 contains: [8,1,2,3,4,5]

	v1 = v1 + v2;
	// v1 contains: [18,21,32,3,4,5]

	cout << v1 << endl;
	// would print: [18,21,32,3,4,5] to standard out.

	cout << v1[2] << endl;
	// would print: 32 to standard out.


	v2 = v2 * 3;
	// v2 contains: [30,60,90]

	v2 = v2 * v1;
	// v2 contains: [540,1260,2880]

	// What about strings??
	system("pause");
}
