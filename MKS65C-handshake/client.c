#include "pipe_networking.h"

int to_server;
int from_server;

void sighandler(int sig){
    if (sig == SIGINT){
        remove("private");
        printf("Client has disconnected\n");
        exit(0);
    } else if (sig == SIGPIPE){
        close(to_server);
        close(from_server);
        printf("server has disconnected\n");
        exit(0);
    }
}

int main() {

    signal(SIGINT, sighandler);
    signal(SIGPIPE, sighandler);
    char * buffer = calloc(1,100);
    from_server = client_handshake( &to_server );
    if (from_server < 0){
        printf("server offline\n");
        exit(0);
    }

    while(1){
        printf("\n\n");
        printf("enter message: ");
        scanf("%s", buffer);
        write(to_server, buffer, 100);
        read(from_server, buffer, 100);
        printf("SERVER RESPOND: %s\n", buffer);
    }
}
