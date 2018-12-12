#include <iostream>

using namespace std;

struct node
{
    char Data;
    node *Next;
    node *Prev;
};

class stack
{
    private:
        node *top;
        node *bottom;
    public:
        stack()
        {
            top=NULL;
        }
        void push();
        void pop();
        void display();
        void palindrome();
};

void stack::push()
{
    char value;
    cout<<"\n Insert a value into the stack: ";
    cin>>value;
    node *temp= new node;
    temp->Data=value;
    temp->Next=NULL;
    temp->Prev=NULL;
    if(top!=NULL)
    {
        temp->Next=top;
        top->Prev=temp;
    }
    if(top==NULL)
    {
        bottom=temp;
    }
    top=temp;
    cout<<"\n Added succesfully";
}

void stack::pop()
{
    node *temp=top;
    if(top==NULL)
        cout<<"\n The stack is empty ";
    top=top->Next;
    cout<<"\n Popped: "<<temp->Data;
    delete temp;
}

void stack::display()
{
    node *temp=top;
    cout<<"\n The stack is: \n";
    while(temp!=NULL)
    {
        cout<<temp->Data<<"->";
        temp=temp->Next;
    }
    cout<<"NULL"<<endl;
}

void stack::palindrome()
{
    node* tempt, *tempb;
    tempt=top;
    tempb=bottom;
    while(tempt!=NULL&&tempb!=NULL)
    {
        if(tempt->Data!=tempb->Data)
        {
            cout<<"\nThe stack is not a palindrome";
            return;
        }
        tempt=tempt->Next;
        tempb=tempb->Prev;
    }
    cout<<"\nThe stack is a palinrome";
}

int main()
{
    int option;
    stack Stack;
    while(1)
    {
        cout<<"\n-----------------------------------------------------------";
        cout<<"\n\t\tSTACK USING LINKED LIST\n\n";
        cout<<"1:PUSH\n2:POP\n3:DISPLAY STACK\n4:CHECK PALINDROME\n5:EXIT";
        cout<<"\nEnter your choice(1-5): ";
        cin>>option;
        switch(option)
        {
            case 1:
                Stack.push();
                break;
            case 2:
                Stack.pop();
                break;
            case 3:
                Stack.display();
                break;
            case 4:
                Stack.palindrome();
                break;
            case 5:
                cout<<"\nExiting ....";
                return 0;
                break;
            default:
                cout<<"\nPlease enter a valid option\n";
                break;
        }
    }
    return 0;
}
