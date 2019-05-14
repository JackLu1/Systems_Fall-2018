#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(){

    // printf("%d\n", dev);
    // printf("error %d\n", errno);
    // perror("error");
    char * fd = "/dev/random";
    int * arr = malloc(40);

    int dev = open( fd, O_RDONLY );
    int r = read(dev, arr, 40);
    close(dev);

    printf("Reading random numbers ...\n");
    for(int i=0; i<10; i++){
        printf("%d\n", arr[i]);
    }

    fd = "./file.txt";
    dev = open(fd, O_CREAT | O_WRONLY, 0777);
    int w = write(dev, arr, 40);
    close(dev);
    free(arr);

    int * data = malloc(40);
    dev = open(fd, O_RDONLY);
    r = read(dev, data, 40);
    close(dev);

    printf("printing read numbers...\n");
    for(int i=0; i<10; i++){
        printf("%d\n", data[i]);
    }
    free(data);

    return 0;
}
