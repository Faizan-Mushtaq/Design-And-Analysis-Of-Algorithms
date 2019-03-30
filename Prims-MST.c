#include <stdio.h>
#include <stdlib.h>
#define Inf 99
void Prims(int,int [10][10],int);
int main()
{
int N,i,j,Source;
printf("Enter the number of nodes: ");
scanf("%d",&N);
int Cost[10][10];
printf("Enter the cost of the edges:\n");
for(i = 1;i <= N;i++)
for(j= 1;j <= N;j++)
scanf("%d",&Cost[i][j]);
printf("Enter the source vertex: ");
scanf("%d",&Source);
Prims(N,Cost,Source);
return 0;
}
void Prims(int N,int Cost[10][10],int S)
{
int i,j,U,sum = 0,Distance[10],Visit[10],Vertex[10],least;
for(i = 1;i <= N;i++)
{
Visit[i] = 0;
Distance[i] = Cost[S][i];
Vertex[i] = S;
}
Visit[S] = 1;
printf("Edges in MST:");
for(i = 1;i < N;i++)
{
least = Inf;
for(j = 1;j <= N;j++)
{
if(Visit[j] == 0 && Distance[j] < least)
{
least = Distance[j];
U = j;
}
}
Visit[U] = 1;
sum = sum + Distance[U];
printf("\nThe edge (%d,%d) cost =%d",Vertex[U],U,Distance[U]);
for(j = 1;j <= N;j++)
{
if(Visit[j] == 0 && Cost[U][j] < Distance[j])
{
Distance[j] = Cost[U][j];
Vertex[j] = U;
}
}
}
printf("\nTotal cost MST =%d",sum);
}
