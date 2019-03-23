#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int j=0,pop[MAX],vis[MAX];
void dfs(int,int,int [][MAX]);
void topo(int,int [][MAX]);
int main()
{
    int i,k,n,a[MAX][MAX];
    printf("Enter no of vertices: ");
    scanf("%d",&n);
    printf("Enter adjacency matrix\n");
    for(i=1;i<=n;i++)
    {
    for(k=1;k<=n;k++)
    {
    scanf("%d",&a[i][k]);
    }
    }
    topo(n,a);
    printf("Topological Order:");
    for(i=n;i>0;i--)
    printf("%d ",pop[i]);

    return 0;
}
void dfs(int u,int n,int a[][MAX])
{
    int i,v,top=-1,s[MAX];
    vis[u]=1;
    s[++top]=u;
    while(top!= -1)
    {
        for(v=1;v<=n;v++)
        {
            if(a[u][v]==1 && vis[v]==1)
            {
                for(i=top;i>=0;i--)
                {
                    if(s[i]==v)
                    {
                        printf("Cycle Detected topological sort not possible \n");
                        exit(1);
                    }
                }
            }
            if(a[u][v]==1 && vis[v]==0)
            {
                vis[v]=1;
                s[++top]=v;
                u=v;
                v=0;
            }
        }
        j++;
        pop[j]=u;
        top--;
        u=s[top];
    }
}
void topo(int n,int a[][MAX])
{
    int i,u;
    for(i=1;i<=n;i++)
        vis[i]=0;

    for(u=1;u<=n;u++)
    {
        if(vis[u]==0)
        dfs(u,n,a);
    }
}
