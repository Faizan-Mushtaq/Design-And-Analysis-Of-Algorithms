#include <stdio.h>
#include <stdlib.h>
int min(int,int);
int BinomialCoefficient(int,int);

int main()
{
int n,k,answer;
printf("Enter N & K value: ");
scanf("%d%d",&n,&k);
if(n<k){
printf("N < K :NOT POSSIBLE\n");
return 0;}
answer = BinomialCoefficient(n,k);
printf("\nThe value of C(%d,%d) is %d.\n",n,k,answer);
return 0;
}

int min(int a,int b)
{
return (a > b)? b:a;
}
int BinomialCoefficient(int n,int k)
{
int i,j,C[n+1][k+1];
for(i = 0;i <= n;i++)
{
for(j = 0;j<= min(i,k);j++)
{
    if(j == 0 || j == i)
    C[i][j] = 1;
    else
    C[i][j] = C[i-1][j-1] + C[i-1][j];
    printf("%3d ",C[i][j]);
}
printf("\n");
}
/*for(i = 0;i <= n;i++)
{
    for(j = 0;j <= i;j++)
    printf("%d ",C[i][j]);
    printf("\n");
}*/
    return C[n][k];
}
