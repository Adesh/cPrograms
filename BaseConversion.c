/*

-------------------------------------------------------------------------------
  AUTHOR:    _(Adesh Shah)
  DATE:      _(27JUL2015)
  URL:       _(NULL)
-------------------------------------------------------------------------------
  FILE:      _(BaseConverstion.c)
  INFO:      _(Base conversion: binary, decimal & hexadecimal)
  FUNCTION:  _(Main,Decimal2Binary,Binary2Decimal,Decimal2Hexadecimal,Hexadecimal2Decimal,StrRev,StrLen)
-------------------------------------------------------------------------------
  CATEGORY:  _(other)
  TAGS:      _(base,binary,hexadecimal,decimal)
  LEVEL:     _(2)
-------------------------------------------------------------------------------

*/

#include <stdio.h>
#include <math.h>

#define _LIMIT_ 2*8 /* Limit in bits to hold HEX number */

#define SWAP(a,b) do{                   \
                    if(a!=b){           \
                      a^=b; b^=a; a^=b; \
                    }			\
		  }while(0)  

int Decimal2Binary(int);
int Binary2Decimal(int);
char* Decimal2Hexadecimal(int, char*);
int Hexadecimal2Decimal(char*);
char* StrRev(char*);
int StrLen(char*);

int main(){
    int Option = 9,
        InputNumber,
        OutputNumber;
    char  InputNumberHex[_LIMIT_],
          OutputNumberHex[_LIMIT_];

    while(Option){
        printf("Enter choice:\n1) decimal to binary\n2) binary to decimal\n3) decimal to hex\n4) hex to decimal\n0) exit\n");
        scanf("%d", &Option);
        switch(Option){
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &InputNumber);
                OutputNumber = Decimal2Binary(InputNumber);
                printf("Ans: Binary -> %d\n\n", OutputNumber);
                break;

            case 2:
                printf("Enter a binary number: ");
                scanf("%d", &InputNumber);
                OutputNumber = Binary2Decimal(InputNumber);
                printf("Ans: Decimal -> %d\n\n", OutputNumber);
                break;

            case 3:
                printf("Enter a decimal number: ");
                scanf("%d", &InputNumber);
                Decimal2Hexadecimal(InputNumber, OutputNumberHex);
                printf("Ans: Hexadecimal -> %s\n\n", OutputNumberHex);
                break;

            case 4:
                printf("Enter a hexadecimal number: ");
                scanf("%s", InputNumberHex);
                OutputNumber = Hexadecimal2Decimal(InputNumberHex);
                printf("Ans: Decimal -> %d\n\n", OutputNumber);
                break;

            case 0:
                break;

            default:
                printf("Enter a valid choice\n\n");
                break;
        }
    }
    return 0;
}

int Decimal2Binary(int _InputNumber){
    int Remainder,
        i=1,
        Binary=0;

    while(_InputNumber){
        Remainder = _InputNumber%2;
        _InputNumber /= 2;
        Binary += Remainder*i;
        i *= 10;
    }

    return Binary;
}

int Binary2Decimal(int _InputNumber){
    int Decimal = 0,
        i = 0,
        Remainder;

    while(_InputNumber){
        Remainder = _InputNumber%10;
        _InputNumber /= 10;
        Decimal += Remainder * pow(2,i);
        ++i;
    }

    return Decimal;
}

char* Decimal2Hexadecimal(int _InputNumber, char* _OutputNumber){
    int i=0;
    char Remainder,
        *OutputNumber = _OutputNumber;

    while(_InputNumber){
        Remainder = "0123456789ABCDEF"[_InputNumber%16];
        _InputNumber /= 16;
        *(OutputNumber++) = Remainder;
    }
    *OutputNumber = '\0';
    StrRev(_OutputNumber);

    return _OutputNumber;
}

int Hexadecimal2Decimal(char* _InputNumber){
    int Length = StrLen(_InputNumber),
        i,
        OutputNumber = 0; /* decimal number */

    for(i=0; i<Length; i++){
        char TempStr[2] = {_InputNumber[i],'\0'};
        OutputNumber += pow(16,(Length-i-1))*atoi(TempStr);
    }

    return OutputNumber;
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
