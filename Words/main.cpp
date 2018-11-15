#include <iostream>
#include <fstream>
#include <string>


using namespace std;


struct node
{
    string word;
    node *prev;
    node *next;
};

node * head=NULL;
node * tail=NULL;

node *GetNewNode(string x)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->word=x;
    temp->next=NULL;
    temp->prev=NULL;
    return temp;
}

void InsertAtHead(string x)
{
    node *temp=GetNewNode(x);
    if(head==NULL)
    {
        head=temp;
        return;
    }
    head->prev=temp;
    temp->next=head;
    head=temp;
    return;
}

void SearchList()
{
    cout<<"Intro un cuvant pe care doresti sa il cauti in lista: ";
    string cuvant;
    cin>>cuvant;
    node *tempf=head;
    while(tempf!=NULL && cuvant!=tempf->word)
    {
        tempf=tempf->next;
    }
    if(tempf->word==cuvant)
        cout<<"Evrika";
    else
        cout<<"Nu s-a gasit cuvantul";

}

int main()
{
    char line[250];
    ifstream file("/Users/andreidancimpean/Documents/Training/Words/data.txt");
    if(file.is_open())
        file.getline(line,250);
    else
        cout<<"Couldn't open file";
    file.close();
    const char delim[2]=" ";
    char *token;
    token=strtok(line,delim);
    cout<<endl<<"Cuvintele citite sunt: ";
    while(token!=NULL)
    {
        cout<<token<<" ";
        InsertAtHead(token);
        token=strtok(NULL,delim);
    }
    cout<<endl<<"Ordinea inversa: ";
    node *tempf=head;
    while(tempf!=NULL)
    {
        cout<<tempf->word<<" ";
        tempf=tempf->next;
    }
    cout<<endl;
    SearchList();
    cout<<endl;
    return 0;
}
