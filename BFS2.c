#include<stdio.h>
int g[10][10]={},vis[10]={},n,m,c;
void main()
{
    int i,a,b;
    printf("enter no.of vert");
    scanf("%d",&n);
    printf("no of edges");
    scanf("%d",&m);
    printf("ente edges:");
    for(i=0 ; i<m ; i++)
    {
        scanf("%d%d",&a,&b);
        g[a][b] = 1;
        g[b][a] = 1;
    }
    graph();
    if(c==1)
        printf("cconnected");
    else
        printf("disconnected,no of comps : %d",c);
}

void graph()
{
    int i;
    for(i=0 ; i<n ; i++)
    {
        if(vis[i]==0)
        {
            bfs(i);
            c++;
        }
    }
}

void bfs(int v)
{
    int q[10],f,r,i,j;
    f=r=-1;
    q[++r] = v;
    vis[v] = 1;
    printf("%d\t",v);
    while(f != r)
    {
        v = q[++f];
        for(i=0 ; i<n ; i++)
        {
            if(g[v][i] == 1 && vis[i] == 0)
            {
                vis[i] = 1;
                printf("%d\t",i);
                q[++r] = i;
            }
        }
    }
}
