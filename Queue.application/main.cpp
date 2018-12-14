#include <iostream>
#include<string>
using namespace std;
#define MAX_SIZE 3

template <class T> class Employee
{
	private:
		T EmployeeName;
		T Description;
	public:
		Employee<T> *nextEmployee;
		Employee(T name, T desc)
		{
			EmployeeName=name;
			Description=desc;
		}
		T getName()
		{
			return EmployeeName;
		}
		T getDescription()
		{
		    return Description;
		}
};

template <class T> class Company
{
	private:
		Employee<T> *frontEmployee;
		Employee<T> *rearEmployee;
		Employee<T> *temp;
		bool empty;
		bool full;
	public:
	    Company()
	    {
            frontEmployee=NULL;
            rearEmployee=NULL;
            empty=true;
            full=false;
        }
		~Company()
		{
            while(frontEmployee!=NULL)
            {
                temp=frontEmployee;
                frontEmployee=frontEmployee->nextEmployee;
                delete(temp);
            }
        }
		bool isEmpty()
		{
            if(frontEmployee==NULL)
                empty=true;
            else
                empty=false;
            return empty;
        }

		void printCompany()
		{
            temp=frontEmployee;
            if(temp!=NULL)
            {
                while(temp!=NULL)
                {
                    if(temp->nextEmployee!=NULL)
                    {
                        cout<<temp->getName()<<"\n";
                        cout<<temp->getDescription()<<"\n";
                        cout<<endl;
                    }
                    else
                    {
                        cout<<temp->getName()<<"\n";
                        cout<<temp->getDescription()<<"\n";
                    }
                    temp=temp->nextEmployee;
                }
                cout<<endl;
            }
            else
            cout<<"Company empty" <<endl;
        }
		void enQueue(T name, T desc)
		{
            Employee<T> *newEmployee=new Employee<T>(name, desc);
            newEmployee->nextEmployee=NULL;
            if(rearEmployee==NULL)
            {
                rearEmployee=newEmployee;
                frontEmployee=newEmployee;
            }
            else
            {
                rearEmployee->nextEmployee=newEmployee;
                rearEmployee=newEmployee;
            }
        }
		T deQueue()
		{
            T Name;;
            if(!isEmpty())
            {
                temp=frontEmployee;
                Name=frontEmployee->getName();
                frontEmployee=frontEmployee->nextEmployee;
                delete(temp);
            }
            else
            {
                throw "Exception:Company empty";
            }
            return Name;
        }
};

int main()
{
    Company<string> Queue;
    while(true)
    {
        int option;
        string name, desc;
        cout<<"\n\n===============================\n";
        cout<<"\t\tMENU\n";
        cout<<"===============================\n";
        cout<<"1. DisplayCompany\n";
        cout<<"2. Enqueue\n";
        cout<<"3. Dequeue\n";
        cout<<"4. ExitProgram\n";
        cout<<"================================\n";
        cout<<"Choose your option :";
        cin>>option;
        switch(option)
        {
            case 1:
                Queue.printCompany();
                break;
            case 2:
                cout<<"The name of the employee: ";
                cin>>name;
                cout<<"Description of the employee: ";
                cin>>desc;
                Queue.enQueue(name, desc);
                cout<<"\nAdded successfully";
                break;
            case 3:
                cout<<"\nRemoved successfully: "<<Queue.deQueue();
                break;
            case 4:
                return 0;
            default:
                cout<<"Enter a  valid command";
                break;
        }
    }
}
