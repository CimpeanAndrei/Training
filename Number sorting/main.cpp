#include <iostream>
#include <fstream>
#include <cstdlib>


using namespace std;

struct node
{
    int data;
    node* next;
};

int main()
{
    node *head, *tail;
    head=NULL;
    tail=NULL;
    int number[100], count=0, i;
    ifstream file("numbers.in");
    while(!file.eof())
    {
        file>>number[count];
        count++;
    }
    count--;
    for(i=0; i<count; i++)
    {
        node *temp=new node;
        temp->data=number[i];
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
            tail=temp;
            temp=NULL;
        }
        else
        {
            tail->next=temp;
            tail=temp;
        }
    }
    node *temp=new node;
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->next;

    }
    cout<<endl;
    cout<<"Ascending order: "<<endl;
    node *j, *k;
    node *tempc=new node;
    j=head;
    k=head->next;
    for(j=head;j!=NULL;j=j->next)

            for(k=j->next;k!=NULL;k=k->next)

                if(j->data>k->data)
                    {
                        tempc->data=j->data;
                        j->data=k->data;
                        k->data=tempc->data;

                    }
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->next;

    }
    return 0;
}
