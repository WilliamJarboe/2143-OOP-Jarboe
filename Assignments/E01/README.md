## C++ Extra Credit
#### William Jarboe


###### Objects:
* Objects are run-time entities in an Object oriented system, objects are instances of a class or struct.
* Objects can be user-defined or implemented through libraries
* data is held inside objects and can be private, public, or protected, giving outside functions and classes different levels of access.

```
class person{
    private:
        char name[20];
        int id;
    public:
        void getdetails(){}
    protected:
        string phoneNum;
};
    
int main()
{
    person p1; //p1 is an object
}
```
###### Encapsulation and Data abstraction:
* Wrapping up(combing) of data and functions into a single unit is known as encapsulation.
* The data is not accessible to the outside world and only those functions which are wrapping in the class can access it.
* This insulation of the data from direct access by the program is called data hiding or information hiding.

###### Data abstraction
* refers to providing only needed information to the outside world and hiding implementation details.
    * For example, consider a class Complex with public functions as getReal() and getImag().
    * We may implement the class as an array of size 2 or as two variables.
* The advantage of abstractions is, we can change implementation at any point, users of Complex class wont’t be affected as out method interface remains same.
* Had our implementation be public, we would not have been able to change it.



###### Inheritance:
* inheritance is the process by which objects of one class acquire the properties of objects of another class.
* It supports the concept of hierarchical classification. 
* Inheritance provides re usability. 
    * This means that we can add additional features to an existing class without modifying it.



###### Polymorphism:
* polymorphism means ability to take more than one form.
* An operation may exhibit different behaviors in different instances.
    * The behavior depends upon the types of data used in the operation.
* C++ supports operator overloading and function overloading.
    * Operator overloading is the process of making an operator to exhibit different behaviors in different instances.
    * A good example of this is to overload a << operator to print an array.
* Function overloading is using a single function name to perform different types of tasks.
* Polymorphism is extensively used in implementing inheritance.



###### Dynamic Binding:
* In dynamic binding, the code to be executed in response to function call is decided at runtime.
* C++ has virtual functions to support this.


###### Early Binding
* (compile-time time polymorphism) As the name indicates, compiler (or linker) directly associate an address to the function call.
* It replaces the call with a machine language instruction that tells the mainframe to leap to the address of the function.
* By default early binding happens in C++. Late binding (discussed below) is achieved with the help of virtual keyword)

###### Late Binding:
* (Run time polymorphism) In this, the compiler adds code that identifies the kind of object at runtime then matches the call with the right function definition (Refer this for details).
* This can be achieved by declaring a virtual function.

###### Copy Constructor:
* A copy constructor is a member function which initializes an object using another object of the same class.
* A copy constructor usually does a deep copy of the object it is working with, that is passed in by parameter.

###### Friend Class:
* A friend class can access private and protected members of other class in which it is declared as friend.
* It is sometimes useful to allow a particular class to access private members of other class.
* For example a LinkedList class may be allowed to access private members of Node.

###### Friend Function:
* Like friend class, a friend function can be given special grant to access private and protected members.
* A friend function can be:
  * A method of another class
  * A global function

###### Is it possible to access private data members without using friend?
* Yes
* You need to use pointers.

###### Static
* A static member is shared by all objects of the class
* all static data is initialized to zero when the first object is created
    * if no other initialization is present.
* A static member function can only access static data member
* other static member functions and any other functions from outside the class.
* By declaring a function member as static, we make it independent of any particular object of the class.
* A static member function can be called even if no objects of the class exist
* the static functions are accessed using only the class name and the scope resolution operator 
```
::
```
.
