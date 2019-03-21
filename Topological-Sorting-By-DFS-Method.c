#include<stdio.h>
#include<stdlib.h>
int j=0,pop[10],vis[10];
int dfs(int u,int n,int a[][10])
{
    int i,v,top=-1,s[10];
    vis[u]=1;
    a[++top]=u;
    while(top!=-1)
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
            if(a[u][v])==1 && vis[v]==0)
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
void topo(int n,int a[][10])
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
