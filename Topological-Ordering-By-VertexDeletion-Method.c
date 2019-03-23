#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int topo(int,int [][MAX],int [],int []);
int main()
{
    int i,j,m,n;
    int a[MAX][MAX],b[MAX],indegree[MAX];
    printf("ENTER NO OF VERTICIES\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        indegree[i]=0;
    }
    printf("ENTER ADJACENCY MATRIX\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j]==1)
            indegree[j]++;
        }
    }
    m=topo(n,a,indegree,b);
    if(m!=n)
    {
        printf("CYCLE DETECTED TOPOLOGICAL ORDERING NOT POSSIBLE\n");
    }
    else
    {
        printf("TOPOLOGICAL ORDERING: ");
        for(i=1;i<=n;i++)
        {
            printf("%d ",b[i]);
        }
    }
    return 0;
}
int topo(int n,int a[][MAX],int indegree[MAX],int b[MAX])
{
    int i,j,k=0;
    for(i=1;i<=n;i++)
    {
        if(indegree[i]==0)
        {
            indegree[i]=-1;
            b[++k]=i;
            for(j=1;j<=n;j++)
            {
                if(indegree[j]!=0 && a[i][j]==1)
                indegree[j]--;
            }
        i=0;
        }
    }
    return k;
}
