//
// Created by Tim_Don on 26-9-12.
//

#include <iostream>
#define MAXV 10

using namespace std;

// typedef struct MGraph {
//     int numVertices,numEdges;
//     char VerticesList[MAXV];
//     int Edge[MAXV][MAXV];
// }MGraph;
//
// int IsExistEL(MGraph G) {
//     int degree=0,cnt=0;
//     for (int i=0;i<G.numVertices;i++) {
//         for (int j=0;j<G.numVertices;j++) {
//             degree+=G.Edge[i][j];
//         }
//         if (degree % 2==1) cnt++;
//     }
//     //当存在0个奇数度顶点，存在欧拉回路
//     //当存在2个奇数度顶点，存在欧拉路径
//     if (cnt==0 || cnt==2) return 1;
//     else return 0;
// }


typedef struct MGraph {
    int numVertices,numEdges;
    char VerticesList[MAXV][MAXV];
    int Edge[MAXV][MAXV];
}MGraph;

int IsExistEL(MGraph G) {
    int degree,cnt=0;
    for (int i=0;i<G.numVertices;i++) {
        degree=0;
        for (int j=0;j<G.numVertices;j++) {
            degree+=G.Edge[i][j];
        }
        if (degree%2==1) {
            cnt++;
        }
    }
    if (cnt==0 || cnt==2) return 1;
    else return 0;
}

int main() {



    return 0;
}