/*
-------------------------------------------------------------------------------
  AUTHOR:    _(Adesh Shah)
  DATE:      _(28JUL2015)
  URL:       _(NULL)
-------------------------------------------------------------------------------
  FILE:      _(DoublyLinkedList.c)
  INFO:      _(Doubly Linkedlist operations)
  FUNCTION:  _(main,InsertDoublyList,PrintDoublyList,DeleteNode,ReverseDoublyList,DeleteDoublyList)
-------------------------------------------------------------------------------
  CATEGORY:  _(linkedlist)
  TAGS:      _(doubly,linkedlist)
  LEVEL:     _(2)
-------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

#define SWAP(a,b) do{                       \
                    if(a!=b){               \
                        a^=b; b^=a; a^=b;   \
                    }                       \
                  }while(0)

typedef struct _node{
    int val;
    struct _node *next;
    struct _node *prev;
} node;

node *HEAD = NULL,
     *CURR = NULL;
int COUNT = 0;

node* InsertDoublyList(int, int); /* insert into nth position: if n=0->append, if n=count->prepend, else insert in middle */
int PrintDoublyList();
int DeleteNode(int);    /* delete nth node */
int ReverseDoublyList();
int DeleteDoublyList();

int main(void){
    int Option = 1;
    int Value,
        N;
    while(Option){
        printf("1) Insert in Doubly-list\n2) Print Doubly-list\n3) Delete a node\n4) Reverse Double-list\n0) Exit program\n");
        scanf("%d", &Option);

        switch(Option){
            case 1:
                printf("Enter a value & position(0:Left, -1:Right): ");
                scanf("%d %d", &Value, &N);
                if(InsertDoublyList(Value,N) == NULL)
                    printf("Error inserting doubly list\n\n");
                PrintDoublyList();
                break;
            case 2:
                PrintDoublyList();
                break;
            case 3:
                printf("Enter node position to delete: ");
                scanf("%d", &N);
                if(DeleteNode(N))
                    printf("Node deleted\n\n");
                else
                    printf("Error deleting a Node\n\n");
                PrintDoublyList();
                break;
            case 4:
                if(ReverseDoublyList())
                    PrintDoublyList();
                break;
            case 0:
                DeleteDoublyList();
                break;
            default:
                printf("Enter a valid choice\n\n");
        }
    }
    return 1;
}


node* InsertDoublyList(int _Val, int _N){
    if(_N > COUNT)
        return NULL;

    node *ptr = (node*)malloc(sizeof(node));
    if(ptr == NULL)
        return;
    ptr->val = _Val;
    ptr->next = NULL;
    ptr->prev = NULL;

    if(HEAD == NULL){       /* first element */
        HEAD = CURR = ptr;
        COUNT++;
        return HEAD;
    }

    if(_N == 0){ /* prepend = insert Left most */
        ptr->next = HEAD;
        HEAD->prev = ptr;
        HEAD = ptr;
        COUNT++;
        return HEAD;
    }
    else if(_N == COUNT || _N == -1){ /* append = insert Right most */
        CURR->next = ptr;
        ptr->prev = CURR;
        CURR = ptr;
        COUNT++;
        return HEAD;
    }
    else{   /* insert after nth element */
        node *ptr2 = HEAD;
        _N--;
        while(_N-- > 0)
            ptr2 = ptr2->next;

        ptr->prev = ptr2;
        ptr->next = ptr2->next;
        ptr2->next->prev = ptr;
        ptr2->next = ptr;
        COUNT++;
        return HEAD;
    }

}

int PrintDoublyList(){
    if(!COUNT)
        return 0; /* LIST empty */

    node *ptr = HEAD;
    printf("LEFT <-> ");
    while(ptr != NULL){
        printf("%d <-> ", ptr->val);
        ptr = ptr->next;
    }
    printf("RIGHT\nLEFT: %d\nRIGHT:%d\nCOUNT: %d\n\n", HEAD->val, CURR->val, COUNT);
    return 1;
}

int DeleteNode(int _N){
    if(COUNT == 0 || _N>COUNT || _N<1)
        return 0;

    node *ptr = HEAD;

    if(_N == 1){ /* remove HEAD node*/
        if(COUNT == 1){
            HEAD = NULL;
            CURR = NULL;
        }
        else{
            HEAD = HEAD->next;
            HEAD->prev = NULL;
        }
    }
    else if(_N == COUNT){ /* remove CURR(last node) */
        ptr = CURR;
        CURR = CURR->prev;
        CURR->next = NULL;
    }
    else{
        _N--;
        while(_N-- > 0)
            ptr = ptr->next;
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
    }
    free(ptr);
    COUNT--;
    return 1;
}

int DeleteDoublyList(){
    if(HEAD == NULL)
        return 1;
    node *ptr = HEAD;
    while(HEAD != NULL){
        HEAD = HEAD->next;
        free(ptr);
    }
    return 1;
}

int ReverseDoublyList(){
    if(COUNT == 0 || COUNT == 1)
        return 0;

    node *ptr;
    int i,
        j;

    for(i=COUNT; i>=0; i--){
            ptr = HEAD;
        for(j=0; j<i-1; j++){
            SWAP(ptr->val,ptr->next->val);
            ptr = ptr->next;
        }
    }
    return 1;
}
