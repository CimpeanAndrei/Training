#include <iostream>
#define STACK_SIZE 10
#define EMPTY (-1)

using namespace std;
char elements[STACK_SIZE];
int top=EMPTY;

void push(char ch)
{
    elements[++top]=ch;
}

char pop()
{
    return elements[top--];
}

int StackEmpty()
{
    return top==EMPTY;
}

int StackFull()
{
	return top==STACK_SIZE-1;
}

void palindrome()
{

}

int main()
{
    string palindrome;
	int options;
	char character;
	int i, j;
	bool ok;
	do {
		cout<<endl;
		cout<<"	1. Add a  to the stack.\n";
		cout<<"	2. Remove a  from the stack.\n";
		cout<<"	3. Display stack contents\n";
		cout<<"	4. Check if the stack is a palindrome\n";
		cout<<"        5. Exit\n";
		cout<<"	Please enter your choice-> ";
        cin>>options;
		switch ( options)
        {
			case 1:
					if ( !StackFull() )
                    {
						cout<<" Enter a single : ";
						cin>>character;
						push( character);
					}
					else
						cout<<"Sorry, stack is full."<<endl;
					break;
			case 2:
					if ( !StackEmpty())
						cout<<"\n Retrieved "<< pop();
					else
						cout<<" Sorry, stack is empty."<<endl;
					break;
			case 3: cout<<"\nThe stack contents is:\n";
					for (i=top; i>=0; i--)
						cout<<" "<< elements[ i];
					break;
			case 4:
                   for(j=0; j<=top; j++)
                        if(elements[j]==elements[top-j])
                            ok=true;
                        else
                        {
                            ok=false;
                            cout<<"The stack is not a palindrome\n";
                            break;
                        }
                        if(ok==true)
                            cout<<"The stack is a palindrome\n";
                        break;
            case 5:
                    cout<<"Exiting.. ";
                    return 0;
			default:
					cout<<" Invalid option, please retry\n."<<endl;
					break;
		}

	} while ( options != 5);
	return 0;
}
