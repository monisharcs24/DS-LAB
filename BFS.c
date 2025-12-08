#include <stdio.h>
#include <stdlib.h>

#define MAX 100
int queue[MAX],front=-1,rear=-1;
int visited[MAX];

void enqueue(int v){
    if(rear==MAX-1)
        printf("Queue Overflow\n");
    else{
        if(front==-1)
            front=0;
        rear++;
        queue[rear]=v;
    }
}
int dequeue(){
    int v;
    if(front==-1||front>rear)
        return -1;
    else{
        v=queue[front];
        front++;
        return v;
    }
}
void BFS(int adj[MAX][MAX],int n,int start){
    int i,current;
    for(i=0;i<n;i++)
        visited[i]=0;
    enqueue(start);
    visited[start]=1;
    printf("BFS Traversal:");
    while((current=dequeue())!=-1){
        printf("%d ",current);
        for(i=0;i<n;i++){
            if(adj[current][i]==1&&!visited[i]){
                enqueue(i);
                visited[i]=1;
            }
        }
    }
    printf("\n");
}
int main(){
    int n,i,j,start;
    int adj[MAX][MAX];
    printf("Enter number of vertices:");
    scanf("%d",&n);
    printf("Enter adjacency matrix of the graph:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&adj[i][j]);
    printf("Enter starting vertex for BFS:");
    scanf("%d",&start);
    BFS(adj,n,start);
    return 0;
}
