#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include "hashtab.h"

#define HASHTAB_SIZE 71
#define HASHTAB_MUL  31

double wtime() {
        struct timeval t;
        gettimeofday(&t, NULL);
        return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int getrand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

int main() {
	int n,i=0,j;
	double t, t2 = 0;
	struct listnode *node;
	struct listnode *hashtab[HASHTAB_SIZE];
	char words[51203][60], w;
	FILE *in = fopen("Dictionary.txt", "r");
	for(n=0;n<51203;n++)
	  {
	  fgets(words[n], 60000, in);
	  }
	  fclose(in);
	hashtab_init(hashtab);
	for(i=2;i<200000;i++){
	hashtab_add(hashtab,words[i-1],i-1);
	if(i%10000 == 0){
	for(j=0;j<i;j++){
		w = words[getrand(0,i-1)];
		t = wtime();
		node = hashtab_lookup(hashtab, w);
		t = wtime() - t;
		t2 = t2 + t;
		}
		t2 = t2/i;
		printf("n = %d; Elapsed time: %.6f sec.\n", i-1, t2);
}
}
	return 0;
}
