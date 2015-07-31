/*

-------------------------------------------------------------------------------
  AUTHOR:    _(Adesh Shah)
  DATE:      _(28JUL2015)
  URL:       _(NULL)
-------------------------------------------------------------------------------
  FILE:      _(Stack.c)
  INFO:      _(simple stack operations)
  FUNCTION:  _(main,Push,Pop,Peep,Change,StackPrint,DeleteStack)
-------------------------------------------------------------------------------
  CATEGORY:  _(linkedlist)
  TAGS:      _(stack,linkedlist)
  LEVEL:     _(2)
-------------------------------------------------------------------------------

*/

#include <stdio.h>
#include <stdlib.h>
#define STACK_LIMIT 25

typedef struct _node{
	int val;
	struct _node *next;
} node;

node *TOS; /* TOS: TOP OF STACK */
int COUNT;

node* Push(int);
node* Pop();
int Peep(int);
int Change(int,int);
void StackPrint();
int DeleteStack();

int main(){
	int Option=1,
			Value,
			i;	       
	
	while(Option){
		printf("1) PUSH Stack\n2) POP Stack\n3) Print Stack\n4) Peep\n5) Change Stack\n0) Exit program\n"); 
		scanf("%d", &Option);  
		switch(Option){
		 case 1:
		   do{
				printf("Enter a +ve value: ");
 		    scanf("%d", &Value);
			 }while(Value<0);       
			 Push(Value);	/* allow possitive values */		   
			 printf("Stack PUSHed\n\n");
		   break;
		 case 2:
		   Pop();
		   printf("Stack POPed\n\n");
		   break;
		 case 3:
		   StackPrint();
		   break;
		 case 4:
			 printf("Enter a valid index: ");
		   scanf("%d", &Value);
		   Value = Peep(Value);
			 if(Value)
			 	printf("Value at asked index: %d\n\n", Value);
		   else
				printf("wrong index\n\n");
			 break;
		 case 5:
			 printf("Enter a valid index & value: ");
		   scanf("%d %d", &i, &Value);
			 Change(i,Value);
			 printf("Value changed\n\n");
		   break;
		 case 0:
		   DeleteStack();
		   break;
		 default:
			 printf("Enter a valid choice\n\n");
			 break;
		}
	}
  return 1;
}


node* Push(int _Value){
	if(COUNT>STACK_LIMIT)
		return; /* Stack overflow */	

	node *ptr = (node*)malloc(sizeof(node));
  if(ptr == NULL)
		return;
	ptr->val = _Value;
	ptr->next = TOS;
	TOS = ptr;
	
	COUNT++;
	
	return TOS;
}

node* Pop(){
	if(COUNT<1)
		return; /* Stack empty */
	node *ptr = TOS;
	TOS = TOS->next;
	free(ptr);
	COUNT--;
	
	return TOS;
}

int Peep(int _i){
	if(_i>COUNT && _i<=0)		/* Element indexed starts from [1 ... N] Ex. peep 5th element */
		return -1;
	
	node *ptr = TOS;
	--_i;
	while(--_i>=0)	
		ptr = ptr->next;

	return ptr->val;
}

int Change(int _i, int _Val){
	if(_i>COUNT && _i<=0)		/* Element indexed starts from [1 ... N] Ex. peep 5th element */
		return;
	
	node *ptr = TOS;
	--_i;	
	while(--_i>=0)	
		ptr = ptr->next;
	
	ptr->val = _Val;
	return 1;
}

void StackPrint(){
	node* ptr = TOS; 	
	printf("TOS -> ");
	while(ptr != NULL){
		printf("%d -> ", ptr->val);
		ptr=ptr->next;
	}
	printf("EOS\n\n");
}

int DeleteStack(){
	node *ptr = TOS;
	while(ptr != NULL){
		TOS = ptr->next;
		free(ptr);			
		ptr = TOS->next;
	}
	return 1;
}
