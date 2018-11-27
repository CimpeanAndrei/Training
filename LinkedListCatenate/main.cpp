#include <iostream>

using namespace std;

#include <iostream>

class node
{
public:
    node* next;
    int data;
};

using namespace std;

class LinkedList
{
public:
    int lungime;
    node* head;
    node* tail;
    LinkedList();
    void add(int data);
    void afisList();
};

LinkedList::LinkedList()
{
    this->lungime = 0;
    this->head = NULL;
    this->tail=NULL;
}

void LinkedList::add(int data)
{
    node *temp=new node;
    temp->data=data;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
        tail=temp;
        this->lungime++;
    }
    else
    {
        tail->next=temp;
        tail=tail->next;
        this->lungime++;
    }
}

void LinkedList::afisList()
{
    node* temp = new node;
    int i = 1;
    temp=head;
    while(temp!=NULL)
    {
        cout <<"elementul "<< i << ": " << temp->data << std::endl;
        temp = temp->next;
        i++;
    }
}

int main()
{
    cout<<endl;
    LinkedList* list1 = new LinkedList();
    for (int i = 0; i < 10; ++i)
    {
        list1->add(rand() % 15);
    }
    cout<<endl<<"Prima lista contine: "<<endl;
    list1->afisList();
    LinkedList* list2 = new LinkedList();
    for (int i = 0; i < 10; ++i)
    {
        list2->add(rand() % 15);
    }
    cout<<endl<<"a doua lista contine: "<<endl;
    list2->afisList();
    cout<<endl<<"Concatenarea celor doua liste: "<<endl;
    list1->tail->next=list2->head;
    list1->afisList();
    return 0;
}
