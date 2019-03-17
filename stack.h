#ifndef CUSTOM_STACK

#include <iostream>
#include <string>

using namespace std;

template <class T>
class Stack
{
public:
    Stack();
    Stack(int maxSize);
    ~Stack();

    void push(T item);
    T pop();
    T peek();

    bool isFull();
    bool isEmpty();

    //Variables
    int size;
    int top;

    T* myArray;
};

template <class T>
Stack<T>::Stack()
{
    myArray = new T[128];
    size = 128;
    top = -1; // empty
}

template <class T>
Stack<T>::Stack(int maxSize)
{
    myArray = new T[maxSize];
    size = maxSize;
    top = -1; // empty
}

template <class T>
Stack<T>::~Stack()
{
    if(myArray)
        delete[] myArray;
}

template <class T>
void Stack<T>::push(T d)
{
    if(top == (size-1))
    {
        T* tempArray = new T[size+32];
        for(int i = 0; i < size; ++i)
            tempArray[i]=myArray[i];

        T* tempPointer = myArray;
        myArray = tempArray;
        tempArray = tempPointer;
        delete[] tempArray;
        size = size+32;
    }

    myArray[++top] = d;
}

template <class T>
T Stack<T>::pop()
{
    if(top == -1)
        throw out_of_range("Your stack is empty.");

    return myArray[top--];
}

template <class T>
T Stack<T>::peek()
{
    if(top == -1)
        throw out_of_range("Your stack is empty.");

    return myArray[top];
}

template <class T>
bool Stack<T>::isFull()
{
    return (top == size-1);
}

template <class T>
bool Stack<T>::isEmpty()
{
    return (top == -1);
}

#endif
