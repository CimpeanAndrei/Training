#include <iostream>

using namespace std;

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
    for (int i = 0; i < 10; ++i)
    {
        list1->add(rand() % 10);
    }
    list1->afisList();
    cout << endl<<"List1 lungime: " << list1->lungime <<endl;
    cout<<endl;
    LinkedList* list2 = new LinkedList();
    LinkedList* list3 = new LinkedList();
    node *temp1=new node;
    temp1=list1->head;
    node* temp2= new node;
    temp2=list2->head;
    node* temp3=new node;
    temp3=list3->head;
    for(int i=0; i<list1->lungime;i++)
        if(i%2==0)
        {
            list2->add(temp1->data);
            temp1=temp1->next;
        }
        else
        {
            list3->add(temp1->data);
            temp1=temp1->next;
        }
    cout<<"Rearanjarea primei liste in 2 ce contin doar termenii impari/pari: "<<endl;
    list2->afisList();
    cout<<endl;
    list3->afisList();
    return 0;
}
