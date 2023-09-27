/*
 Course: Fundamentals of Computing II
 Student Name: Ismail ElDahshan
 Student ID: 900221719
 Professor: Dr. Amr Goneid
 Section: 3
 */
#include "Stack.h"
#include <iostream>
using namespace std;

template <class Type>
Stackt <Type> :: Stackt(int size)
{
    
    MaxSize = size;// sets maxsize to the size
    arr = new Type[MaxSize];//creates 1d dynamic stack array
    top = -1;//sets top to be -1
    
}

// Destructor
template <class Type>
Stackt <Type> :: ~Stackt()
{
    delete [ ] arr;// deletes the 1d dynamic array class stack after usage
}

template <class Type>
void Stackt<Type>::push(Type v)
{
    if(stackIsFull())
        cout << "Stack Overflow";//checks if stack is full
    else
        arr[++top] = v;// if not push elements in stack
}

template <class Type>
void Stackt<Type>::pop(Type &v)
{
    if(stackIsEmpty())
        cout << "Stack Underflow";//chcecks if stack is empty
    else
        v = arr[top--];// if not remove elemets from stack
}

template <class Type>
void Stackt<Type>::stackTop(Type &v) const
{
    if(stackIsEmpty())
        cout << "Stack Underflow";//checks if stack is empty
    else
        v = arr[top];// else make the varriable be = to the top of the stack
}

template <class Type>
bool Stackt<Type>::stackIsEmpty() const
{
    return (top ==-1);// if the stack is empty top will be = -1
    
}

template <class Type>
bool Stackt<Type>::stackIsFull() const
{
    return (top ==(MaxSize-1));// if stack is full stack will be = maxsize-1
    
}



