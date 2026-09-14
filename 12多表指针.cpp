//
// Created by Tim_Don on 26-9-7.
//
#include "iostream"
#define MAXSIZE 100

using namespace std;

typedef struct LNode {
    char data;
    struct LNode *next;
}LNode,*LinkList;

//暴力解
LNode* BF(LinkList str1, LinkList str2) {
    LNode *p = str1->next;
    LNode *q = str2->next;
    while (p!=NULL) {
        while (q!=NULL) {
            if (p==q) return q;
            q = q->next;
        }
        p=p->next;
    }
    return NULL;
}

//多表指针
int len(LinkList str) {
    LNode *p=str->next;
    int cnt=0;
    while (p!=NULL) {
        cnt++;
        p=p->next;
    }
    return cnt;
}

LNode* Search(LinkList L1, LinkList L2) {
    int len1 = len(L1);
    int len2 = len(L2);
    int dist;
    LNode *LongList,*ShortList;
    if (len1>len2) {
        LongList=L1->next;
        ShortList=L2->next;
        dist=len1-len2;
    }else {
        LongList=L2->next;
        ShortList=L1->next;
        dist=len2-len1;
    }
    while (dist--) {
        LongList=LongList->next;
    }
    while (LongList!=NULL) {
        if (LongList==ShortList) return LongList;
        else {
            LongList=LongList->next;
            ShortList=ShortList->next;
        }
    }
    return NULL;
}

int main() {
    LinkList L;


    return 0;
}