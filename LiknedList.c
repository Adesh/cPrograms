#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int val;
    struct _node *next;
} node;

node *HEAD = NULL;   /* GLOBAL variable */

node* Create_LinkedList(int, node*);
node* Append_LinkedList(int, node*);
node* Prepend_LinkedList(int, node*);
node* Delete_Node(int, node*);
node* Reverse_LinkedList(node*);
int Length_Of_LinkedList(node*);
int Delete_LinkedList(node*);
int Print_LinkedList(node*);
int Search_LinkedList(int, node*, node**);
node* Last_Node(node*);

int main(void){
    int Option = 1;
    int Val;
    while(Option){
        printf("1) Create linked-list\n2) Append linked-list\n3) Prepend linked-list\n4) Length Of linked-list\n5) Delete a node\n6) Reverse linked-list\n7) Delete linked-list\n8)Print linked-list\n0) Exit program\n");
        scanf("%d", &Option);

        switch(Option){
            case 1:
                printf("Enter a value: ");
                scanf("%d", Val);
                Create_LinkedList(Val, HEAD);
                printf("Linked-list created\n\n");
                break;
            case 2:
                printf("Enter a value: ");
                scanf("%d", Val);
                HEAD = Append_LinkedList(Val, HEAD);
                printf("Value appended to Linked-list\n\n");
                break;
            case 3:
                printf("Enter a value: ");
                scanf("%d", Val);
                HEAD = Prepend_LinkedList(Val, HEAD);
                printf("Value prepended to Linked-list\n\n");
                break;
            case 4:
                Val = Length_Of_LinkedList(HEAD);
                printf("Linked-list length: %d\n\n", Val);
                break;
            case 5:
                printf("Enter a value: ");
                scanf("%d", Val);
                HEAD = Delete_Node(Val, HEAD);
                printf("Value deleted from linked-list\n\n");
                break;
            case 6:
                HEAD = Reverse_LinkedList(HEAD);
                printf("Linked-list reversed\n\n");
                break;
            case 7:
                Delete_LinkedList(HEAD);
                printf("Linked-list deleted\n\n");
                break;
            case 8:
                Print_LinkedList(HEAD);
                break;
            case 0:
                Delete_LinkedList(HEAD);
                break;
            default:
                printf("Enter a valid choice\n\n");
        }
    }
    return 1;
}

node* Create_LinkedList(int _Value, node *_Head){
    if(_Head != NULL)
        return NULL;

    node *ptr = (node*)malloc(sizeof(node));
    if(ptr == NULL)
    {
        printf("Node creation failed\n\n");
        return NULL;
    }
    ptr->val = _Value;
    ptr->next = NULL;

    _Head = ptr;
    return _Head;
}

node* Append_LinkedList(int _Value, node *_Head){
    if(_Head == NULL)
        return (Create_LinkedList(_Value, _Head));

    node *ptr = (node*)malloc(sizeof(node));
    if(ptr == NULL)
    {
        printf("Node creation failed\n\n");
        return NULL;
    }
    ptr->val = _Value;
    ptr->next = NULL;

    node* ptr2 = Last_Node(_Head);
    ptr2->next = ptr;

    return _Head;
}

node* Prepend_LinkedList(int _Value, node *_Head){
    if(_Head == NULL)
    {
        _Head = Create_LinkedList(_Value, _Head);
        return (_Head);
    }

    node *ptr = (node*)malloc(sizeof(node));
    if(ptr == NULL)
    {
        printf("Node creation failed\n\n");
        return NULL;
    }
    ptr->val = _Value;
    ptr->next = NULL;

    ptr->next = _Head;
    _Head = ptr;

    return ptr;
}

node* Delete_Node(int _Value, node *_Head){
    node *prev = NULL,
         *del = NULL,
         *curr = Last_Node(_Head);

    int found = Search_LinkedList(_Value, _Head, &prev);

    if(found){
        if(prev == NULL){
            //head node to be deleted
            del = _Head;
            _Head = _Head->next;
        }
        else{
            if(prev->next == curr){
                //last node to be deleted
                del = curr;
                curr = prev;
                curr->next = NULL;
            }
            else{
                //middle node to be deleted
                del = prev->next;
                prev->next = del->next;
            }
        }
    }

    free(del);
    del = NULL;

    return _Head;
}

node* Reverse_LinkedList(node *_Head){

}

int Length_Of_LinkedList(node *_Head){
    int Length = 0;
    node *ptr = _Head;
    while(ptr->next != NULL)
        Length++;

    return Length;
}

int Delete_LinkedList(node* _Head){
    //delete and at last
    _Head = NULL;
}

int Print_LinkedList(node *_Head){
    node *ptr = _Head;
    while(ptr->next != NULL){
        printf("%d(%p) -> ", ptr->val, ptr);
        ptr = ptr->next;
    }
    printf("NULL\n\n");

    return 1;
}

int Search_LinkedList(int _Value, node *_Head, node **Prev){
    node *ptr = _Head;

    if(ptr->val == _Value)
        return 0;

    while(ptr->next != NULL){
        if(ptr->next->val == _Value){
            *Prev = ptr;
            return 1;
        }
        ptr = ptr->next;
    }

    return 0;
}

node* Last_Node(node *_Head){
    node *ptr = _Head;
    while(ptr->next != NULL)
        ptr = ptr->next;

    return ptr;
}
