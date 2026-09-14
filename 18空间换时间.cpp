//
// Created by Tim_Don on 26-9-10.
//
#include <iostream>

using namespace std;

//笨蛋解快排
void QuickSort(int arr[],int left, int right) {
    if (left>=right) return;
    int i=left,j=right;
    int pivot=arr[left];
    while (i<j) {
        while (i<j && arr[j]>=pivot) j--;
        while (i<j && arr[i]<=pivot) i++;
        if (i<j) {
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    arr[left]=arr[i];
    arr[i]=pivot;
    QuickSort(arr,left,i-1);
    QuickSort(arr,i+1,right);
}

int func(int arr[],int n) {
    int min=1;
    QuickSort(arr,0,n-1);
    for (int i=0;i<n;i++) {
        if (arr[i]>0) {
            if (arr[i]!=min) return min;
            min++;
        }
    }
}

//正解空间换时间
int func2(int arr[],int n) {
    int aux[n+1]={0};
    for (auto i:aux)    cout<<i<<" ";
    cout<<endl;
    for (int i=0;i<n;i++) {
        if (arr[i]>0) {
            aux[arr[i]]=1;
        }
    }
    for (int i=1;i<n;i++) {
        if (aux[i]==0)
            return i;
    }
    return -1; //所有正数都有
}

int main() {
    int arr[4]={-5,3,2,3};

    int arr3[4]={-5,3,2,3};
    int n=4;
    int max_num=3;

    int res=func(arr,n);
    cout<<res<<endl;

    int res3=func2(arr3,max_num);
    cout<<res3<<endl;

    return 0;
}