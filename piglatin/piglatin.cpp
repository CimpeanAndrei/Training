#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 43;

bool isVowel(char ch)
{
    switch(ch)
    {
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
        case 'Y':
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'y':
            return true;
        default:
            return false;
    }
}

void append(char* s, char c)
{
        int len = strlen(s);
        s[len] = c;
        s[len+1] = '\0';
}

bool isConsonant(char ch)
{
    if(ch!='A'&&ch!='E'&&ch!='O'&&ch!='U'&&ch!='I'&&ch!='a'&&ch!='e'&&ch!='o'&&ch!='u'&&ch!='i'&&ch!='Y'&&ch!='y')
        return true;
    else
        return false;
}

char* ToPigLatin(char* word)
{
    if(isVowel(word[0])&&word[0]!='y'&&word[0]!='Y')
    {
        strcat(word,"way");
        return word;
    }
    else
        if(isupper(word[0]))
        {
            word[0]=tolower(word[0]);
            do
            {
                append(word, word[0]);
                for(int j=0; j<39; j++)
                {
                    word[j]=word[j+1];
                }
            }
            while(isConsonant(*(word+0)));
            word[0]=toupper(word[0]);
            strcat(word,"ay");
            return word;
        }
        else
        {
            do
            {
                append(word, word[0]);
                for(int j=0; j<39; j++)
                {
                    word[j]=word[j+1];
                }
            }
            while(isConsonant(*(word+0)));
            strcat(word,"ay");
            return word;
        }
}
 int main()
{
   char word[5][MAX];
   cout << "Input 5 words: ";
   for (int i = 0; i < 5; i++)
       cin >> word[i];
   cout << "\nPig Latin version of the 5 words:\n";
   for (int i = 0; i < 3; i++)
   {
      ToPigLatin(word[i]);
      cout << word[i] << ' ';
   }
   cout << ToPigLatin(word[3]) << ' '<< ToPigLatin(word[4]) << '\n';
   return 0;
}
