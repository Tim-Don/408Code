//
// Created by Tim_Don on 26-9-5.
//
#include "iostream"

using namespace std;

//三次翻转最优解
void reverse(int arr[], int left ,int right) {
    if (left>=right) return;
    int temp;
    while (left < right) {
        temp=arr[left];
        arr[left]=arr[right];
        arr[right]=temp;
        left++;
        right--;
    }
}

void opshift (int arr[], int n, int p) {
    if (p<=0 || p>=n) return;
    reverse(arr, 0, p-1);
    reverse(arr, p, n-1);
    reverse(arr, 0, n-1);
}

//time:O(n^2),space:O(n) 拼接
void BF(int arr[], int n,int p) {
    if (p<=0 || p>=n) return;
    int aux_arr[n]; int j=0;
    for (int i=0;i<n;i++) {
        if (i<p) aux_arr[i]=arr[i];
        else arr[j++]=arr[i];
    }
    for (int i=0;i<p;i++) {
        arr[j++]=aux_arr[i];
    }
}

//每次循环把数组第一个元素保存，其余元素全部向前移动 1 位，把保存的元素放到数组末尾；循环执行 p 次完成左移。
//time:O(n^2),space:O(1)
void BF2(int arr[], int n, int p) {
    for (int i=0;i<p;i++) {
        int temp=arr[i];
        for (int j=0;j<n-1;j++) {
            arr[j]=arr[j+1];
        }
        arr[n-1]=temp;
    }
}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    // opshift(arr,10,1);
    BF2(arr,10,3);

    for (int i=0;i<10;i++) {
        printf("%d ",arr[i]);
    }

    return 0;
}