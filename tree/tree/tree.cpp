#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
 
 
class TREE{
public:
    struct tree{
        int data;
        int view;//для обхода дерева
        struct tree *Left;
        struct tree *Right;
        struct tree *Prev;//для стека
    };
struct tree *Work;
struct tree *Root;
 
void Create(int i);
void PushTree(int i);
void PrintTree();
void DeleteTree();

int getMaxDepth(tree* tree, int depth) {
	if (tree == NULL)
		return depth;
	return max(getMaxDepth(tree->Left, depth + 1), getMaxDepth(tree->Right, depth + 1));
}
 
private: void CreateStack(void);
         struct tree *top;
         void PushStack(struct tree *a);
         void PopStack();
		 int max(int a, int b) {
			 if (a > b) return a;
			 return b;
		 }
};
 
void TREE::CreateStack(void){
    Root->Prev=NULL;
    top=Root;
}
 
 void TREE::PushStack(struct tree *a){
     a->Prev=top;
     top=a;
 }
 
 void TREE::PopStack(){
     top=top->Prev;
 }
 
void TREE::Create(int i){
    Work=(struct tree*)malloc(sizeof(struct tree));
    Work->Left=NULL;
    Work->Right=NULL;
    Work->data=i;
    Work->view=-1;
    Root=Work;
}
 
void TREE::PushTree(int i){
    Work=Root;
    while(Work!=NULL){//Поиск листа для добавления
        if(i<Work->data){
            if(Work->Left==NULL){
                break;
            }
            Work=Work->Left;
        }
    else{
        if(Work->Right==NULL){
            break;
        }
        Work=Work->Right;
        }
    }
//Добавление нового узла
    if(i<Work->data){//Левый сын
        Work->Left=(struct tree*)malloc(sizeof(struct tree));
        Work=Work->Left;
        Work->Left=NULL;
        Work->Right=NULL;
        Work->data=i;
        Work->view=-1;
    }
    else{//Правый сын
        Work->Right=(struct tree*)malloc(sizeof(struct tree));
        Work=Work->Right;
        Work->Left=NULL;
        Work->Right=NULL;
        Work->data=i;
        Work->view=-1;
    }
}
 
void CreateTree(TREE &BST){ 
    srand(time(NULL));
    int i;
    i=rand()%20+1;
    printf("%s%d","Data: ",i);
    BST.Create(i);//Создаем корень
    for(int j=0; j<9; j++){//Остальные узлы
        i=rand()%20+1;
        BST.PushTree(i);
        printf("%  d",i);
    }
}
 
void TREE::PrintTree(){
    printf("\n\n");
    CreateStack();
    int i=0;
    while(top!=NULL){
        while(top->Right!=NULL&&top->Right->view!=0){
            PushStack(top->Right); 
            i++;
        }
        if(top->view==-1){
            for(int j=i; j>0; j--){
                printf("\t");
            }
            printf(" %d\n",top->data);
            top->view=0;//0-напечатана, -1-не напечатана
        }
        if(top->Left!=NULL&&top->Left->view==-1){
            PushStack(top->Left); 
            i++; 
            continue;
        }
        PopStack();
        i--;
    }
}
 
void TREE::DeleteTree(){
    CreateStack();
    int i=0;
    while(top!=NULL){
        while(top->Right!=NULL){
            Work=top;
            PushStack(top->Right);
            Work->Right=NULL;
        }
        if(top->Left!=NULL){
            Work=top;
            PushStack(top->Left); 
            Work->Left=NULL;
            continue;
        }
        if(top->Left==NULL&&top->Right==NULL){
            Work=top;
            PopStack();
            free(Work);
        }
    }
}
 
void main(){
    TREE BST;
    CreateTree(BST);
	BST.PrintTree();
    BST.DeleteTree();
}