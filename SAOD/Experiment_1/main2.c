#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include "hashtab.h"

#define HASHTAB_SIZE 100000
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
	int n,i=0,j,m=0,b=0;
	srand(time(NULL));
	double t, t2 = 0;
	struct listnode *node;
	struct listnode *hashtab[HASHTAB_SIZE];
	char words[51203][60], *w;
	FILE *in = fopen("Dictionary.txt", "r");
	for(n=0;n<51203;n++)
	  {
	  fgets(words[n], 60000, in);
	  }
	  fclose(in);
	hashtab_init(hashtab);
	for(m=1;m<=20;m++){
	i=10000;
	for(b=0;b<i;b++){
	hashtab_add(hashtab,words[b],b-1);
	}
	for(j=0;j<1000000;j++){
		w = words[rand()%51203];
		t = wtime();
		//hashtab_delete(hashtab, w);
		node = hashtab_lookup(hashtab, w);
		t = wtime() - t;
         	t2 = t2 + t;
		}
        	t2 = t2/1000000;
		printf("n = %d; Elapsed time: %.8f sec.\n", i*m, t2);
	t2 = 0;
}
	return 0;
}