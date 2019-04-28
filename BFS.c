#include<stdio.h>
#include<stdlib.h>
#define max 10
void bfs(int a[][max],int vis[],int n,int s);
int main()
{
    int n,i,j,a[max][max],start;
    int vis[max];
    int count=0;
    printf("Enter no of nodes: ");
    scanf("%d",&n);
    printf("Enter adj matrix\n");
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    scanf("%d",&a[i][j]);
    for(i=0;i<n;i++)
    vis[i]=0;

  /* printf("Enter starting vertex: ");
    scanf("%d",&start);
    printf("BFS traversal of graph: \n");
    bfs(a,vis,n,start-1);
    count++;
    printf("Traversal for node %d: ",count);*/
    j=0;
    for(i=0;i<n;i++)
    {
        if(vis[i]==0)
        {
            printf("\nTraversal for component %d: %d",count+1,i+1);
            bfs(a,vis,n,i);
            count++;
        }
        /*else
        {
            printf(" %d",i+1);
        }*/
    }
    if (count==1)
    {
        printf("\nGraph is connected\n");
    }
    else
    {
        printf("\nGraph is disconneted with %d components\n",count);
    }
    return 0;
}
void bfs(int a[][max],int vis[],int n,int start)
{
    int f=0,r=-1,i;
    int q[max],node;
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
                printf(" %d",i+1);
                q[++r]=i;
            }
        }
    }
}
