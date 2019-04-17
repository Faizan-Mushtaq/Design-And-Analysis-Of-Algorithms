/* Following program is a C implementation of Rabin Karp
Algorithm given in the CLRS book */
#include<stdio.h>
#include<string.h>
// d is the number of characters in the input alphabet
#define d 256
int count=0,flag=0;
/* pat -> pattern
	txt -> text
	q -> A prime number*/
void search(char pat[], char txt[], int q)
{
	int M = strlen(pat);
	int N = strlen(txt);
	int i, j;
	int p = 0; // hash value for pattern
	int t = 0; // hash value for txt
	int h = 1;
	// The value of h would be "pow(d, M-1)%q"
	for (i = 0; i < M-1; i++)
		h = (h*d)%q;
	// Calculate the hash value of pattern and first
	// window of text
	for (i = 0; i < M; i++)
	{
		p = (d*p + pat[i])%q;
		t = (d*t + txt[i])%q;
	}

	// Slide the pattern over text one by one
	for (i = 0; i <= N - M; i++)
	{
		// Check the hash values of current window of text
		// and pattern. If the hash values match then only
		// check for characters on by one
		count++;
		if ( p == t )
		{
			/* Check for characters one by one */
			for (j = 0; j < M; j++)
			{
				count++;
				if (txt[i+j] != pat[j])
					break;
			}
			// if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]
			if (j == M){flag=1;
				printf("Pattern found at index %d \n", i);
				break;
		}
	}
		// Calculate hash value for next window of text: Remove
		// leading digit, add trailing digit
		if ( i < N-M )
		{
			t = (d*(t - txt[i]*h) + txt[i+M])%q;
			// We might get negative value of t, converting it
			// to positive
			if (t < 0)
			t = (t + q);
		}
	}

}
/* Driver program to test above function */
int main()
{
	char txt[100];
	char pat[100];
	int q = 101; // A prime number to get a strong hash function.
	printf("ENTER TEXT\n");
	scanf("%[^\n]s",txt);
	getchar();
	printf("ENTER PATTERN\n");
	scanf("%[^\n]s",pat);
	search(pat, txt, q);
	if(flag==0)
	printf("PATTERN NOT FOUND\n");
	printf("NO OF COMPARISONS=%d\n",count);
	return 0;
}
