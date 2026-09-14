//
// Created by Tim_Don on 26-9-6.
//
#include "iostream"

using namespace std;

void QuickSort(int arr[], int left, int right) {
    if (left>=right) return ;
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
    QuickSort(arr, left,i-1);
    QuickSort(arr,i+1,right);
}

//笨蛋解，S1和S2合并成S3，快排后找中位数
int Merge(int S1[],int S2[],int n, int m) {
    int S3[n+m];
    for (int i=0;i<n;i++) {
        S3[i]=S1[i];
    }
    for (int i=0;i<m;i++) {
        S3[n+i]=S2[i];
    }
    for (auto i:S3) cout<<i<<" ";
    cout<<endl;
    QuickSort(S3,0,n+m-1);
    for (auto i:S3) cout<<i<<" ";
    cout<<endl;
    return S3[((n+m)-1)/2];
}

//多表指针
//用两个指针分别遍历两个有序数组，谁小谁移动
//注意边界处理
#define MAXSIZE 100
typedef struct SqList {
    int data[MAXSIZE];
    int length;
};

int Merge2(SqList A,SqList B) {
    int i=0,j=0,k=0;
    int mid=(A.length+B.length-1)/2;
    while (i<A.length && j<B.length) {
        if (A.data[i]<B.data[j]) {
            if (k==mid) return A.data[i];
            i++;
        }else {
            if (k==mid) return B.data[j];
            j++;
        }
        k++;
    }
    int gap=mid-k;
    if (i<A.length) return (A.data[i+gap]);
    if (j<B.length) return (B.data[j+gap]);
}

int main() {
    int n=5;
    int m=5;
    int S1[n]={11,13,15,17,19};
    int S2[m]={2,4,6,8,20};
    int res=Merge(S1,S2,n,m);
    cout<<res<<endl;

    SqList A={{11,13,15,17,19},5};
    SqList B={{2,4,6,8,20},5};

    int res2=Merge2(A,B);
    cout<<res2<<endl;




    return 0;
}