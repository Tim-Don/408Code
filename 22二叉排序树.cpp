//
// Created by Tim_Don on 2026/9/16.
//
#include <iostream>

using namespace std;

//// 结构体定义，和题目保持一致
//#define MAXSIZE 100
//
//typedef struct{
//    int SqBiTNode[MAXSIZE];
//    int ElemNum;
//}SqBiTree;
//
//// k：当前结点数组下标；pre：引用保存中序前驱的值
//bool JudgeBST(SqBiTree T, int k, int &pre) {
//    int n = T.ElemNum;
//    // 【修改】先判断k不越界，再读取结点值，防止数组越界
//    if (k < n) {
//        int cur_node = T.SqBiTNode[k];
//        if (cur_node != -1) { // 当前结点不是空结点
//            // 递归检查左子树
//            if (!JudgeBST(T, 2 * k + 1, pre)) {
//                return false;
//            }
//            // BST中序必须严格大于前驱
//            if (cur_node <= pre) {
//                return false;
//            }
//            pre = cur_node;
//            // 递归检查右子树
//            if (!JudgeBST(T, 2 * k + 2, pre)) {
//                return false;
//            }
//        }
//    }
//    // k越界 或者 当前结点是-1空结点，返回true
//    return true;
//}
//
//// 对外调用入口函数
//bool IsBST(SqBiTree T){
//    int pre = INT_MIN;
//    return JudgeBST(T,0,pre);
//}

#define MAX_SIZE 100

typedef struct SqBiTNode{
    int SqBiTNode[MAX_SIZE];
    int ElemNum;
}SqBiTree;

bool JudgeBST(SqBiTree T, int k, int &pre){
    int n=T.ElemNum;
    if(k<n){
        int cur_node=T.SqBiTNode[k];
        if(cur_node!=-1){//当前节点不是空节点
            //递归遍历左子树
            if(!JudgeBST(T,k*2+1,pre)){
                return false;
            }
            if(cur_node<=pre) return false;
            pre=cur_node;
            if(!JudgeBST(T,k*2+2,pre)){
                return false;
            }
        }
    }
    return true;
}

bool IsBST(SqBiTree T){
    int pre=INT_MIN;
    return JudgeBST(T,0,pre);
}

int main(){


    return 0;
}