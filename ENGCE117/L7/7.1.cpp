#include <stdio.h>
#include <string.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
};

class LinkedList {
protected:
    struct studentNode *start, **now;
public:
    LinkedList();
    virtual ~LinkedList(); 
    void InsNode(const char* n, int a, char s, float g);
    void DelNode();
    void GoNext();
    
    virtual void ShowNode(); 
};
class NewList : public LinkedList {
public:
    void GoFirst();
    
    virtual void ShowNode(); 
};

int main() {
    LinkedList listA;
    NewList listB;
    LinkedList *listC; 
    listA.InsNode("one", 1, 'A', 1.1);
    listA.InsNode("two", 2, 'B', 2.2);
    listA.InsNode("three", 3, 'C', 3.3);
    listA.GoNext();
    listA.ShowNode(); 
    listB.InsNode("four", 4, 'D', 4.4);
    listB.InsNode("five", 5, 'E', 5.5);
    listB.InsNode("six", 6, 'F', 6.6);
    listB.GoNext();
    listB.DelNode();
    listB.ShowNode(); 
    listC = &listA;
    listC->GoNext();
    listC->ShowNode(); 

    listC = &listB;
    listC->ShowNode(); 

    return 0;
}


LinkedList::LinkedList() {
    start = NULL;
    now = &start;
}

LinkedList::~LinkedList() {
    studentNode *temp;
    while (start != NULL) {
        temp = start;
        start = start->next;
        delete temp;
    }
}

void LinkedList::InsNode(const char* n, int a, char s, float g) {
    studentNode *newNode = new studentNode;
    strcpy(newNode->name, n);
    newNode->age = a;
    newNode->sex = s;
    newNode->gpa = g;

    newNode->next = *now;
    *now = newNode;
}

void LinkedList::GoNext() {
    if (*now != NULL) {
        now = &((*now)->next);
    }
}

void LinkedList::ShowNode() {
    if (*now != NULL) {
        printf("%s %d %c %.2f\n", (*now)->name, (*now)->age, (*now)->sex, (*now)->gpa);
    }
}

void LinkedList::DelNode() {
    if (*now != NULL) {
        studentNode* temp = *now;
        *now = (*now)->next;
        delete temp;
    }
}

void NewList::GoFirst() {
    now = &start;
}

void NewList::ShowNode() {
    studentNode *temp = start;
    while (temp != NULL) {
        printf("%s ", temp->name);
        temp = temp->next;
    }
    printf("\n");
}
