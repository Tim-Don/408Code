//
// Created by Tim_Don on 26-9-8.
//
#include "iostream"

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

int BF(int arr[], int n) {
    QuickSort(arr,0,n-1);
    int cnt=1;
    for (int i=0; i<n; i++) {
        if (arr[i]==arr[i+1]) cnt++;
        else cnt=1;
        if (cnt>n/2) return arr[i];
    }
    return -1;
}

//辅助空间
int func(int arr[],int n) {
    int aux[n]={0};
    for(int i=0;i<n;i++) {
        aux[arr[i]]++;
        if (aux[arr[i]]>n/2)
            return arr[i];
    }
    return -1;
}

int main() {

    int n=10;
    int A[n]={0,5,5,5,5,5,4,3,2,5};
    int B[n]={0,5,5,5,5,5,4,3,2,3};
    int res=func(A,n);
    int BF_res=BF(B,n);
    cout<<res<<endl;
    cout<<BF_res<<endl;

    return 0;
}