//
// Created by Tim_Don on 26-8-31.
//
#include<iostream>
using namespace std;

void QuickSort(int arr[],int left,int right) {
    if (left>=right) return;
    int i=left, j=right;
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

int main() {
    int arr[7]={24,5,77,12,30,1,55};
    QuickSort(arr, 0, 6);
    for (int i=0; i<7; i++) {
        cout<<arr[i]<<endl;
    }



    return 0;
}