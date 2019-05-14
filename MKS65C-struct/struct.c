#include <stdio.h>
#include "struct.h"
#include <time.h>
#include <string.h>
#include <stdlib.h>

struct student {
    char name[256];
    float gpa;
};

char names[40][15] = {
    "Nadine", "Jack", "Michael", "Hasif",
    "Cooper", "Jason", "Raymond", "Joan",
    "Raunak", "Bill", "Kevin", "Mandy",
    "Tina", "Matthew", "Maggie", "Brian",
    "Puneet", "Calvin", "Jabir", "Camilla",
    "Hui Min", "Oliver", "Aaron", "Michael",
    "Horace", "Ahnaf", "Adil", "Imad",
    "Wei Wen", "Samuel", "Christopher", "Yulia",
    "Leah", "JonAlf", "David", "Peter",
    "Ivan", "Fabiha", "Rohan", "Michelle"
};

struct student example()
{
    struct student bob;
    strcpy(bob.name, names[rand() % 40]);
    bob.gpa = rand() % 37 + 64;
    return bob;
}

void modify(struct student *s, char *newName, float newGPA)
{
    strcpy(s->name, newName);
    s->gpa = newGPA;
}

// Randomize vowels
void vowel(struct student *s){
    char * change = s->name;
    char * v = "aeiou";
    while(*change){
        if ( strchr( v, *change) != NULL ){
            char rvowel = *(v + (int)(rand() % 5));
            *change = rvowel;
        }
        change++;
    }
}

void printStu(struct student s)
{
    printf("%s's gpa: %f\n", s.name, s.gpa);
}

int main(){
    srand(time(NULL));

    struct student bob = example();
    printStu(bob);

    printf("Change student gpa to 100\n");
    modify(&bob, bob.name, 100);
    printStu(bob);

    printf("Randomize vowels in student name\n");
    vowel(&bob);
    printStu(bob);

    struct student test;
    strcpy(test.name, "Voldemort");
    test.gpa = 55;
    vowel(&test);
    printStu(test);

    char *mcName = "Harry";
    modify(&test, mcName, 99.5);
    vowel(&test);
    printStu(test);

    return 0;

}





