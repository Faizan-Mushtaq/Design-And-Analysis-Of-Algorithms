#include<stdio.h>
#include<stdlib.h>
int count;
void heapify(int a[],int n,int i)
{
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && a[l]>a[largest])
    {
        largest=l;
        count++;
    }
    if(r<n && a[r]>a[largest])
    {
        largest=r;
        count++;
    }
    if(largest!=i)
    {
        int temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;
        heapify(a,n,largest);
    }
}
void heapsort(int a[],int n)
{
    int i;
    for(i=n/2;i>=0;i--)
    heapify(a,n,i);

    for(i=n-1;i>=0;i--)
    {
        int temp =a[0];
        a[0]=a[i];
        a[i]=temp;
        heapify(a,i,0);
    }
}
int main()
{
    int i,j,n,a[1200],b[1200],c[1200],c1,c2,c3;
    printf("enter no oif ele:");
    scanf("%d",&n);
    printf("enter ele:");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    heapsort(a,n);
    printf("Sorted array: ");
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
    printf("Time complex\n");
    printf("size\tasc\tdsc\tran\n");
    for(i=16;i<=1024;i=i*2)
    {
        for(j=0;j<i;j++)
        {
            a[j]=j;
            b[j]=i-j;
            c[j]=rand()%i+1;
        }
        count=0;
        heapsort(a,i);
        c1=count;
        count=0;
        heapsort(b,i);
        c2=count;
        count=0;
        heapsort(c,i);
        c3=count;
        printf("%d\t%d\t%d\t%d\n",i,c1,c2,c3);
    }
    return 0;
}
