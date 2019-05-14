#include <stdio.h>
#include <string.h>
#include "str.h"

int main(){
  char s1[256] = "stuyvesant";
  char s2[] = "science";
  char *s3 = "btech";

  printf("\nstrlen test\n");
  printf("length of %s: %d\n", s1, (int)strlen(s1)); //10
  printf("length of %s: %d\n", s2, (int)strlen(s2)); //7
  printf("length of %s: %d\n", s3, (int)strlen(s3)); //5
    
  printf("\nmystrlen test\n");
  printf("length of %s: %d\n", s1, mystrlen(s1)); //10
  printf("length of %s: %d\n", s2, mystrlen(s2)); //7
  printf("length of %s: %d\n", s3, mystrlen(s3)); //5


  printf("\nstrcat test\n");
  char dest1[6] = "foo";
  char source1[] = "bar";
  printf("source: %s\n", source1);
  printf("dest: %s\n", dest1);
  strcat(dest1, source1);
  printf("result: %s\n", dest1);
 

  printf("\nmystrcat test\n");
  char dest2[6] = "foo";
  char source2[] = "bar";
  printf("source: %s\n", source2);
  printf("dest: %s\n", dest2);
  mystrcat(dest2, source2);
  printf("result: %s\n", dest2);

  printf("\nmystrncpy test\n");
  char dest3[10] = "meow";
  char source3[] = "cat";
  printf("source: %s\n", source3);
  printf("dest: %s\n", dest3);
  mystrncpy(dest3, source3, 5);
  printf("our result: %s\n", dest3);
  char dest5[10] = "meow";
  char source5[] = "cat";
  strncpy(dest5, source5, 5);
  printf("ofc result: %s\n", dest5);
  char dest4[10] = "triste";
  char source4[] = "happiness";
  printf("source: %s\n", source4);
  printf("dest: %s\n", dest4);
  mystrncpy(dest4, source4, 7);
  printf("our result: %s\n", dest4);
  char dest6[10] = "triste";
  char source6[] = "happiness";
  strncpy(dest6, source6, 7);
  printf("ofc result: %s\n", dest6);
    
  printf("\nmystrcmp test\n");
  char cmp0[] = "kilogramme of steel";
  char cmp1[] = "kilogramme of feathers";
  printf("cmp0: %s\n", cmp0);
  printf("cmp1: %s\n", cmp1);
  printf("our result: %d\n", mystrcmp(cmp0, cmp1));
  printf("ofc result: %d\n", strcmp(cmp0, cmp1));
  char cmp2[] = "kilogram";
  char cmp3[] = "kilogram";
  printf("cmp2: %s\n", cmp2);
  printf("cmp3: %s\n", cmp3);
  printf("our result: %d\n", mystrcmp(cmp2, cmp3));
  printf("ofc result: %d\n", strcmp(cmp2, cmp3));
  char cmp4[] = "ounce";
  char cmp5[] = "pound";
  printf("cmp4: %s\n", cmp4);
  printf("cmp5: %s\n", cmp5);
  printf("our result: %d\n", mystrcmp(cmp4, cmp5));
  printf("ofc result: %d\n", strcmp(cmp4, cmp5));
  char cmp6[] = "fluid";
  char cmp7[] = "fluid ounces";
  printf("cmp6: %s\n", cmp6);
  printf("cmp7: %s\n", cmp7);
  printf("our result: %d\n", mystrcmp(cmp6, cmp7));
  printf("ofc result: %d\n", strcmp(cmp6, cmp7));
  

  printf("\nmystrchr test\n");
  char s6[] = "kilogramme of steel";
  printf("s6: %s\n", s6);
  printf("our result for m: %p\n", mystrchr(s6, 'm'));
  printf("ofc result for m: %p\n", strchr(s6, 'm'));
  printf("our result for e: %p\n", mystrchr(s6, 'e'));
  printf("ofc result for e: %p\n", strchr(s6, 'e'));
  printf("our result for k: %p\n", mystrchr(s6, 'k'));
  printf("ofc result for k: %p\n", strchr(s6, 'k'));
  printf("our result for 1: %p\n", mystrchr(s6, '1'));
  printf("ofc result for 1: %p\n", strchr(s6, '1'));
    
  return 0;
}

