/*

-------------------------------------------------------------------------------
  AUTHOR:    _(Adesh Shah)
  DATE:      _(27JUL2015)
  URL:       _(NULL)
-------------------------------------------------------------------------------
  FILE:      _(Palindrome.c)
  INFO:      _(Check if string is palindrome)
  FUNCTION:  _(Main,Palindrome,StrRev,StrLen)
-------------------------------------------------------------------------------
  CATEGORY:  _(string)
  TAGS:      _(palindrome)
  LEVEL:     _(1)
-------------------------------------------------------------------------------

*/

#include <stdio.h>

int StrLen(char*);
int Palindrome(char*);

int main(){
    int Option = 1;
    char Str[15];
    while(Option){
        printf("Enter a choice: \n1.) Check if a string is palindrome\n0.) Exit\n");
        scanf("%d", &Option);

        switch(Option){
            case 1:
                printf("Enter a string: ");
                scanf("%s", Str);
                if(Palindrome(Str))
                    printf("Ans: String is palindrome\n\n");
                   else
                    printf("Ans: String is not palindrome\n\n");
                break;
            case 0:
               break;
            default:
                printf("Enter a valid choice\n\n");
        }
    }
 return 0;
}

int Palindrome(char* _String){
    int Length = StrLen(_String),
        temp,
        i;

    if(Length == 1)
        return 1;

    temp = Length/2;
    for(i=0; i<temp; i++)
        if(_String[i] != _String[Length - i -1])
            return 0;

    return 1;
}

int StrLen(char* _InputString){
    int Length = 0;

    while(_InputString[Length++] != '\0');

    return --Length;
}
