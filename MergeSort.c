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

void MergeSort(int*, int, int, int);
void Merge(int*, int, int);
void PrintArray(int*);

int main(void){
    int Set[_LIMIT_];
    int Option = 1;
    
    while(Option){
        printf("Merge sort algorithm:\nRandomly creating array\n");
        PrintArray();
        MergeSort(Set);
        PrintArray();
        
        printf("Do you want to continue?\nYes - 1\nExit - 0\n");
        scanf("%d", &Option);        
    }
        
    return 0;
}

void MergeSort(int* _Set, int _Low, int _High){
    int Mid;
    
    if(_Low < _High){
        Mid=(_Low + _High)/2;
        MergeSort(_Set, _Low, Mid);
        MergeSort(_Set, Mid+1, _High);
        MergeSort(_Set, _Low, Mid, _High);
    }
}
void Merge(int* _Set, int _Low, int _Mid, int _High){
    int i = _Low,
        Mid = _Mid + 1,
        k,
        Low = _Low, 
        TempSet[MAX];

    while( (Low <= _Mid) && (Mid <= _High)){
    
    }
    
    while(Low <= _Mid){
    
    }
    
    while(Mid <= _High){
    
    }
    
    for(k=low;k<=high;k++)
        _Set[k] = TempSet[k];
}

void PrintArray(int *_Set){

}
