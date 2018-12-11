#include <stdlib.h>
#include <iostream>

using namespace std;

struct Node
{
    int Date;
    Node *Next, *Prev;
    Node(int date, Node *next=NULL, Node* prev=NULL) :
        Date(date), Next(next), Prev(prev){}
};

typedef Node *Queue;

Queue CreateQueue()
{
    return NULL;
}

bool QueueIsEmpty(Queue &queue)
{
    return queue==NULL;
}

void Push(Queue &queue, int date)
{
    if(QueueIsEmpty(queue))
    {
        queue = new Node(date);
        queue->Prev=queue->Next=queue;
    }
    else
    {
        queue->Prev->Next=new Node(date,queue,queue->Prev);
        queue->Prev=queue->Prev->Next;
    }
}

int Pull(Queue &queue)
{
    int ret;
    if(QueueIsEmpty(queue))
        return int();
    if(queue->Prev==queue)
    {
        ret=queue->Date;
        delete queue;
        queue =NULL;
        return ret;
    }
    Node *tempQueue=queue;
    ret=queue->Date;
    queue=queue->Next;
    queue->Prev=queue->Prev->Prev;
    queue->Prev->Next=queue;
    delete tempQueue;
    return ret;
}

int main()
{
    Queue queue=CreateQueue();
    for(int i=0; i<30; i++)
        Push(queue, rand() % 30);
    Node*i;
    i=queue;
    cout<<endl<<"The queue has the following elements: "<<endl;
    while(i->Next!=queue)
    {
        cout<<i->Date<<"   ";
        i=i->Next;
    }
    cout<<endl<<"How many elemenents do you wish to pull ";
    int nr, j;
    cin>>nr;
    for(j=0;j<nr;j++)
        Pull(queue);
    i=queue;
    int div;
    cout<<endl<<"Provide a number to divide by "<<endl;
    cin>>div;
    cout<<"The numbers from queue who can divide by: "<<div<<" are: ";
    while(i->Next!=queue)
    {
        if(i->Date%div==0)
            cout<<i->Date<<" ";
        i=i->Next;
    }
    return 0;
}
