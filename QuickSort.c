#include<stdio.h>
#include<stdlib.h>
int count;
void quicksort(int [],int,int);
int part(int [],int ,int);
int main()
{
    int a[1200],b[1200],c[1200],i,c1,c2,c3,j;
    int n;
    printf("ENTER THE NO ELEMENTS\n");
    scanf("%d",&n);
    printf("ENTER THE ELEMENTS\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
        quicksort(a,0,n-1);
        printf("SORTED ARRAY IS:\n");
        for(i=0;i<n;i++)
        {
            printf("%d ",a[i]);
        }
    printf("\n");
    printf("TIME COMPLEXITY ANALYSIS\n");
    printf("SIZE\tASC\tDSC\tRANDOM\n");
    for(i=16;i<=1024;i=i*2)
    {
        for(j=0;j<i;j++)
        {
            a[j]=j;
            b[j]=i-j;
            c[j]=rand()%i+1;
        }
        count=0;
        quicksort(a,0,i-1);
        c1=count;
        count=0;
        quicksort(b,0,i-1);
        c2=count;
        count=0;
        quicksort(c,0,i-1);
        c3=count;
        printf("%d\t%d\t%d\t%d\n",i,c1,c2,c3);
    }
    return 0;
}
void quicksort(int a[],int low,int high)
{
    int j;
    if(low<high)
    {
        j=part(a,low,high);
        quicksort(a,low,j-1);
        quicksort(a,j+1,high);
    }
}
int part(int a[],int low,int high)
{
    int p;
    p=a[low];
    int i=low+1;
    int j=high;
    int temp;
    while(1)
    {
        while(a[i]<p && i<=high)
        {
            i++;
            count++;
        }
        count++;
        while(a[j]>=p && j>low)
        {
            j--;
            count++;
        }
        count++;
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;;
        }
        else
        {
            temp=a[low];
            a[low]=a[j];
            a[j]=temp;
            return j;
        }
    }
}
