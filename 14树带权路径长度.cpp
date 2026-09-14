//
// Created by Tim_Don on 26-9-8.
//
#include<iostream>

using namespace std;

typedef struct BTNode {
    int weight;
    struct BTNode *left,*right;
}BTNode,*BTree;

int func(BTree root,int deep) {
    if (root==NULL) return 0;
    int left,right;
    if (root->left==NULL && root->right==NULL) return deep*(root->weight);
    left=func(root->left,deep+1);
    right=func(root->right,deep+1);
    return left+right;
}

BTNode* CreatBTNode(int weight) {
    BTNode *p=(BTNode*)malloc(sizeof(BTNode));
    p->weight=weight;
    p->left=NULL;
    p->right=NULL;
    return p;
}

int main() {
    BTree root=CreatBTNode(10);
    root->left=CreatBTNode(20);
    root->right=CreatBTNode(30);
    int wpl=func(root,1);
    cout<<wpl<<endl;

    return 0;
}