#include <iostream>
#include "Stack.h"
#include "node.h"


using namespace std;

int main()
{
    Stack s1;
    while(true)
    {
        int optiune;
        int data;
        cout<<"\n\n===============================\n";
        cout<<"\t\tMENU\n";
        cout<<"===============================\n";
        cout<<"1. Display\n";
        cout<<"2. Push\n";
        cout<<"3. Pop\n";
        cout<<"4. StopProgram\n";
        cout<<"================================\n";
        cout<<"Choose your option :";
        cin>>optiune;
        switch(optiune)
        {
            case 1:
                    s1.display();
                    break;
            case 2:
                cout<<"Push an element : ";
                cin>>data;
                s1.push(data);
                cout<<"\nAdded successfully";
                break;
            case 3:
                cout<<"Element "<<s1.pop()<<" removed";
                break;
            case 4:
                return 0;
            default:
                cout<<"Invalid command";
                break;
        }
    }
    return 0;
}
