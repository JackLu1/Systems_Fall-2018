#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        printf("Error: No filename given\n");
        return 1;
    }

    struct stat *s = malloc(sizeof(struct stat));
    if (stat(argv[1], s) < 0)
    {
        printf("Error: %s\n", strerror(errno));
        return 1;
    }

    printf("=====================================\n");
    printf("Metadata of %s\n", argv[1]); 
    printf("=====================================\n");
    printf("Size: %ld bytes\n", s->st_size);
    printf("Permissions: %o\n", s->st_mode % 01000);
    printf("Time of last access: %s", ctime(&(s->st_atime)));


    char * str = malloc(100);
    long int size = s->st_size;
    printf("\nPrinting human readable format...\n");
    sprintf( str, "size of stat.c is %ld bytes, %f KB, %f MB, %f GB", 
            size, size/1000., size/1000000., size/1000000000. );
    printf("%s\n", str);


    printf("\nPrinting permissions in ls -l form...\n");
    int p = s->st_mode % 01000;
    // printf("IN BINARY 110100100\n");
    // printf(" all %o\n", p);
    // printf(" owner %o\n", p >> 6 & 7);
    // printf(" group %o\n", p >> 3 & 7);
    // printf(" other %o\n", p & 7);


    struct passwd *pw = getpwuid(s->st_uid);
    struct group  *gr = getgrgid(s->st_gid);

    char * owner = pw->pw_name;
    char * group = gr->gr_name;

    // get rid of \n at end of ctime format
    char * oof = ctime(&(s->st_mtime));
    for (char * ooof = oof; *ooof != '\0';ooof++){
        if (*ooof == '\n'){
            *ooof = '\0';
        }
    }

    char * rwx[] = {"---", "--x", "-w-", "-wx", "r--", "r-x", "rw-", "rwx"};
    
    char * ll = malloc(50);
    sprintf(ll, "%s%s%s 1 %s %s %ld %s %s\n", rwx[p >> 6 & 7], rwx[p >> 3 & 7], rwx[p & 7],
            owner, group, size, oof, argv[1]);
    printf("%s\n", ll);
    


    free(s);
    free(str);
    free(owner);
    free(group);
    return 0;
}
