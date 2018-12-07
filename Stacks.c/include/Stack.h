#ifndef STACK_H
#define STACK_H
#include "node.h"
#include<iostream>

class Stack
{
    public:
        Stack();
        void push(int elem);
        int pop();
        void display();
    protected:

    private:
        node *start;
};

#endif // STACK_H
