/*

-------------------------------------------------------------------------------
  AUTHOR:    _(Adesh Shah)
  DATE:      _(28JUL2015)
  URL:       _(NULL)
-------------------------------------------------------------------------------
  FILE:      _(Stack.c)
  INFO:      _(simple stack operations)
  FUNCTION:  _(main,Push,Pop,StackPrint,DeleteStack)
-------------------------------------------------------------------------------
  CATEGORY:  _(linkedlist)
  TAGS:      _(stack,linkedlist)
  LEVEL:     _(2)
-------------------------------------------------------------------------------

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
	int val;
	struct _node *next;
} node;

node *top;
int count;

node* Push(int);
node* Pop();
void StackPrint();
int DeleteStack();

int main(){
	int Option=1,
			Value;	       
	
	while(Option){
		printf("1) PUSH Stack\n2) POP Stack\n3) Prinr Stack\n0) Exit program\n"); 
		scanf("%d", &Option);  
		switch(Option){
		 case 1:
		   printf("Enter a value: ");
		   scanf("%d", &Value);
		   Push(Value);
		   printf("Stack PUSHed\n\n");
		   break;
		 case 2:
		   Pop();
		   printf("Stack POPed\n\n");
		   break;
		 case 3:
		   StackPrint();
		   break;
		 case 0:
		   //DeleteStack();
		   break;
		 default:
			 printf("Enter a valid choice\n\n");
		}
	}
  return 1;
}


node* Push(int _Value){
	node *ptr = (node*)malloc(sizeof(node));
  if(ptr == NULL)
		return;
	ptr->val = _Value;
	ptr->next = NULL;

	top = ptr;

	return top;
}

node* Pop(){
	node *ptr = top;
	top = top->next;
	free(ptr);

	return top;
}

void StackPrint(){
	node* ptr = top; 	
	while(ptr != NULL){
		printf("%d\n", ptr->val);
		ptr=ptr->next;
	}
}

int DeleteStack(){
	node *ptr = top;
	while(ptr != NULL){
		top = ptr->next;
		free(ptr);			
	}
}
