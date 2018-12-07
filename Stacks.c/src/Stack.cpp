#include "Stack.h"
#include "node.h"
#include<iostream>

using namespace std;

Stack::Stack()
{
    start=NULL;
}

void Stack::display()
{
    node* temp=start;
    while(temp!=NULL)
    {
        cout<<temp->getData()<<" ";
        temp=temp->next;
    }
}

void Stack::push(int elem)
{
    node *point;
    node *temp=start;
    point=new node(elem);
    if(start==NULL)
    {
        start=point;
        start->next=NULL;
    }
    else
    {
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=point;
        point->next=NULL;
    }
}

int Stack::pop()
{
    node *temp=start;
    node *top=start;
    while(temp->next!=NULL)
        temp=temp->next;
    while(top->next!=temp)
        top=top->next;
    top->next=NULL;
    int item=temp->getData();
    delete (temp);
    return item;
}
