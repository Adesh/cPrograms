/*

-------------------------------------------------------------------------------
  AUTHOR:    _(Adesh Shah)
  DATE:      _(29JUL2015)
  URL:       _(NULL)
-------------------------------------------------------------------------------
  FILE:      _(QuickSort.c)
  INFO:      _(classical quick sort algorithm)
  FUNCTION:  _(main,QuickSort,PrintArray)
-------------------------------------------------------------------------------
  CATEGORY:  _(other)
  TAGS:      _(sort,quick)
  LEVEL:     _(2)
-------------------------------------------------------------------------------

*/

#include <stdio.h>
#define _LIMIT_ 10
#define SWAP(a,b) do{                   \
                    if(a!=b){           \
                      a^=b; b^=a; a^=b; \
                    }			\
		  }while(0)             

void QuickSort(int*, int);
void PrintArray(int*);

int main () {
    int Array[_LIMIT_] = {4, 65, 2, -31, 0, 99, 2, 83, 782, 1},
        Length = sizeof Array / sizeof Array[0],
        i;

    PrintArray(Array);
    QuickSort(Array, Length);    
    PrintArray(Array);
    
    return 0;
}

void QuickSort(int *_Array, int _N){
    int Left,
        Right, 
        Pivot, 
        t;
        
    if (_N < 2)
        return;
    
    Pivot = _Array[_N / 2];
    
    for (Left=0, Right=_N-1;; Left++, Right--){
        while (_Array[Left++] < Pivot); Left--;
        while (Pivot < _Array[Right--]); Right++;
        if (Left >= Right)
            break;
        SWAP(_Array[Left],_Array[Right]);
    }
    
    QuickSort(_Array, Left);
    QuickSort(_Array + Left, _N - Left);
}

void PrintArray(int *_Array){
	int i;
	printf("\nArray: ");
	for(i=0; i<_LIMIT_; i++)
		printf("%d -> ", _Array[i]);
	printf("NULL\n");
}
