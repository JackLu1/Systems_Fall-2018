#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sieve.h"

/*
 * Finds nth prime
 */
int sieve( int targetPrime ){
    
    int size;
    //size = 1.15 * targetPrime * log(targetPrime);
    if (targetPrime == 1){
        return 2;
    }
    if (targetPrime < 5000){
       size = 1.3 * targetPrime * log(targetPrime);
    }
    else{
       size = 1.15 * targetPrime * log(targetPrime);
    }
    int * list = calloc(size, 4);
    int stop = (int)sqrt(size);

    list[0] = 1; // 0
    list[1] = 1; // 1
    int i, j;
    for (i = 2; i < stop; i++){
        if (!list[i]){
            for (j = 2*i; j < size; j=j+i){
                list[j] = 1;
            } 
        }
    }
    for (i = 0; i < size; i++){
        if (!list[i]){
            targetPrime--;
        }
        if (!targetPrime){
            return i;
        }
    }

    return 0;
}
