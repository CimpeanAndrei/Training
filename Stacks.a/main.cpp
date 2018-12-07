#include <iostream>
#include<stdlib.h>

using namespace std;

int stack[30];
int top;

int main()
{

    int stack[30];
    int top=0;

	int choice;
    int ele;
    while(true)
	{
		cout<< "Implementation of a stack"<<endl;
        cout<<"1.push, 2.pop, 3.display, 4. exit"<<endl;
        cout<<" Please enter your choice"<<endl;
        cin>>choice;

	switch(choice)
	{

	case 1: cout<<"enter your element: ";
        cin>>ele;
		if (top>30)
        {
            cout<<"your stack has overflowed or is full, returning to a past state"<<endl;
        }
        stack[++top]=ele;
		break;

	case 2: cout<<"you have popped an element out!"<<endl;
		if(top<0)
        {
            cout<<"stack is underflowed,restoring last state"<<endl;
        }
        cout<<"deleted"<<stack[top--];
		break;

	case 3:
	    if (top<0)
        {
            cout<<"The stack is empty"<<endl;
        }
        for ( int i = top;i>0;i--)
            cout<<stack[i]<< " ";
        break;
        case 4:
            return 0;
        }
    }
}
