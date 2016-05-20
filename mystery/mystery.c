#include <stdio.h>
#include <stdlib.h>
#include "mystery.h"

int num[200];

int add(int x, int y) {
  return x + y;
}

int dothething(int a) {
  int tmp = 0; //movl    $0, -8(%ebp), so tmp = -8(%ebp)

  if (num[a] == -1) { // cmpl    $-1, %eax since eax holds num[a] from previous assembley instructions

    if (a == 0){ //  cmpl    $0, 8(%ebp) because 8(%ebp) holds the first parameter passed into the function, aka "a"

      num[a] = 0; //movl   $0, num(,%eax,4) assigns num[a] the value 0 
    }
    else if (a == 1){ //cmpl	$1, 8(%ebp) compares first parameter a to 1. 
      num[a]=1;
    }
    else{ //jne   .L10 (not equal) causes this recursive call to run. 
      num[a] = add (dothething(a-1),dothething(a-2));
    }
  }
  tmp = num[a];
  return tmp;
}


int main(int argc, char** argv) {
  int i = 0; //movl $0, -8(%ebp) and -8(%ebp) holds value for i. 

  int n = atoi(argv[1]);  /*call    atoi
			    movl    %eax, -12(%ebp) and -12(ebp) holds local variable n*/ 

  while (i<=199) {    // cmpl    $199, -8(%ebp),                                                                                                                                                                                       // jle     .L17           all assembley code reads loops as while loops, since for loops are basically while loops as well 
    num[i]=-1;
    i++; //addl    $1, -8(%ebp) == -8(%ebp) = -8(%ebp)+1 == i = i+1 == i++
  }
  printf("%i\n", dothething(n));
  return 0;
}
