#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define MAX 100
void dijiktra(int graph[MAX][MAX],int src,int vertices){
    int visited[MAX];
    int dist[MAX];
    for(int v=0;v<vertices;v++){
        dist[v]=INT_MAX;
        visited[v]=0;
    }
    dist[src]=0;
    for(int count=0;count<vertices-1;count++){
        int min=INT_MAX,u=-1;
        for(int v=0;v<vertices;v++){
            if(!visited[v] && dist[v] < min){
                min=dist[v];
                u=v;
            }
        }
        if(u==-1){
            break;
        }
        visited[u]=1;
        for(int v=0;v<vertices;v++){
            if(!visited[v] && graph[u][v]!=0 && dist[u]!=INT_MAX && dist[u] + graph[u][v] < dist[v]){
                dist[v]=dist[u] + graph[u][v];
            }
        }
    }
    printf("Node - Distance\n");
    for(int v=0;v<vertices;v++){
        printf("%d - %d\n",v,dist[v]);
    }
}
void BellmanFord(int graph[MAX][MAX],int vertices,int src){
    int dist[MAX];
    for(int v=0;v<vertices;v++){
        dist[v]=INT_MAX;
    }
    dist[src]=0;
    for(int count=0;count<vertices-1;count++){
        for(int u=0;u<vertices;u++){
            for(int v=0;v<vertices;v++){
                if(graph[u][v]!=0 && dist[u]!=INT_MAX && dist[u] + graph[u][v] < dist[v]){
                    dist[v]=dist[u] + graph[u][v];
                }
            }
        }
    }
    printf("Node - Distance\n");
    for(int i=0;i<vertices;i++){
        printf("%d - %d\n",i,dist[i]);
    }
}
int main(){
    int graph[MAX][MAX]={0};
    int vertices,Edges,src;
    scanf("%d",&vertices);
    scanf("%d",&Edges);
    for(int i=0;i<Edges;i++){
        int u,w,weight;
        scanf("%d %d %d",&u,&w,&weight);
        graph[u][w]=weight;
        graph[w][u]=weight;
    }
    scanf("%d",&src);
    printf("Dijiktra\n");
    dijiktra(graph,src,vertices);
    printf("BellmanFord\n");
    BellmanFord(graph,vertices,src);
}
