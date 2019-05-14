#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    srand( time(NULL));
    int ray[10];

    int i;
    for (i = 0; i<10; i++){
        ray[i] = rand();
    }

    ray[9] = 0;
    printf("First array\n" );
    for (i = 0; i < 10; i++){
        printf("%d\n", ray[i]);
    }

    int another[10];
    int * point = another;
    for (int i = 9; i >= 0; i--){
        *(point + i) = rand();
    }
    printf("\n\nSecond array\n" );
    for (i = 0; i < 10; i++){
        printf("%d\n", another[i]);
    }

    return 0;
}
