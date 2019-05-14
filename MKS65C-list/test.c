#include <stdio.h>
#include <stdlib.h>
#include "link.h"


int main(){
    struct node * head = malloc(sizeof(struct node));
    //struct node * a0 = malloc(sizeof(struct node));
    //struct node * a1 = malloc(sizeof(struct node));
    //struct node * a2 = malloc(sizeof(struct node));
    //struct node * a3 = malloc(sizeof(struct node));
    //struct node * a4 = malloc(sizeof(struct node));
    printf("%ld\n", sizeof(struct node));

    printf("\nprint_list\n\n");
    head->num = 1;
    head->next = 0;

    print_list(head);

    //a0->num = 2;
    //a0->next = a1;

    //a1->num = 4;
    //a1->next = a2;

    //a2->num = 8;
    //a2->next = a3;

    //a3->num = 16;
    //a3->next = a4;

    //a4->num = 32;
    //a4->next = NULL;

    //print_list(head);

    printf("insert_front\n");
    int i = 10;
    for (i; i >= 0; i--){
        head = insert_front(head, i);
    }
    print_list(head);

    printf("free\n");
    free_list(head);
    print_list(head);

    //free(head);
    //free(a0);
    //free(a1);
    //free(a2);
    //free(a3);
    //free(a4);

    printf("end\n");
    return 0;
}
