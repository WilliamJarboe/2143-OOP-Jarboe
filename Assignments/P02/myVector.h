#include <iostream>
using namespace std;

class myVector {
private:
	//reference variables
	int				*theVector;
	int				nextEmpty			= 0;
	int				arraySize;
	int				originalSize;

	//dynamically allocating functions that work on push_back
	//and pop as needed
	int*			expandArray			();
	int*			shrinkArray			();

	void			silentpop			();

public:
	//constructor
	myVector							(int size);
	//publically accessible methods
	void			printExisting		();
	void			printWhole			();
	void			push_back			(int val);
	void			push_back			(string val);//troll
	int				pop					();
	int				getCount			();
	int				getMemory			();
	int				operator		[]	(int i);
	friend ostream& operator		<<	(ostream& os, myVector& vec);
	myVector		operator		+	(myVector v);
	myVector		operator		-	(myVector v);
	myVector		operator		*	(myVector v);
	myVector		operator		*	(int v);
	myVector		operator		/	(myVector v);
	myVector		operator		/	(int v);
	myVector		operator		==	(myVector v);
	void			operator		=	(myVector i);
	void			push_back			(int v[], int n);
};
