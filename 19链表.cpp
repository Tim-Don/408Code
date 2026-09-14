//
// Created by Tim_Don on 26-9-11.
//

/**
 *
 *
 *
 *
 *
 *
 *****重新写**
 *
 *
 *
 *
 *
 *
 ******/

#include <iostream>

using namespace std;

typedef struct LNode {
    int data;
    struct LNode *next;
}LNode,*LinkList;

// 原地逆置 带头结点链表
void ReverseList(LinkList L){
    LNode *p = L->next;  // p指向第一个元素结点
    LNode *pre = NULL;
    LNode *r;            // 保存后继节点
    while(p != NULL){
        r = p->next;    // 先记下后面，防止断链
        p->next = pre;  // 反转指针，指向前面
        pre = p;
        p = r;
    }
    L->next = pre; // 头结点指向新的第一个结点（原链表最后一个）
}

void merge(LinkList L) {
    LinkList L2;
    LNode *p=L->next;
    LNode *q=L->next;
    while (p!=NULL && p->next!=NULL) {
        p=p->next->next;
        q=q->next;
    }
    L2->next=q->next;
    q->next=NULL;

    ReverseList(L2);

    p=L->next;
    q=L2->next;
    LNode *Ptemp;
    LNode *Qtemp;
    while (p!=NULL && q!=NULL) {
        Ptemp=p->next;
        Qtemp=q->next;
        p->next=q;
        q->next=Ptemp;
        p=Ptemp;
        q=Qtemp;
    }
}

int main() {


    return 0;
}