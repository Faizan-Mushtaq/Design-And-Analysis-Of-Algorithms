    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #define MAX 500
    int t[MAX];
    void shifttable(char p[]) {
    	int i,j,m;
    	m=strlen(p);
    	for (i=0;i<MAX;i++)
    	  t[i]=m;
    	for (j=0;j<m-1;j++)
    	  t[p[j]]=m-1-j;
          printf("Shifttable\n");
          for(int k=0;k<m;k++)
    printf("t[%d]=%d ",k+1,t[p[k]]);

    }
    int horspool(char src[],char p[]) {
    	int i,j,k,m,n,flag=0;
    	n=strlen(src);
    	m=strlen(p);
    	printf("\nLength of text=%d\n",n);
    	printf("Length of pattern=%d\n",m);
    	i=m-1;
    	while(i<n) {
    		k=0;
    		while((k<m)&&(p[m-1-k]==src[i-k]))
    		   {k++;}
    		if(k==m){
                flag=1;
                printf("pattern found at %d\n",i-m+2);
                i+=t[src[i]];
    		  // return(i-m+1);
          }
                else
    		   i+=t[src[i]];
    	}
    	return flag;
    }
    int main() {
    	char src[100],p[100];
    	int pos;
    	printf("Enter the text in which pattern is to be searched:\n");
    	scanf("%[^\n]",src);//gets(src); better use scanset
    	getchar();
    	printf("Enter the pattern to be searched:\n");
    	scanf("%[^\n]",p);//gets(p);
    	shifttable(p);
    	pos=horspool(src,p);
    	//if(pos>=0)
    	  //printf("\nThe desired pattern was found starting from position %d",pos+1);
        if(pos==0)
    	  printf("\nThe pattern was not found in the given text\n");
           return 0;
    }
