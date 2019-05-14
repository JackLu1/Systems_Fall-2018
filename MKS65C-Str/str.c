#include <stdio.h>
#include "str.h"

int mystrlen( char * s){
  int a = 0;
  while(*s++){a++;} //iterates to null char, 
  return a; //returns how many chars you went through
}
char * mystrcat( char *dest, char *source ){
  char * ans = dest;
  while(*dest){dest++;} //iterate to terminating 0
  while(*dest++ = *source++); //concatonate until and including null
  return ans; //pointer to char array
}
char * mystrncpy( char *dest, char *source, int n )
{
  while (*source && n--) //until ending null or n characters, whichever is first
    {
      *dest++ = *source++; //copy character over
    }
  *dest = 0; //add null
}
int mystrcmp( char *s1, char *s2 )
{
  while (*s1 && *s2 && *s1 == *s2){ //until reach end or difference
    s1++;//keep going 
    s2++;
  }
  return *s1 - *s2; //0 if equal, - if s1 is less, + if s1 is greater
}
char * mystrchr( char *s, char c )
{
  while (*s != c) //until you find the character
    if (!*s++) //if you reach end of string
      return 0; //return nil address
  return s; //location of c
}
