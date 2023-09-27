/*
 Course: Fundamentals of Computing II
 Student Name: Ismail ElDahshan
 Student ID: 900221719
 Professor: Dr. Amr Goneid
 Section: 3
 */
#ifndef Stack_h
#define Stack_h
template <class Type>

class Stackt
{
public:
    Stackt (int size=1000);// constructor that initiallizes all varriables in the stack
    ~Stackt();// destructor that destroys the stack after usage
    void push(Type v );// push function that pushes elements onto the stack
    void pop(Type &v);// pop function that pops elements out of the staxk
    void stackTop(Type &v) const; // retrieve top function that retrieves the top elemnet on the stack
    bool stackIsEmpty() const; // checks if stack is empty
    bool stackIsFull() const; // checks if stack is full
private:
    Type *arr;// dynamic pointer that will be used for the dynamic staxk array
    int top, MaxSize;// top index and maxsize of the stack array
};
#endif
