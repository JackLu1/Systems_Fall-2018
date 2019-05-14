#include <stdio.h>
#include <stdlib.h>
#include "link.h"

void print_list(struct node * n){
    while(n){
        printf("num = %d\n", n->num);
        printf("n = %p\n", n);
        printf("next = %p\n\n", n->next);
        n = n->next;
    }
}

struct node * insert_front(struct node * front, int new_num){
    struct node * new_front = malloc(sizeof(struct node));
    new_front->num = new_num;
    new_front->next = front;
    return new_front;
}


struct node * free_list(struct node * front){
    struct node * temp = front;
    struct node * ret = front;
    while(temp){
        temp = temp->next;
        free(front);
        front = temp;
    }

    return ret;
}
