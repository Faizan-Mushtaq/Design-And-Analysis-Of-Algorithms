// C program for Naive Pattern Searching algorithm
#include <stdio.h>
#include <string.h>

void search(char* pat, char* txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int j;
    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++) {


        /* For current index i, check for pattern match */
        for (j = 0; j < M; j++)
            if (txt[i + j] != pat[j])
                break;

        if (j == M) // if pat[0...M-1] = txt[i, i+1, ...i+M-1]
            printf("Pattern found at index %d \n", i);

    }
    if(j!=M){printf("Pattern not found\n");}
}

/* Driver program to test above function */
int main()
{
    char txt[100];
    char pat[100];
    printf("ENTER TEXT\n");
	scanf("%[^\n]s",txt);
	getchar();
	printf("ENTER PATTERN\n");
	scanf("%[^\n]s",pat);
    search(pat, txt);
    return 0;
}
