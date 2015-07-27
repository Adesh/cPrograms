/*

-------------------------------------------------------------------------------
  AUTHOR:    _(Adesh Shah)
  DATE:      _(27JUL2015)
  URL:       _(NULL)
-------------------------------------------------------------------------------
  FILE:      _(StringReverse.c)
  INFO:      _(String reverse using pointers)
  FUNCTION:  _(Main,StrRev,StrLen)
-------------------------------------------------------------------------------
  CATEGORY:  _(string)
  TAGS:      _(string,basic,reverse)
  LEVEL:     _(1)
-------------------------------------------------------------------------------

*/

#include <stdio.h>

#define SWAP(a,b) if(a!=b){  \
                   do{       \
                     a^=b;   \
                     b^=a;   \
                     a^=b;   \
                   }         \
                   while(0); \
                  }

char* StrRev(char*);
int StrLen(char*);

int main(void){
    int Option = 1;
    char Str[15];
    while(Option){
        printf("Enter a choice: \n1.) String length\n2.) String reverse\n0.) Exit\n");
        scanf("%d", &Option);

        switch(Option){
            case 1:
                printf("Enter a string: ");
                scanf("%s", Str);
                int Len = StrLen(Str);
                printf("Ans: String length is %d\n\n", Len);
                break;
            case 2:
                printf("Enter a string: ");
                scanf("%s", Str);
                StrRev(Str);
                printf("Ans: Reversed string - %s\n\n", Str);
                break;
            case 0:
               break;
            default:
                printf("Enter a valid choice\n\n");
        }
    }
}
char* StrRev(char* _InputString){
    int Length = 0,
        i,
        j;

    Length = StrLen(_InputString);

    for(i=Length; i>=0; i--)
        for(j=0; j<i-1; j++)
            SWAP(_InputString[j], _InputString[j+1]);

    return _InputString;
}

int StrLen(char* _InputString){
    int Length = 0;

    while(_InputString[Length++] != '\0');

    return --Length;
}
