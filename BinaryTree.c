/*
-------------------------------------------------------------------------------
  AUTHOR:    _(Adesh Shah)
  DATE:      _(28JUL2015)
  URL:       _(NULL)
-------------------------------------------------------------------------------
  FILE:      _(BinaryTree.c)
  INFO:      _(Binary Tree operations)
  FUNCTION:  _(main,InsertInTree,PrintBinaryTree,PreOrderTravarse,
			   InOrderTravarse,PostOrderTravarse,DeleteBinaryTree)
-------------------------------------------------------------------------------
  CATEGORY:  _(linkedlist)
  TAGS:      _(binary,tree,doubly,linkedlist)
  LEVEL:     _(3)
-------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX(a,b) a>b?a:b

typedef struct _node{
    int val;
    struct _node *left,
                 *right;
} node;

node *ROOT = NULL;
int COUNT = 0;

int InsertInTree(int,node**);
void PrintBinaryTree_HTML(node*,FILE*);
void PrintBinaryTree_XML(node*,FILE*);
node* SearchBinaryTree(int,node*);
int PreOrderTravarse(node*);
int InOrderTravarse(node*);
int PostOrderTravarse(node*);
int DeleteBinaryTree(node*);
unsigned int HeightBinaryTree(node*);

int main(void){
    int Option = 1;
    int Value;
    FILE *fp;

    /* -> TEST ROUTINE
    InsertInTree(1,&ROOT);printf("Tree height: %d\n\n", HeightBinaryTree(ROOT));
    InsertInTree(2,&ROOT);printf("Tree height: %d\n\n", HeightBinaryTree(ROOT));
    InsertInTree(9,&ROOT);printf("Tree height: %d\n\n", HeightBinaryTree(ROOT));
    InsertInTree(4,&ROOT);printf("Tree height: %d\n\n", HeightBinaryTree(ROOT));
    InsertInTree(5,&ROOT);printf("Tree height: %d\n\n", HeightBinaryTree(ROOT));
    fp = fopen("BinaryTreeHTML.html", "w");
    PrintBinaryTree_HTML(ROOT,fp);
    fclose(fp);
    DeleteBinaryTree(ROOT);
    */

    Option = 0;
    do{
        printf("1) Insert in BinaryTree\n2) Print BinaryTree\n3) Pre-order travarse\n4) In-order travarse\n5) Post-order travarse\n6) Print Height of B.Tree\n0) Exit program\n");
        scanf("%d", &Option);

        switch(Option){
            case 1:
                printf("Enter a value: ");
                scanf("%d", &Value);
                if(InsertInTree(Value,&ROOT) == 0)
                    printf("Error inserting node\n\n");
                break;
            case 2:
                fp = fopen("BinaryTreeXML.txt", "w");
                PrintBinaryTree_HTML(ROOT,fp);
                fclose(fp);
                break;
            case 3:
                PreOrderTravarse(ROOT);
                break;
            case 4:
				InOrderTravarse(ROOT);
				break;
			case 5:
				PostOrderTravarse(ROOT);
				break;
			case 6:
				Value = HeightBinaryTree(ROOT);
				printf("Tree height: %d\n\n", Value);
				break;
            case 0:
                DeleteBinaryTree(ROOT);
                break;
            default:
                printf("Enter a valid choice\n\n");
        }
    }while(Option);
    return 1;
}

int InsertInTree(int _Val, node **_Ptr){
	if(*_Ptr == NULL){
		*_Ptr = (node*)malloc(sizeof(node));
		if(*_Ptr == NULL)
			return 0;
		(*_Ptr)->val = _Val;
		(*_Ptr)->right = NULL;
		(*_Ptr)->left = NULL;
		return 1;
	}
	else if(_Val < (*_Ptr)->val)
		return InsertInTree(_Val, &(*_Ptr)->left);
	else if(_Val > (*_Ptr)->val)
		return InsertInTree(_Val, &(*_Ptr)->right);
    else if(_Val == (*_Ptr)->val)
        return 0;   /* same value not allowed in binary tree */
}

node* SearchBinaryTree(int _Val, node *_Ptr){
	if(_Val == _Ptr->val)
		return _Ptr;

	if(_Val < _Ptr->val)
		return SearchBinaryTree(_Val, _Ptr->left);
	else if(_Val > _Ptr->val)
		return SearchBinaryTree(_Val, _Ptr->right);
	return NULL;
}

int PreOrderTravarse(node *_Ptr){

}

int InOrderTravarse(node *_Ptr){

}

int PostOrderTravarse(node *_Ptr){

}

int DeleteBinaryTree(node* _Ptr){
  if(_Ptr != NULL){
      DeleteBinaryTree(_Ptr->left);
      DeleteBinaryTree(_Ptr->right);
      free(_Ptr);
	  return 1;
  }
  return 0;
}

unsigned int HeightBinaryTree(node *_Ptr){
    unsigned int height = 0;
    if (_Ptr) {
        if (_Ptr->left || _Ptr->right) {
            unsigned int leftheight = 0,
                         rightheight = 0;

            if (_Ptr->left)
                leftheight = HeightBinaryTree(_Ptr->left);
            if (_Ptr->right)
                rightheight = HeightBinaryTree(_Ptr->right);

            if (leftheight > rightheight)
                height = leftheight + 1;
            else
                height = rightheight + 1;
        }
    }
    return height;
}

void PrintBinaryTree_XML(node *_Ptr, FILE *fp){
    if(_Ptr != NULL){
        if(_Ptr == ROOT){
            fprintf(fp,"<xml>\n");
            fprintf(fp,"<node type='ROOT' value='%d'>\n", _Ptr->val);
        }

        /* left child node */
        if(_Ptr->left == NULL)
                fprintf(fp,"<node type='Left' value='NULL'>\n");
        else{
                fprintf(fp, "<node type='Left' value='%d'>\n", _Ptr->left->val);
                PrintBinaryTree_XML(_Ptr->left,fp);
        }
        fprintf(fp,"</node>\n");

        /* right node */
        if(_Ptr->right == NULL)
            fprintf(fp, "<node type='Right' value='NULL'>\n");
        else{
            fprintf(fp,"<node type='Right' value='%d'>\n", _Ptr->right->val);
            PrintBinaryTree_XML(_Ptr->right,fp);
        }
        fprintf(fp,"</node>\n");
    }

    if(_Ptr == ROOT){
        fprintf(fp,"</node>\n");    /* close ROOT node */
        fprintf(fp,"</xml>\n");
    }
}

void PrintBinaryTree_HTML(node *_Ptr, FILE *fp){
    fprintf(fp,"<html><html><head><style>.nodeVal{position:relative;padding:5px;margin:5px;height:50px;width:50px;text-align:center;line-height: 50px;border:1px Solid #ADADAD;background:#f1f1f1;}.nodeROOT,.nodeLeft,.nodeRight{padding:5px 5px 5px 15px;margin:5px 5px 5px 15px;clear:both;}.nodeLeft{border-left:1px Solid Red;}.nodeRight{border-left:1px Solid Blue;}</style></head><body><div>");
    if(_Ptr != NULL){
        if(_Ptr == ROOT){
            fprintf(fp,"<div class='BinaryTree'>\n");  /* XML start */
            fprintf(fp,"<div class='nodeROOT'><div class='nodeVal'>%d</div>\n",_Ptr->val);
        }

        /* left child node */
        if(_Ptr->left == NULL)
                fprintf(fp,"<div class='nodeLeft'><div class='nodeVal'>NULL</div>\n");
        else{
                fprintf(fp, "<div class='nodeLeft'><div class='nodeVal'>%d</div>\n", _Ptr->left->val);
                PrintBinaryTree_HTML(_Ptr->left,fp);
        }
        fprintf(fp,"</div>\n");

        /* right node */
        if(_Ptr->right == NULL)
            fprintf(fp, "<div class='nodeRight'><div class='nodeVal'>NULL</div>\n");
        else{
            fprintf(fp,"<div class='nodeRight'><div class='nodeVal'>%d</div>\n", _Ptr->right->val);
            PrintBinaryTree_HTML(_Ptr->right,fp);
        }
        fprintf(fp,"</div>\n");
    }

    if(_Ptr == ROOT){
        fprintf(fp,"</div>\n");    /* close ROOT node */
        fprintf(fp,"</div>\n"); /* XML end */
    }
    fprintf(fp,"</div></body></html>");

}

