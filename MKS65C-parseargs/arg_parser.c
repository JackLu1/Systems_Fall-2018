#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char ** parse_args( char * line ){
    char ** args = calloc(6, 8);
    int i = 0;
    while (args[i++] = strsep(&line, " "));
    return args;
}

int main(){
    char line[100] = "echo 'asdfasdfasdfasdfasdfasdfasdfasdfasd'";
    char ** args = parse_args(line);

    // for (char ** a = args; *a; a++){
    //     printf("%s\n", *a); 
    // }
    execvp(args[0], args);

    return 0;
}

