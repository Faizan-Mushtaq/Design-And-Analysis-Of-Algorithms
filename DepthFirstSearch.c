#include<stdio.h>
#include<stdlib.h>
#define max 20
void dfs(int a[][max],int vis[],int n,int i);
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
    printf("traversal for comp 1: ");
    dfs(a,vis,n,start-1);
    count++;
    for(i=0;i<n;i++)
    {
        if(vis[i]==0)
        {
            printf("\ntraversal for component %d: ",count+1);
            dfs(a,vis,n,i);
            count++;
            printf("\n");
        }
    }
    if(count==1)
    printf("\nG is connected\n");
    else
    printf("\nG is disconnected %d components\n",count);

    return 0;
}
void dfs(int a[][max],int vis[],int n,int i)
{
    int j;
    vis[i]=1;
    printf("%d ",i+1);
    for(j=0;j<n;j++)
    {
        if(a[i][j]==1&&vis[j]==0)
        dfs(a,vis,n,j);
    }
}
