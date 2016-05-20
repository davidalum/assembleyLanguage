//newFormula.c 
#include <stdio.h>
#include <stdlib.h>
#include "nCr.h"
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <ctype.h>
#include "formula.h"

int main(int argc, char **argv){ //returns 0 if overflow/error occurs, 1 if runs correctly 
struct timeval begin, end;
 if(argc != 2){
   fprintf(stderr, "Invalid number of inputs\n");
   return 0;
 }
  int length = strlen(argv[1]);
  int n = atoi(argv[1]);
  if(n == 0 && argv[1][0] != '0'){ //not a number BUT could have letters at the end. 
    if(argv[1][0] == '-' && argv[1][1] == 'h'){
      printf("Usage: formula <positive integer>\n");
      return 1;
    }
    else{
      fprintf(stderr, "Invalid input entered\n");
      return 0;
    }
 
 } //end of not a number check
  else{ //is a number with/without letters at the end
    int j;
    for(j=0;j<length;j++){ //check if input has letters at end
      if(!isdigit(argv[1][j])){
        fprintf(stderr, "Invalid input entered\n");
        return 0;}
    }

    printf("(1 + x)^%d = ", n);
    gettimeofday(&begin, NULL); //starts timing of program speed
    if(n == 0){
      printf("1");
     gettimeofday(&end, NULL);                                                                                                                                                                                          printf("\n%ld microseconds\n", ((end.tv_sec * 1000000 + end.tv_usec)                                                                                                                                                                               - (begin.tv_sec * 1000000 + begin.tv_usec)));   
      return 1;
  }
	int coeff;
	int i;
      for(i=1;i<=n;i++){
	if(n == 0){
	  printf("0\n");
	  return 1;
		 }
	
	coeff = nCr(n, i);
	if(coeff == 0){ //check for 0 indicating overflow
	  printf("Overflow\n"); 
	  return 0;
	}
	if(i==1){
	  printf("1 + "); //prints the 1+ right at the beginning only once
	}
	printf("%d*x^%d ", coeff, i); 
	if(i != n)
	  printf("+ ");
      }
      gettimeofday(&end, NULL); //ends timing of program speed and prints
      printf("\n%ld microseconds\n", ((end.tv_sec * 1000000 + end.tv_usec)
				      - (begin.tv_sec * 1000000 + begin.tv_usec)));
  }

  

  return 1;



}
