//
// Created by Tim_Don on 2026/9/15.
//
#include <iostream>

using namespace std;

typedef struct LNode{
    int data;
    LNode *next;
}LNode,*LinkList;

int Search_K(LinkList L, int k){
    if(k<=0 || L->next==NULL) return 0;
    LNode *p=L->next;
    LNode *q=L->next;
    while(p!=NULL && k!=0){
        p=p->next;
        k--;
    }
    if(k!=0) return 0; //链表中元素节点不足k个
    while(p!=NULL){
        p=p->next;
        q=q->next;
    }
    cout << q->data << endl;
    return 1;
}

int main(){


    return 0;
}