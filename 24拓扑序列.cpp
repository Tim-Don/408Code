//
// Created by Tim_Don on 26-9-16.
//
#include<iostream>
#define MAXV 100

using namespace std;

typedef struct MGraph {
    int numVertex,numEdge;
    char VertexList[MAXV];
    int Edge[MAXV][MAXV];
}MGraph;

//拓扑序列若唯一，则入度为0的顶点只有一个，若有两个及以上就不唯一，几条路都可以走，若为0个则为环，无路可走
//每次拆掉入度为0的顶点
int uniquely(MGraph G) {
    int degree[G.numVertex]={0};
    for (int i=0;i<G.numVertex;i++) {
        for(int j=0;j<G.numVertex;j++) {
            degree[i]+=G.Edge[i][j];
        }
    }
    for (int i=0;i<G.numVertex;i++) {
        int cnt=0;//保存度为0顶点个数
        int index=-1;//保存度为0顶点下标
        for(int j=0;j<G.numVertex;j++) {
            if (degree[j]==0) {
                cnt++;
                index=j;
            }
        }

        if (cnt>1 || cnt==0) return 0;//度为0的顶点个数大于等于2或为0
        degree[index]=-1;

        for (int j=0;j<G.numVertex;j++) {
            if (G.Edge[index][j]!=0) {
                degree[j]--;
            }
        }
        return 1;
    }
}

int main() {


    return 0;
}