#include<stdio.h>
#include<stdlib.h>
#define size 1024
int count;
void heapify(int [],int);
void heapsort(int [],int);
int main()
{
    int a[size],i,j,n,c1=0,c2=0,c3=0,b[size],c[size];
    printf("ENTER THE NO OF ELEMENTS\n");
    scanf("%d",&n);
    printf("ENTER ELEMENTS\n");
    for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
    heapify(a,n);
    printf("ELEMENTS AFTER HEAPIFY\n");
    for(i=1;i<=n;i++)
    printf("%d ",a[i]);
    printf("\nELEMENTS AFTER HEAPSORT\n");
    heapsort(a,n);
    for(i=1;i<=n;i++)
    printf("%d ",a[i]);
    printf("\nCOUNT VALUE=%d\n",count);
    printf("TIME COMPLEXITY IS:\n");
    printf("SIZE\tASC\tDSC\tRAN\n");
    for(i=16;i<=512;i=i*2)
    {
        for(j=1;j<=i;j++)
        {
            a[j]=j;
            b[j]=i-j+1;
            c[j]=rand()%i;
        }
        count=0;
        heapify(a,i);
        heapsort(a,i);
        c1=count;
        count=0;
        heapify(b,i);
        heapsort(b,i);
        c2=count;
        count=0;
        heapify(c,i);
        heapsort(c,i);
        c3=count;
        printf("%d\t%d\t%d\t%d\n",i,c1,c2,c3);
    }
    return 0;
}
void heapify(int a[size],int n)
{
    int i,j,k,v,flag;
    for(i=n/2;i>=1;i--)
    {
        k=i;
        v=a[k];
        flag=0;
        while(!flag&& (2*k)<=n)
        {
            j=2*k;
            if(j<n)
            {
                if(a[j]<a[j+1])
                j=j+1;
            }
            count++;
            if(v>=a[j])
            flag=1;
            else
            {
                a[k]=a[j];
                k=j;
            }
        }
        a[k]=v;
    }
}
void heapsort(int a[size],int n)
{
    int i;
    for(i=n;i>=1;i--)
    {
        int temp=a[1];
        a[1]=a[i];
        a[i]=temp;
        heapify(a,i-1);
    }
}
