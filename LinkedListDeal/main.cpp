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
    list1->afisList();
    cout << endl<<"List1 lungime: " << list1->lungime <<endl;
    cout<<endl;
    LinkedList* list2 = new LinkedList();
    for (int i = 0; i < 10; ++i)
    {
        list2->add(rand() % 15);
    }
    list2->afisList();
    cout << endl<< "List2 lungime: " << list2->lungime << endl;
    cout<<endl;
    LinkedList* list3= new LinkedList();
    if(list1->lungime==list2->lungime)
    {
        cout<<"Listele au aceesi lungime, deci se pot combina. "<<endl;
        node* temp1= new node;
        temp1=list1->head;
        node* temp2=new node;
        temp2=list2->head;
        for(int i=0; i<2*list1->lungime;i++)
            if(i%2==0)
            {
                list3->add(temp1->data);
                temp1=temp1->next;
            }
            else
            {
                list3->add(temp2->data);
                temp2=temp2->next;
            }
    }
    cout<<endl;
    list3->afisList();
    return 0;
}
