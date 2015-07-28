#include <stdio.h>
#include <stdlib.h>

#define SWAP(a,b)   do{                     \
                     if(a!=b){              \
                       a^=b; b^=a; a^=b;    \
                     }                      \
                    }while(0)               \

typedef struct _node{
    int val;
    struct _node *next;
} node;

node *head = NULL,
     *curr = NULL;

/* functions */
int Print_LinkedList();                /* return 1 on success */
node* Create_Linked_list(int);
node* Append_Linked_list(int);
node* Prepend_Linked_list(int);
int Search_Linked_list(int, node**); /* pass **prev to get prev element address */
node* Delete_Node(int);                /* delete the first found element */
node* Reverse_Linked_list();
int Length_Of_Linked_list();
int Delete_Linked_list();

int main(void){
    int Option = 1;
    int Value;
    while(Option){
        printf("1) Create linked-list\n2) Append linked-list\n3) Prepend linked-list\n4) Length Of linked-list\n5) Delete a node\n6) Reverse linked-list\n7) Delete linked-list\n8)Print linked-list\n0) Exit program\n");
        scanf("%d", &Option);

        switch(Option){
            case 1:
                printf("Enter a value: ");
                scanf("%d", Value);
                Create_Linked_list(Value);
                printf("Linked-list created\n\n");
                break;
            case 2:
                printf("Enter a value: ");
                scanf("%d", Value);
                Append_Linked_list(Value);
                printf("Value appended to Linked-list\n\n");
                break;
            case 3:
                printf("Enter a value: ");
                scanf("%d", Value);
                Prepend_Linked_list(Value);
                printf("Value prepended to Linked-list\n\n");
                break;
            case 4:
                Value = Length_Of_Linked_list();
                printf("Linked-list length: %d\n\n", Value);
                break;
            case 5:
                printf("Enter a value: ");
                scanf("%d", Value);
                Delete_Node(Value);
                printf("Value deleted from linked-list\n\n");
                break;
            case 6:
                Reverse_Linked_list();
                printf("Linked-list reversed\n\n");
                break;
            case 7:
                Delete_Linked_list();
                printf("Linked-list deleted\n\n");
                break;
            case 8:
                Print_LinkedList();
                break;
            case 0:
                Delete_Linked_list();
                break;
            default:
                printf("Enter a valid choice\n\n");
        }
    }
    return 1;
}

int Print_LinkedList(){
    node *ptr = head;
    while(ptr != NULL){
        printf("%d(%p) -> ", ptr->val, ptr);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
node* Create_Linked_list(int _val){
    if(head != NULL)
        return;

    node *ptr = (node*)malloc(sizeof(node));
    if(ptr == NULL)
        return; /* or print "error creating node\n" */
    ptr->val = _val;
    ptr->next = NULL;

    head = curr = ptr;

    return head;
}
node* Append_Linked_list(int _val){
    if(head == NULL)
        return Create_Linked_list(_val);

    node *ptr = (node*)malloc(sizeof(node));
    if(ptr == NULL)
        return;
    ptr->val = _val;
    ptr->next = NULL;

    curr->next = ptr;
    curr = ptr;

    return head;
}
node* Prepend_Linked_list(int _val){
    if(head == NULL)
        return Create_Linked_list(_val);

    node *ptr = (node*)malloc(sizeof(node));
    if(ptr == NULL)
        return;
    ptr->val = _val;
    ptr->next = head;

    head = ptr;

    return head;
}
int Search_Linked_list(int _val, node **_prev){
    node *ptr;

    ptr = head;

    if(head->val == _val)
        return 1;   /* found but no prev node (prev == NULL) */

    while(ptr->next != NULL){
        if(ptr->val == _val){
            return 1;
        }
        _prev = ptr;
        ptr = ptr->next;
    }

    return 0; /* not found */
}
node* Delete_Node(int _val){
    node **prev = NULL,
         *ptr = NULL;
    if(!Search_Linked_list(_val, prev))
        return;

    if(head->val == _val){  /* or prev==NULL */
        ptr = head;
        head = head->next;
        free(ptr);
    }
    else if(curr->val == _val){
        ptr = curr;
        curr = (*prev);
        curr->next = NULL;
        free(ptr);
    }
    else{
        ptr = (*prev)->next;
        (*prev)->next = ptr->next;
        free(ptr);
    }

    return head;
}
int Length_Of_Linked_list(){
    node *ptr = head;
    int Length = 0;

    while(ptr->next != NULL)
        Length++;

    return Length;
}
node* Reverse_Linked_list(){
    int Len, i, j;
    node *ptr;

    Len = Length_Of_Linked_list();
    if(Len == 1)
        return head;

    for(i=Len-1; i<=0; i--){
        ptr = head;
        for(j=0; j<i-1; j++){
            node *ptr2 = ptr->next;
            SWAP(ptr->val,ptr2->val);
        }
        ptr = ptr->next;
    }

    return head;
}
int Delete_Linked_list(){

    return 1;
}
