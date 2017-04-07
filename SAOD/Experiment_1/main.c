#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "bstree.h"

double wtime() {
	struct timeval t;
	gettimeofday(&t, NULL);
	return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int main(){
  int n=0,i=0;
  double t;
  char words[51203][60], tree, w, node;
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
  	tree = bstree_add(words[i-1],i-1);
  	if(i%10000 == 0){
  		w = words[getRand(0,i-1)];
  		t = wtime();
  		node = bstree_lookup(tree, w);
  		t = wtime() - t;
  		printf("n = %d; Elapsed time: %.6f sec.\n", i-1, t);
  	}
  }
  return 0;
}
