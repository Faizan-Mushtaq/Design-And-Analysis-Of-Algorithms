#include <stdio.h>
#include <stdlib.h>
#define Inf 999
void Dijsktra(int N,int Cost[10][10],int S,int Distance[])
{
int i,j,U,count = 1,Visited[10],min;
for(i = 1;i <= N;i++)
{
Distance[i] = Cost[S][i];
Visited[i] = 0;
}
Visited[S] = 1;
Distance[S] = 0;
while(count <= N)
{
min = Inf;
for(j = 1;j <= N;j++)
if(Distance[j] < min && Visited[j] == 0)
{min = Distance[j];
U = j;
}
Visited[U] = 1;
count++;
for(j = 1;j <= N;j++)
if(Distance[U] + Cost[U][j] < Distance[j])
Distance[j] = Distance[U] + Cost[U][j];
}
}
int main()
{
int N,i,j,Source;
printf("Enter the number of nodes: ");
scanf("%d",&N);
int Cost[10][10],Distance[N+1];
printf("Enter the cost of the edges:\n");
for(i = 1;i <= N;i++)
for(j = 1;j <= N;j++)
{
scanf("%d",&Cost[i][j]);
if(Cost[i][j] == 0)
Cost[i][j] = Inf;
}
printf("Enter the source vertex: ");
scanf("%d",&Source);
Dijsktra(N,Cost,Source,Distance);
for(i = 1;i <= N;i++)
if(i != Source)
printf("\nThe shortest distance from %d to %d is %d.",Source,i,Distance[i]);
return 0;
}
