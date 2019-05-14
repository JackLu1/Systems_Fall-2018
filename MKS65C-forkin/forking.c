#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(){

    //printf("F = %i, my pid = %i, my parent is %i\n", f, getpid(), getppid());
    //if (f == -1){
    //    printf("error\n");
    //}else if (f){
    //    printf("I am parent my pid = %i\n", getpid());
    //    f = fork();
    //}else{
    //    printf("I am child of %i, my pid is %i\n", getppid(), getpid());
    //}


    printf("I am parent %i, before fork\n", getpid());
    int f = fork();
    if (f){
        if (f = fork()){
            // parent
            //perror("error: ");
        } else {
            // second child
            //perror("error: ");
        }
    } else{
        // first child
        //perror("error: ");
    }

    if (f){
        int status;
        int dead_kid = wait(&status);
        //perror("error: ");
        printf("Child %i woke up and died, slept for %i secs\n", dead_kid, WEXITSTATUS(status));
    } else{
        srand(getpid());
        int s = rand() % (20 + 1 - 5) + 5;
        printf("Child %i now sleeping\n", getpid());
        sleep(s);
        printf("Child %i woke up after %i seconds\n", getpid(), s);
        //perror("error: ");
        return s;
    }

    return 0;
}
