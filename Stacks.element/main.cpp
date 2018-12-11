#include <iostream>
#include <string>

using namespace std;

struct book
{
    string Name;
    int Pages;
    float Price;
    bool available;
    book *Next;
};

class stack
{
    public:
        stack();
        void push(string name, int pages, float price);
        void display();
    protected:
    private:
        book *front;
};

stack::stack()
{
    front=NULL;
}

void stack::push(string name, int pages, float price)
{
    book* point=new book;
    book* temp=front;
    point->Name=name;
    point->Pages=pages;
    point->Price=price;
    point->available=true;
     if(front==NULL)
    {
        front=point;
        front->Next=NULL;
    }
    else
    {
        while(temp->Next!=NULL)
            temp=temp->Next;
        temp->Next=point;
        point->Next=NULL;
    }
}

void stack::display()
{
    if(front==NULL)
    {
        std::cout<<"stack is empty.";
        return;
    }
    book *tempNode=front;
    if(front->Next==NULL)
    {
        cout<<"Book Name: "<<tempNode->Name<<endl;
        cout<<"Pages: "<<tempNode->Pages<<endl;
        cout<<"Price: "<<tempNode->Price<<endl;
        cout<<"Available"<<endl;
        return;
    }
    while(tempNode!=NULL)
    {
        cout<<"Book Name: "<<tempNode->Name<<endl;
        if(tempNode->available==true)
        {
        cout<<"Pages: "<<tempNode->Pages<<endl;
        cout<<"Price: "<<tempNode->Price<<endl;
        cout<<"Available"<<endl;
        }
        else
            cout<<"book not available";
        tempNode=tempNode->Next;
    }
    cout<<endl;
    return;
}

int main()
{
    stack Stack;
    while(true)
    {
        int option;
        int pages;
        string name;
        float price;
        cout<<"\n\n===============================\n";
        cout<<"\t\tMENU\n";
        cout<<"===============================\n";
        cout<<"1. DisplayStack\n";
        cout<<"2. Push\n";
        cout<<"3. ExitProgram\n";
        cout<<"================================\n";
        cout<<"Choose your option :";
        cin>>option;
        switch(option)
        {
            case 1:
                    Stack.display();
                    break;
            case 2:
                cout<<"The name of the book: ";
                cin>>name;
                cout<<"Number of pages: ";
                cin>>pages;
                cout<<"Book price: ";
                cin>>price;
                Stack.push(name, pages, price);
                cout<<"\nAdded successfully";
                break;
            case 3:
                return 0;
            default:
                cout<<"Enter a  valid command";
                break;
        }
    }
    return 0;
}
