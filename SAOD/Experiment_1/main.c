#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "bstree.h"

double wtime() {
	struct timeval t;
	gettimeofday(&t, NULL);
	return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int getrand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

int main(){
  int n=0, j,i=0;
  double t, t2 = 0;
  char words[51203][60]; int w;
  struct bstree *tree, *node;
  FILE *in = fopen("Dictionary.txt", "r");
    for(n=0;n<51203;n++)
    {
	fgets(words[n], 60000, in);
    }
  fclose(in);
   /* for(i=0;i<5;i++)
        printf("%s", words[i]);*/
  tree = bstree_create(words[0], 0);
  for(i=2;i<=200000;i++){
  	bstree_add(tree,words[i-1],i-1);
  	if(i%10000 == 0){
  	for(j=0;j<i;j++){
  		w = getrand(0,i-1);
  		t = wtime();
  		node = bstree_lookup(tree, w);
  		t = wtime() - t;
  		t2 = t2 + t;
  		}
  		t2 = t2/i;
  		printf("n = %d; Elapsed time: %.6f sec.\n", i-1, t2);
  }
  }
  return 0;
}