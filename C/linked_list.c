#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct person {
    int age;
    struct person *next;
};

struct person* getNewPerson(int age);
void traverseList(struct person *current);
int linearSearch(struct person *current, int element);
int countLength(struct person *head);
struct person *insertNewHead(struct person *currentHead, int newData);

int main() {

    struct person *person1 = getNewPerson(5);
    struct person *person2 = getNewPerson(22);
    struct person *person3 = getNewPerson(25);

    (*person1).next = person2;
    (*person2).next = person3;

    traverseList(person1);

    int elementExist1 = linearSearch(person1, 25);
    int elementExist2 = linearSearch(person2, 1);

    (elementExist1 == 1 ? printf("Element Exists\n") : printf("Element Does Not Exist\n"));
    (elementExist2 == 1 ? printf("Element Exists\n") : printf("Element Does Not Exist\n"));

    printf("Length of this linked list: %d\n", countLength(person1));

    

    struct person *person0 = insertNewHead(person1, 23);

    traverseList(person0);


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
        printf("%d -> ", (*current).age);
        current = (*current).next;
    }
    printf("NULL\n");
}

int linearSearch(struct person *current, int element) {
    while (current != NULL) {
        if ((*current).age == element) {
            return true;
        }
        current = (*current).next;
    }
    return false;
}

int countLength(struct person *head) {
    struct person *current = head;
    int length = 0;

    while (current != NULL) {
        length++;
        current = (*current).next;
    }
    return length;
}

struct person *insertNewHead(struct person *currentHead, int newData) {
    struct person *newHead = getNewPerson(newData);
    (*newHead).next = currentHead;
    return newHead;
}

