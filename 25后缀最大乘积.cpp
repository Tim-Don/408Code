//
// Created by Tim_Don on 26-9-15.
//
#include <iostream>

using namespace std;

void BF_calMulMax(int A[], int res[], int n) {
    int max=INT_MIN;
    int num;
    for (int i = 0; i < n; i++) {
        max=INT_MIN;
        for (int j = i; j < n; j++) {
            num=A[i]*A[j];
            if (num>max) max=num;
        }
        res[i]=max;
    }
}

//先逆置，用前缀和/积处理，处理后再逆置res
//维护一个已经遍历过了的最大值和最小值，因为当前元素一定是和最大最小值相乘才能得到最大值
//（最小值是当前元素是负数乘一个是负数的最小值，得到的值更大）

void Reverse_calMulMax(int A[], int res[], int n) {
    int max=INT_MIN;
    int min=INT_MAX;

    for (int i=0;i<n/2;i++) {
        int tmp=A[i];
        A[i]=A[n-i-1];
        A[n-i-1]=tmp;
    }
    for (int j=0;j<n;j++) {
        if (A[j]>max) max=A[j];
        if (A[j]<min) min=A[j];
        if (A[j]*min > A[j]*max) res[j]=A[j]*min;
        else res[j]=A[j]*max;
    }
    //res是逆置的，所以需要逆回来
    for (int i=0;i<n/2;i++) {
        int tmp=res[i];
        res[i]=res[n-i-1];
        res[n-i-1]=tmp;
    }
}

//不使用逆置，直接做后缀积
void calMulMax(int A[], int res[], int n) {
    int max=INT_MIN;
    int min=INT_MAX;
    for (int i=n-1;i>=0;i--) {
        if (A[i]>max) max=A[i];
        if (A[i]<min) min=A[i];
        if (A[i]*min > A[i]*max)
            res[i]=A[i]*min;
        else res[i]=A[i]*max;
    }
}

int main() {
    int A[4]={1,4,-9,6};
    int res[4];
    BF_calMulMax(A, res, 4);
    for (auto i: res)
        cout<<i<<' ';
    cout<<endl;

    int res3[4];
    calMulMax(A, res3, 4);
    for (auto i: res3)
        cout<<i<<' ';
    cout<<endl;

    //Reverse_calMulMax执行后会修改A的顺序
    int res2[4];
    Reverse_calMulMax(A, res2, 4);
    for (auto i: res2)
        cout<<i<<' ';
    cout<<endl;



    return 0;
}