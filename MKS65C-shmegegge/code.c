#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <error.h>

int main(){
    int key = 12345;
    char * data;
    int shmid = shmget(key, 201, 0644);

    if (shmid < 0){
        printf("Create new shared mem\n");
        shmid = shmget(key, 201, 0644 | IPC_CREAT);
    }

    if (*data == -1) {
        perror("shmid");
        exit(1);
    }

    data = shmat(shmid, 0, 0);
    if (*data == -1) {
        perror("shmat");
        exit(1);
    }
    printf("data:\n%s\n", data);

    int choice;
    printf("Do you want to write to file? (0/1) ");
    scanf("%i", &choice);
    if (choice){
        printf("Enter a string: ");
        scanf("%s", data);
        printf("%s\n", data);
    }

    printf("Do you want to delete file? (0/1) ");
    scanf("%i", &choice);
    if (choice){
        printf("deleting file\n");
        choice = shmctl(shmid, IPC_RMID, NULL);
        if (choice == -1){
            perror("shmdt");
        }
    }


    if (shmdt(data) == -1) {
        perror("shmdt");
        exit(1);
    }


    return 0;
}
