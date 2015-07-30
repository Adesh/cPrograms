/*

-------------------------------------------------------------------------------
  AUTHOR:    _(Adesh Shah)
  DATE:      _(28JUL2015)
  URL:       _(NULL)
-------------------------------------------------------------------------------
  FILE:      _(MergeSort.c)
  INFO:      _(classical merge sort algorithm)
  FUNCTION:  _(main,Merge,MergeSort,PrintArray)
-------------------------------------------------------------------------------
  CATEGORY:  _(other)
  TAGS:      _(sort,merge)
  LEVEL:     _(2)
-------------------------------------------------------------------------------

*/

#include <stdio.h>
#define _LIMIT_ 10

void MergeSort(int*, int, int);
void Merge(int*, int, int, int);
void PrintArray(int*);

int main(void){
    int Set[_LIMIT_],
		Option = 1,
		i;
    
    while(Option){
        printf("Merge sort algorithm:\nPrint 10ss numbers\n");     
		for(i=0; i<_LIMIT_; i++)
			scanf("%d", &Set[i]);
		PrintArray(Set);
        MergeSort(Set, 0, _LIMIT_-1);
        PrintArray(Set);
        
        printf("Do you want to continue?\nYes - 1\nExit - 0\n");
        scanf("%d", &Option);        
    }
        
    return 0;
}

void MergeSort(int* _Array, int _Low, int _High){
    int Mid;
    
    if(_Low < _High){
        Mid=(_Low + _High)/2;
        MergeSort(_Set, _Low, Mid);
        MergeSort(_Set, Mid+1, _High);
        Merge(_Set, _Low, Mid, _High);
    }
}
void Merge(int* _Array, int _Low, int _Mid, int _High){
    int i = _Low,
        Mid = _Mid + 1,
        k,
        Low = _Low, 
        TempSet[_LIMIT_];

    while( (Low <= _Mid) && (Mid <= _High)){
    	if(_Set[Low] <= _Array[Mid])
			TempSet[i++] = _Array[Low++];
		else
			TempSet[i++] = _Array[Mid++];
    }
    
    while(Low <= _Mid){
    	TempSet[i++] = _Array[Low++];
    }
    
    while(Mid <= _High){
    	TempSet[i++] = _Array[Mid++];
    }
    
    for(k=_Low; k<=_High; k++)
        _Array[k] = TempSet[k];
}

void PrintArray(int *_Array){
	int i;
	printf("\nArray: ");
	for(i=0; i<_LIMIT_; i++)
		printf("%d -> ", _Array[i]);
	printf("NULL\n");
}
