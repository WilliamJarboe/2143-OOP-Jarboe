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
