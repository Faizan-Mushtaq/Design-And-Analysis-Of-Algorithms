#include<stdio.h>
#define max 20
void dfs(int a[][max],int v[],int,int);
int main()
{
    int n;
    int a[max][max];
    int v[10],i,j,count=0;
    printf("ENTER THE NO OF NODES\n");
    scanf("%d",&n);
    printf("ENTER THE SYM ADJACENCY MATRIX\n");
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    {
        scanf("%d",&a[i][j]);
    }
    printf("ADJACENCY MATRIX IS:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<n;i++)
    v[i]=0;

    for(i=0;i<n;i++)
    {
        if (v[i]==0)
        {
            printf("TRAVERSAL FOR COMPONENT %d: ",count+1);
            dfs(a,v,i,n);
            count++;
            printf("\n");
        }

    }
    if(count==1)
    {
        printf("GRAPH IS CONNECTED\n");
    }
    else{
        printf("GRAPH IS DISCONNECTED WITH %d COMPONENTS\n",count);
    }
    return 0;
}
void dfs(int a[][max],int v[],int i,int n)
{
    int j;
    v[i]=1;
    printf("%d\t",i);
    for(j=0;j<n;j++)
    if(v[j]==0 && a[i][j]==1)
    dfs(a,v,j,n);
}
