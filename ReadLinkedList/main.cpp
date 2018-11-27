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
    LinkedList* list1 = new LinkedList();
    int i, n, v[15];
    cout<<"Da-ti nr de valori ce doriti a fi introduse in lista: ";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"v["<<i+1<<"]=";
        cin>>v[i];
        cout<<endl;
        list1->add(v[i]);
    }
    list1->afisList();
    return 0;
}
