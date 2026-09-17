//
// Created by Tim_Don on 2026/9/17.
//
#include <iostream>
#define MAXSIZE 100

using namespace std;

typedef int ElemType;

typedef struct BiTNode{
    ElemType data;
    BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

typedef BiTNode *QElemType;

typedef struct Queue{
    QElemType data[MAXSIZE];
    int front,rear;
}Queue;

int DFS_CountNode(BiTree T){
    int lcnt=0,rcnt=0;
    if(T==NULL) return 0;
    lcnt=DFS_CountNode(T->lchild);
    rcnt=DFS_CountNode(T->rchild);
    return lcnt+rcnt+1;
}

void InitQueue(Queue &Q){
    Q.front=Q.rear=0;
}

bool IsEmpty(Queue Q){
    return Q.front==Q.rear;
}

bool EnQueue(Queue &Q, QElemType x){
    if((Q.rear+1)%MAXSIZE==Q.front) return false;
    Q.data[Q.rear]=x;
    Q.rear=(Q.rear+1)%MAXSIZE;
    return true;
}

bool DeQueue(Queue &Q, QElemType &x){
    if(IsEmpty(Q)) return false;
    x=Q.data[Q.front];
    Q.front=(Q.front+1)%MAXSIZE;
    return true;
}

int BFS_CountNode(BiTree T){
    BiTNode *p=T;
    int cnt=0;
    Queue Q;
    InitQueue(Q);
    EnQueue(Q,p);
    while(!IsEmpty(Q)){
        DeQueue(Q,p);
        cnt++;
        if(p->lchild) EnQueue(Q,p->lchild);
        if(p->rchild) EnQueue(Q,p->rchild);
    }
    return cnt;
}

int main(){
    BiTNode n1={1,NULL,NULL};
    BiTNode n2={2,NULL,NULL};
    BiTNode root={10,&n1,&n2};
    cout << DFS_CountNode(&root) << ' '; // 输出3，正确

    cout << BFS_CountNode(&root);

    return 0;
}