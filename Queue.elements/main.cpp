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

class queue
{
    public:
        queue();
        void push(string name, int pages, float price);
        void display();
        virtual ~queue();
    protected:
    private:
        book *front;
        book *back;
        int lenght;
};

queue::queue()
{
    front=back=NULL;
}

void queue::push(string name, int pages, float price)
{
    book* tempNode=new book;
    tempNode->Name=name;
    tempNode->Pages=pages;
    tempNode->Price=price;
    tempNode->available=true;
    if(front==NULL)
        front=back=tempNode;
    else
    {
        back->Next=tempNode;
        back=back->Next;
        back->Next=NULL;
    }
    lenght++;
}

queue::~queue()
{
    if(front==NULL)
    {
        std::cout<<"Queue is empty ";
        return ;
    }
    book * tempNode=front;
    if(lenght>0)
    {
        front=tempNode->Next;
        lenght--;
        delete tempNode;
    }
}

void queue::display()
{
    if(front==NULL)
    {
        std::cout<<"Queue is empty.";
        return;
    }
    book *tempNode=front;
    if(front==back)
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
    queue Queue;
    while(true)
    {
        int option;
        int pages;
        string name;
        float price;
        cout<<"\n\n===============================\n";
        cout<<"\t\tMENU\n";
        cout<<"===============================\n";
        cout<<"1. DisplayQueue\n";
        cout<<"2. Push\n";
        cout<<"3. ExitProgram\n";
        cout<<"================================\n";
        cout<<"Choose your option :";
        cin>>option;
        switch(option)
        {
            case 1:
                    Queue.display();
                    break;
            case 2:
                cout<<"The name of the book: ";
                cin>>name;
                cout<<"Number of pages: ";
                cin>>pages;
                cout<<"Book price: ";
                cin>>price;
                Queue.push(name, pages, price);
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
