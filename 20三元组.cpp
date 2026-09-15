//
// Created by Tim_Don on 26-9-12.
//
#include<iostream>

#define Abs(x) ((x)>0 ? (x) : -(x))

using namespace std;

//暴力解
int BF(int S1[], int S2[], int S3[], int m, int n, int p) {
    int min = INT_MAX;
    int Dist;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < p; k++) {
                Dist=Abs(S1[i]-S2[j])+Abs(S2[j]-S3[k])+Abs(S3[k]-S1[i]);
                if (Dist<min)
                    min=Dist;
            }
        }
    }
    return min;
}


//多表指针
//因为三个数组内有序，只需要每次都移动最小的一个元素的指针，就能逼近另外两个
int func(int S1[], int S2[], int S3[], int m, int n, int p) {
    int min = INT_MAX;
    int Dist;
    int i=0,j=0,k=0;
    while (i<m && j<n && k<p && min>0) {
        Dist=Abs(S1[i]-S2[j])+Abs(S2[j]-S3[k])+Abs(S3[k]-S1[i]);
        if (Dist<min) min=Dist;
        if (S1[i]<=S2[j] && S1[i]<=S3[k]) i++;
        else if (S2[j]<=S1[i] && S2[j]<=S3[k]) j++;
        else k++;
    }
    return min;
}


int main() {

    int S1[3]={-1,0,9};
    int S2[4]={-25,-10,10,11};
    int S3[5]={2,9,17,30,41};
    int m=3,n=4,p=5;
    int res=BF(S1, S2, S3, m, n, p);
    cout<<res<<endl;

    int res2=func(S1, S2, S3, m, n, p);
    cout<<res2<<endl;

    return 0;
}