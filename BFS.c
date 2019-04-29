#include<stdio.h>
#include<stdlib.h>
#define max 20
void bfs(int a[][max],int vis[],int n,int s);
int main()
{
    int n,a[max][max],i,j,start;
    int vis[10],count=0;
    printf("enter no of vet:");
    scanf("%d",&n);
    printf("enter matrix\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("enter starting vet");
    scanf("%d",&start);
    for(i=0;i<n;i++)
    vis[i]=0;
    printf("traversal for component 1: %d ",start);
    bfs(a,vis,n,start-1);
    count++;
    j=0;
    for(i=0;i<n;i++)
    {
        if(vis[i]==0)
        {
            printf("\ntraversal for component %d: %d ",count+1,i+1);
            bfs(a,vis,n,i);
            count++;
            //printf("\n");
        }
    }
    if(count==1)
    printf("\nG is connected\n");
    else
    printf("\nG is disconnected %d components\n",count);

    return 0;
}
void bfs(int a[][max],int vis[],int n,int s)
{
    int f=0,r=-1,i;
    int q[max],node;
    vis[s]=1;
    q[++r]=s;
    while(f<=r)
    {
        node=q[f++];
        for(i=0;i<n;i++)
        {
            if(a[node][i]==1&&vis[i]==0)
            {
                vis[i]=1;
                printf("%d ",i+1);
                q[++r]=i;
            }
        }
    }
}
