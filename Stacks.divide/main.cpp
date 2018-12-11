#include <iostream>
#include <cstdlib>


using namespace std;

class Stack
{
    public :
        Stack(int i=0);
        ~Stack();
        void push(int x);
        void displays();
        int pop();
        void displaydiv();
    private:
        int lenght;
        int top;
        int *point;
};

Stack::Stack(int Size)
{
    top=-1;
    lenght=Size;
    if(Size==0)
        point=0;
    else
        point=new int[lenght];
}

Stack::~Stack()
{
    if(point!=0)
        delete [] point;
}

void Stack::push(int elem)
{
    if(point==0)
    {
        cout<<"Give the stack a size";
        cin>>lenght;
        point=new int[lenght];
    }
    if(top==(lenght-1))
    {
        cout<<"Cannot push into stack";
        return;
    }
    else
    {
        top++;
        point[top]=elem;
    }

}

void Stack::displays()
{
    for(int i=top; i>0; i--)
        cout<<" "<<point[i];
    cout<<endl;
}

int Stack::pop()
{
    if(point==0 || top==-1)
    {
        cout<<"Stack is empty";
        return -1;
    }
    int ret=point[top];
    top--;
    return ret;
}

void Stack::displaydiv()
{
    int div;
    cout<<"Provide a number to divide by: ";
    cin>>div;
    cout<<"The numbers that can divide "<<div<<" are: ";
    for(int i=top; i>0; i--)
        if(point[i]%div==0)
            cout<<point[i]<<" ";
}

int main()
{
    Stack stack;
    for(int i=0; i<10; i++)
        stack.push(rand() %100);
    stack.displays();
    cout<<"How many times do you want to pop the stack: ";
    int num;
    cin>>num;
    for(int j=0; j<num; j++)
        stack.pop();
    stack.displays();
    cout<<"The odd numbers are: ";
    stack.displaydiv();
    return 0;
}
