#include <stdio.h>
#include <string.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    studentNode *next;
    studentNode *back;
};

void showAll(struct studentNode *walk);
studentNode *addNode(studentNode **start, const char *name, int age, char sex, float gpa);
void InsNode(studentNode *now, const char *name, int age, char sex, float gpa);
void DelNode(studentNode **now, studentNode **start);
void GoBack(studentNode **now);

int main() {
    studentNode *start = nullptr;
    studentNode *now;

    now = addNode(&start, "one", 6, 'M', 3.11); showAll(start);
    now = addNode(&start, "two", 8, 'F', 3.22); showAll(start);
    InsNode(now, "three", 10, 'M', 3.33); showAll(start);
    InsNode(now, "four", 12, 'F', 3.44); showAll(start);
    GoBack(&now);
    DelNode(&now, &start); showAll(start);
    DelNode(&now, &start); showAll(start);
    DelNode(&now, &start); showAll(start);
    return 0;
}

void showAll(struct studentNode *walk) {
    while (walk != nullptr) {
        printf("%s ", walk->name);
        walk = walk->next;
    }
    printf("\n");
}

void GoBack(studentNode **now) {
    if (*now != nullptr && (*now)->back != nullptr) {
        *now = (*now)->back;
    }
}

studentNode *addNode(studentNode **start, const char *name, int age, char sex, float gpa) {
    studentNode *newNode = new studentNode;
    strcpy(newNode->name, name);

    newNode->age = age;
    newNode->sex = sex;
    newNode->gpa = gpa;
    newNode->next = nullptr;
    newNode->back = nullptr;

    if (*start == nullptr) {
        *start = newNode;
    } else {
        studentNode *walk = *start;
        while (walk->next != nullptr) {
            walk = walk->next;
        }
        walk->next = newNode;
        newNode->back = walk;
    }

    return newNode;
}

void InsNode(studentNode *now, const char *name, int age, char sex, float gpa) {
    if (now == nullptr) return;

    studentNode *newNode = new studentNode;
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->sex = sex;
    newNode->gpa = gpa;

    newNode->next = now->next;
    newNode->back = now;

    if (now->next != nullptr) {
        now->next->back = newNode;
    }

    now->next = newNode;
}

void DelNode(studentNode **now, studentNode **start) {
    if (*now == nullptr) return;

    studentNode *temp = *now;

    if (temp->back != nullptr) {
        temp->back->next = temp->next;
    } else {
        *start = temp->next; 
    }

    if (temp->next != nullptr) {
        temp->next->back = temp->back;
    }

    if (temp->next != nullptr) {
        *now = temp->next;
    } else {
        *now = temp->back;
    }

    delete temp;
}
