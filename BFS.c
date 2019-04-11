#include<stdio.h>
#include<stdlib.h>
void bfs(int a[][10],int vis[],int n,int s);
int main()
{
    int n,i,j,a[10][10],start;
    int vis[10];
    int count=0;
    printf("Enter no of nodes: ");
    scanf("%d",&n);
    printf("Enter adj matrix\n");
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    scanf("%d",&a[i][j]);
    for(i=0;i<n;i++)
    vis[i]=0;

    printf("Enter starting vertex: ");
    scanf("%d",&start);
    printf("BFS traversal of graph: \n");
    bfs(a,vis,n,start);
    count++;
    printf("Traversal for node %d: ",count);
    for(i=0;i<n;i++)
    {
        if(vis[i]==0)
        {
            printf("Traversal for node %d: %d",count+1,i+1);
            bfs(a,vis,n,i);
            count++;
        }
        else
        {
            printf(" %d",i+1);
        }
    }
    if (count==1)
    {
        printf("\nGraph is connected\n");
    }
    else
    {
        printf("Graph is disconneted with %d components\n",count);
    }
    return 0;
}
void bfs(int a[][10],int vis[],int n,int start)
{
    int f=0,r=-1,i;
    int q[10],node;
    vis[start]=1;
    q[++r]=start;
    while(f<=r)
    {
        node=q[f++];
        for(i=0;i<n;i++)
        {
            if(a[node][i]==1 && vis[i]==0)
            {
                vis[i]=1;
                q[++r]=i;
            }
        }
    }
}
