//
// Created by Tim_Don on 26-9-9.
//
#include<iostream>

using namespace std;

typedef struct LNode {
    int data;
    struct LNode *next;
}LNode,*LinkList;

int Abs(int num) {
    if (num < 0) return -num;
    else return num;
}

void func(LinkList &L,int n) {
    int aux[n+1]={0};
    int temp=0;
    LNode *p=L;
    while (p->next!=NULL) {
        temp=Abs(p->next->data);
        if (aux[temp]==0) {
            aux[temp]=1;
            p=p->next;
        }else {
            LNode *q=p->next;
            p->next=q->next;
            free(q);
        }
    }
}

int main() {



    return 0;
}