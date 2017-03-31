#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
//#include "bstree.h"

double wtime() {
	struct timeval t;
	gettimeofday(&t, NULL);
	return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int main(){
  int n,i;
  double t;
  char words[100000];
  FILE *mf;
  char *estr;
  printf("Open file: ");
  mf = fopen ("Dictionary.txt","r");
  	
  while(1) {
  	estr = fgets(words,sizeof(words),mf);
  	if(feof(mf) !=0){
  		printf("\nEnd of file\n");
  		break;
  	}
  	printf(" %s",words);
  if (fclose(mf) != EOF)
  	printf("\nOK\n");
  /*scanf("%d", &n);
  printf("\n");*/
  /*tree = bstree_create(words[0], 0);
  for(i=2;i<=200000;i++){
  	tree = bstree_add(words[i-1],i-1);
  	if(i%10000 == 0){
  		w = words[getRand(0,i-1)];
  		t = wtime();
  		node = bstree_lookup(tree, w);
  		t = wtime() - t;
  		printf("n = %d; Elapsed time: %.6f sec.\n", i-1, t);
  	}
  }*/
}
}