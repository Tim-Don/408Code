//
// Created by Tim_Don on 26-9-16.
//
#include <iostream>
#define MAXV 100

using namespace std;

typedef struct MGraph {
    int numVertex,numEdge;
    char VertexList[MAXV];
    int Edge[MAXV][MAXV];
}MGraph;

int printVertices(MGraph G) {
    int outDegree=0,inDegree=0;
    int cnt=0;
    for (int i=0; i<G.numVertex; i++) {
        outDegree=0;
        inDegree=0;
        for (int j=0; i<G.numVertex; j++) {
            if (G.Edge[i][j]>0)
                outDegree++;
        }
        for (int j=0; j<G.numVertex; j++) {
            if (G.Edge[j][i]>0)
                inDegree++;
        }
        if (outDegree>inDegree) {
            cout<<G.VertexList[i]<<" ";
            cnt++;
        }
    }
    return cnt;
}

int main() {


    return 0;
}