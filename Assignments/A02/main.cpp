/**
*   Course: 2143OOP
*   Assignment: A02
*   Purpose: practice commenting code
*   @author: william jarboe (as comment editor)
*   @version: 1.0
*/

#include <iostream>

using namespace std;

int A[100];

//defines the contents of a node
struct Node
{
    int x;
    Node *next;
    //default values/constructors'
    Node()
    {
        x = -1;
        next = NULL;
    }
    Node(int n)
    {
        x = n;
        next = NULL;
    }
};

//defines the contents of the list class
class List
{
  //keeps track of the beginning and end of the list
  private:
    Node *Head;
    Node *Tail;
    int Size;
    
  
  public:
    List()
    {
        Head = Tail = NULL;
        Size = 0;
    }
    
    /**
    *  Pushes one item onto the list.
    *
    *  @param {int} item to push onto the list.
    */
    void Push(int val)
    
        // allocate new memory and init node
        Node *Temp = new Node(val);

        if (!Head && !Tail) //if the list has size of zero
        {
            Head = Tail = Temp;
        }
        else                //if this isn't the first thing to enter the list
        {
            Tail->next = Temp;
            Tail = Temp;
        }
        Size++;
    }
    
    /**
    *  Pushes one item onto the list,
    *  but makes it the first node.
    *
    *  @param {int} item to push onto the list.
    */
    void Insert(int val)
    {
        // allocate new memory and init node
        Node *Temp = new Node(val);

        // figure out where it goes in the list

        Temp->next = Head;
        Head = Temp;
        if (!Tail)
        

            Tail = Head;
        }
        Size++;
    }
    
    /**
    *  Prints the tail of the list.
    */
    void PrintTail()
    {
        cout << Tail->x << endl;
    }
    
    /**
    *  returns the whole list.
    *
    *  @return {string} The whole list, '->' separated
    */
    string Print()
    {
        Node *Temp = Head;
        string list;
        //cycle through list
        while (Temp != NULL)
        {
            list += to_string(Temp->x) + "->";
            Temp = Temp->next;
        }

        return list;
    }
    
    /**
    *  takes an item off the list.
    *  return {int} the item from the list.
    *  
    *  not implemented
    */
    int Pop()
    {
        Size--;
        return 0; //
    }

    /** 
    *   takes the two lists and concatenates them
    *   
    *   @param {List} the lists to concatenate
    *   @return {List} the concatenated list
    */  
    List operator+(const List &Rhs)
    {
        // Create a new list that will contain both when done
        List NewList;

        // Get a reference to beginning of local list
        Node *Temp = Head;

        // Loop through local list and Push values onto new list
        while (Temp != NULL)
        {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Get a reference to head of Rhs
        Temp = Rhs.Head;

        // Same as above, loop and push
        while (Temp != NULL)
        {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Return new concatenated version of lists
        return NewList;
    }

    /**
    *   Implementation of [] operator.
    *
    *   @param {int} index
    *   @return {int} int value to be returned as if the list were an array.   
    */
    int operator[](int index)
    {
        Node *Temp = Head;
        //check for error
        if (index >= Size)
        {
            //index is bigger than list
            cout << "Index out of bounds, exiting";
            //halt program
            exit(0);
        }
        else
        {
            //go from the beginning of the list to index
            for (int i = 0; i < index; i++)
            {
                Temp = Temp->next;
            }
            //get value at index and return it
            return Temp->x;
        }
    }
    
    /**
    *   allows string concatenation using << to take lists as parameters
    */
    friend ostream &operator<<(ostream &os, List L)
    {
        os << L.Print();
        return os;
    }
};

/**
*   controls the execution of the program.
*/
int main(int argc, char **argv)
{
    List L1;
    List L2;
    
    for (int i = 0; i < 25; i++) {
        L1.Push(i);
    }

    for (int i = 50; i < 100; i++) {
        L2.Push(i);
    }

    //cout << L1 << endl;
    L1.PrintTail();
    L2.PrintTail();

    List L3 = L1 + L2
    cout << L3 << endl;

    cout << L3[5] << endl;
    return 0;
}
