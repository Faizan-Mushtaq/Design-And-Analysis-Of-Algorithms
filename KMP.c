// C program for implementation of KMP pattern searching
// algorithm
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int count=0,flag=0;
void computeLPSArray(char* pat, int M, int* lps);

// Prints occurrences of txt[] in pat[]
void KMPSearch(char* pat, char* txt)
{
	int M = strlen(pat);
	int N = strlen(txt);

	// create lps[] that will hold the longest prefix suffix
	// values for pattern
	int lps[M];

	// Preprocess the pattern (calculate lps[] array)
	computeLPSArray(pat, M, lps);

	int i = 0; // index for txt[]
	int j = 0; // index for pat[]
	while (i < N) {
		count++;
		if (pat[j] == txt[i]) {
			j++;
			i++;
		}

		if (j == M) {
			flag=1;
			printf("Found pattern at index %d ", i - j);
			j = lps[j - 1];
			break;//comment break to find all instances of pattern in text.
		}

		// mismatch after j matches
		else if (i < N && pat[j] != txt[i]) {
			// Do not match lps[0..lps[j-1]] characters,
			// they will match anyway
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}


	}
}

// Fills lps[] for given patttern pat[0..M-1]
void computeLPSArray(char* pat, int M, int* lps)
{
	// length of the previous longest prefix suffix
	int len = 0;

	lps[0] = 0; // lps[0] is always 0

	// the loop calculates lps[i] for i = 1 to M-1
	int i = 1;
	while (i < M) {
		if (pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		else // (pat[i] != pat[len])
		{
			// This is tricky. Consider the example.
			// AAACAAAA and i = 7. The idea is similar
			// to search step.
			if (len != 0) {
				len = lps[len - 1];
				// Also, note that we do not increment
				// i here
			}
			else // if (len == 0)
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}
int main()
{
	char txt[100];
	char pat[100];
	printf("ENTER TEXT\n");
	scanf("%[^\n]s",txt);
	getchar();
	printf("ENTER PATTERN\n");
	scanf("%[^\n]s",pat);
	KMPSearch(pat, txt);
	if (flag==0)
	printf("PATTERN NOT FOUND\n");
	printf("\nTHE NO OF COMPARISONS=%d\n",count);
	return 0;
}
