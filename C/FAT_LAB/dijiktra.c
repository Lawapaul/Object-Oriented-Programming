//CODE 1:

// You are using GCC
#include <stdlib.h>
#include <limits.h>
#include <limits.h>
#define MAX_VERTICES 1000

void dijikstra(int graph[MAX_VERTICES][MAX_VERTICES],int source,int vertices,int dest){
    int dist[MAX_VERTICES];
    int visited[MAX_VERTICES];
    int parent[MAX_VERTICES];
    for(int i=0;i<vertices;i++){
        dist[i]=INT_MAX;
        visited[i]=0;
        parent[i]=-1
    }
    dist[source]=0;
    for(int count=0;count<vertices-1;count++){
        int minDist=INT_MAX,u=-1;
        for(int i=0;i<vertices;i++){
            if(!visited[i] && dist[i] < minDist){
                minDist=dist[i];
                u=i;
            }
        }
        if(u==-1){
            break;
        }
        visited[u]=1;
        for(int v=0;v<vertices;v++){
            if(graph[u][v] !=0 && !visited[v] && dist[u] +graph[u][v] < dist[v] && dist[u]!=INT_MAX){
                dist[v]=dist[u] + graph[u][v];
                parent[v]=u;
            }
        }
    }
    if(dist[dest]==INT_MAX){
        printf("No path found");
    }
    else{
        int path[MAX_VERTICES];
        int path_length=0;
        int temp=dest;
        while(temp!=-1){
            path[path_length++]=temp;
            temp=parent[temp];
        }
        printf("Shortest path: ");
        for(int i=path_length-1;i>0;i--){
            printf("%d -> ",path[i]);
        }
        printf("%d",path[0]);
        printf("\nShortest distance: %d",dist[dest]);
    }
}
int main(){
    int edges,vertices,src,dest;
    int graph[MAX_VERTICES][MAX_VERTICES]={0};
    scanf("%d",&vertices);
    scanf("%d",&edges);
    for(int i=0;i<edges;i++){
        int u,v,weight;
        scanf("%d %d %d",&u,&v,&weight);
        graph[u][v]=weight;
        graph[v][u]=weight;
    }
    scanf("%d",&src);
    scanf("%d",&dest);
    dijikstra(graph,src,vertices,dest);
    return 0;
    
}



//CODE 2

// You are using GCC
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 1000
void dijiktra(int graph[MAX_VERTICES][MAX_VERTICES],int src,int vertices){
    int dist[MAX_VERTICES];
    int visited[MAX_VERTICES];
    for(int v=0;v<vertices;v++){
        dist[v]=INT_MAX;
        visited[v]=0;
    }
    dist[src]=0;
    for(int count=0;count<vertices-1;count++){
        int min=INT_MAX,u=-1;
        for(int v=0;v<vertices;v++){
            if(!visited[v] && dist[v]<min){
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
                dist[v]=dist[u]+graph[u][v];
            }
        }
    }
    printf("Vertex  Distance from Source\n");
    for(int v=0;v<vertices;v++){
        printf("%d\t\t\t %d\n",v,dist[v]);
    }
}
int main(){
    int graph[MAX_VERTICES][MAX_VERTICES]={0};
    int vertices,src;
    scanf("%d",&vertices);
    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    dijiktra(graph,src,vertices);
}