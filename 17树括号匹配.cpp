//
// Created by Tim_Don on 26-9-9.
//
#include<iostream>

using namespace std;

typedef struct BTNode {
    char data[10];
    struct BTNode *left, *right;
}BTNode,*BTree;


void func(BTree T, int deep) {
    if (T != NULL) {
        if (deep != 0 && (T->left || T->right)) {
            cout << '(';
        }
        if (T->left) func(T->left, deep + 1);
        cout << T->data;
        if (T->right) func(T->right, deep + 1);
        if (deep != 0 && (T->left || T->right)) {
            cout << ')';
        }
    }
}

int main() {


    return 0;
}