#include <iostream>

#include<cstring>

using namespace std;

int vowelCount(char *str)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = tolower(str[i]);
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' ||str[i] == 'u')
            count++;
    }
    return count;
}

int consonantCount(char *str)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = tolower(str[i]);
        if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u')
            count++;
    }
    return count;
}

void displayMenu()
{
    cout<<"\n\n===============================\n";
    cout<<"\t\tMENU\n";
    cout<<"===============================\n";
    cout<<"A)  Count the number of vowels in the string\n";
    cout<<"B)  Count the number of consonants in the string\n";
    cout<<"C)  Convert the string to uppercase\n";
    cout<<"D)  Convert the string to lowercase\n";
    cout<<"E)  Display the current string\n";
    cout<<"F)  Enter another string\n";
    cout<<"\n\nM)  Display this menu\n";
    cout<<"X)  Exit the program\n";
    cout<<"================================\n";
    cout<<"Choose your option: ";
}

void convertUpper(char* str)
{
    for(int i=0; str[i]!='\0';i++)
        str[i]=toupper(str[i]);
}

void convertLower(char* str)
{
    for(int i=0; str[i]!='\0';i++)
        str[i]=tolower(str[i]);
}

int main()
{
    const int Length= 100;
    char str[Length];
    cout<<"Give a string:\n";
    cin.getline(str,Length,'\n');
    displayMenu();
    char option;
    cin>>option;
    do
    {
        if(option=='M'||option=='m')
            displayMenu();
        else if(option=='A'||option=='a')
            cout<<"The number of vowels are: "<<vowelCount(str)<<endl;
        else if(option=='B'||option=='b')
            cout<<"The number of consonants are: "<<consonantCount(str)<<endl;
        else if(option=='C'||option=='c')
            convertUpper(str);
        else if(option=='D'||option=='d')
            convertLower(str);
        else if(option=='E'||option=='e')
            cout<<endl<<str<<endl;
        else if(option=='F'||option=='f')
        {
            cin.clear();
            cin.sync();
            cin.getline(str,Length,'\n');
        }
        cout<<"Give another option: ";
        cin>>option;
    }while(option!='x'&&option!='X');
    return 0;
}

