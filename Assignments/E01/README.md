## C++ Extra Credit
#### William Jarboe


* Objects:
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
}```
