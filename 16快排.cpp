//
// Created by Tim_Don on 26-9-3.
//
#include <vector>

#include "iostream"

using namespace std;

void QuickSort(int arr[], int left, int right) {
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
    QuickSort(arr, left, i-1);
    QuickSort(arr, i+1, right);
}

int main() {
    int n=10;
    int arr[n]={3,1,4,5,2,4,8,9,7,1};
    QuickSort(arr, 0, n-1);
    int A1[n/2];
    int A2[n/2];

    for (int i=0;i<n;i++) {
        if (i<n/2) A1[i]=arr[i];
        else A2[i-n/2]=arr[i];
    }

    for (auto i:A1) cout<<i<<" ";
    cout<<endl;
    for (auto i:A2) cout<<i<<" ";


    return 0;
}