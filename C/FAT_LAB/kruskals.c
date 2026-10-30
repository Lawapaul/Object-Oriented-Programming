#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#define MAX 100
struct edges{
    int src, weight, dest;
};
struct Subset{
    int parent;
    int rank;
};
int find(struct Subset subset[],int i){
    if(subset[i].parent!=i){
        subset[i].parent-find(subset,subset[i].parent);
    }
    return subset[i].parent;
}
int union_set(struct Subset subset[],int x,int y){
    int rootx=find(subset,x);
    int rooty=find(subset,y);
    if(subset[rootx].rank < subset[rooty].rank){
        subset[rootx].parent=rooty;
    }
    else if(subset[rootx].parent > subset[rooty].rank){
        subset[rooty].parent=rootx;
    }
    else{
        subset[rooty].parent=rootx;
        subset[rootx].rank++;
    }
}
int comparable(const void* a,const void* b){
    struct edges* A=(struct edges*)a;
    struct edges* B=(struct edges*)b;
    return A->weight - B->weight;
}
int noofedges(int V, int graph[MAX][MAX],struct edges edge[]){
    int edgecount=0;
    for(int i=0;i<V;i++){
        for(int j=i+1;j<V;j++){
            if(graph[i][j]!=INT_MAX){
                edge[edgecount].src=i;
                edge[edgecount].dest=j;
                edge[edgecount].weight=graph[i][j];
                edgecount++;
            }
        }
    }
    return edgecount;
}
void mst(int V,int graph[MAX][MAX]){
    struct edges edge[MAX*MAX];
    int E=noofedges(V,graph,edge);
    qsort(edge,E,sizeof(struct edges),comparable);
    struct Subset* subset=(struct Subset*)malloc(V*sizeof(struct Subset));
    int e=0;
    int i=0;
    for(int i=0;i<V;i++){
        subset[i].parent=i;
        subset[i].rank=0;
    }
    struct edges result[MAX];
    while(e<V-1 && i<E){
        struct edges temp=edge[i++];
        int x=find(subset,temp.src);
        int y=find(subset,temp.dest);
        if(x!=y){
            result[e++]=temp;
            union_set(subset,x,y);
        }
    }
    
}
