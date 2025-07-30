#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct person {
    int age;
    struct person *next;
};

struct person* getNewPerson(int age);
void traverseList(struct person *current);

int main() {

    struct person *person1 = getNewPerson(5);
    struct person *person2 = getNewPerson(22);
    struct person *person3 = getNewPerson(25);

    (*person1).next = person2;
    (*person2).next = person3;

    traverseList(person1);

    free(person1);
    free(person2);
    free(person3);
    person1 = NULL;
    person2 = NULL;
    person3 = NULL;

    return 0;
}

struct person* getNewPerson(int age) {
    struct person *newPerson = (struct person*)malloc(sizeof(struct person));

    if (newPerson == NULL) {
        printf("Failed to allocate memory!\n");
        exit(1);
    }

    (*newPerson).age = age;
    (*newPerson).next = NULL;
    printf("New Person at %p\n", newPerson);
    return newPerson;
}

void traverseList(struct person *current) {
    while (current != NULL) {
        printf("Current Person Age: %d\n", (*current).age);
        current = (*current).next;

        // if ((*current).next == NULL) {
        //     printf("Last Person Age: %d", (*current).age);
        // }
    }
    printf("NULL\n");
}