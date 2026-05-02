/**  Avery Schleicher **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node { // represents one node in a Linked List

    void *data;        // pointer to data associated with this node
    struct node *next; // pointer to next node in List
    struct node *prev; // pointer to previous node in List

} Node;

typedef struct { // represents a Linked List

    Node *header; // pointer to the "dummy header node" of
                  // the Linked List
    int size;     // number of nodes in the Linked List

} LinkedList;

// function proto-types
// we give you these five
void createList(LinkedList *someList);
void addEnd(LinkedList *someList, void *newData);
void *delete(LinkedList *someList, int position);
void outputList(LinkedList *someList);
void cleanAll(LinkedList *someList);
// the next three functions are the ones to be written by you
void swap(LinkedList *someList, unsigned int i, unsigned int j);
void *change(LinkedList *someList, int position, void *newElement);
void invert(LinkedList *someList);

#define MAX_NAME_LENGTH 20

static void exit_with_cleanup(LinkedList *list, int status) {
    cleanAll(list);
    exit(status);
}

int main() {

    LinkedList myList;
    LinkedList *roster = &myList;
    createList(roster); // initialize the fields of the list

    char op;
    char name[MAX_NAME_LENGTH + 1];
    int pos, pos2;
    // process a sequence of List operations from stdin
    while (scanf(" %c", &op) == 1) {
        if (op == 'a') {
            if (scanf("%20s", name) != 1) {
                exit_with_cleanup(roster, 1);
            }

            char *storedName = malloc(strlen(name) + 1);
            if (storedName == NULL) {
                exit_with_cleanup(roster, 2);
            }
            strcpy(storedName, name);
            addEnd(roster, storedName);
        } else if (op == 'd') {
            if (scanf("%d", &pos) != 1) {
                exit_with_cleanup(roster, 1);
            }

            char *removed = delete(roster, pos);
            free(removed);
        }

        else if (op == 'o') {
            outputList(roster);
        }

        else if (op == 's') {
            if (scanf("%d %d", &pos, &pos2) != 2) {
                exit_with_cleanup(roster, 1);
            }
            if (pos < 0 || pos2 < 0) {
                exit_with_cleanup(roster, 2);
            }
            swap(roster, (unsigned int)pos, (unsigned int)pos2);
        }

        else if (op == 'c') {
            if (scanf("%d %20s", &pos, name) != 2) {
                exit_with_cleanup(roster, 1);
            }

            char *newName = malloc(strlen(name) + 1);
            if (newName == NULL) {
                exit_with_cleanup(roster, 2);
            }
            strcpy(newName, name);

            char *oldName = change(roster, pos, newName);
            free(oldName);
        }

        else if (op == 'i') {
            invert(roster);
        }

        else {
            exit_with_cleanup(roster, 1);
        }
    }
    cleanAll(roster);
    return 0;
}

// Initially the List is empty
// We must create memory for the "dummy header node"
void createList(LinkedList *someList) {
    someList->size = 0;

    someList->header = malloc(sizeof(Node));
    if (someList->header == NULL) {
        exit(2);
    }

    someList->header->data = NULL;
    someList->header->next = someList->header;
    someList->header->prev = someList->header;
}

// add the new data element to the end of the List
void addEnd(LinkedList *someList, void *newData) {
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        exit(2);
    }

    newNode->data = newData; // set the fields of the new Node
    newNode->next = someList->header;
    newNode->prev = someList->header->prev;

    someList->header->prev->next = newNode; // splice-in the newNode
    someList->header->prev = newNode;       // into the List

    someList->size++;
}

// remove the item in the given positionn in the List, and
// return that data
void *delete(LinkedList *someList, int position) {
    if (position < 0 || position >= someList->size)
        exit(2);

    // walk down the list until we reach the node to be removed
    Node *temp = someList->header;
    for (int i = 0; i <= position; i++)
        temp = temp->next;

    void *removedData = temp->data;

    temp->prev->next = temp->next; // splice-out the Node
    temp->next->prev = temp->prev;

    someList->size--;

    free(temp); // free-up the memory of the deleted Node

    return (removedData);
}

// output the contents of the List
// it is assumed that the elements in the list are strings
void outputList(LinkedList *someList) {
    if (someList == NULL)
        return;

    if (someList->size == 0) {
        printf("[]\n");
        return;
    }

    printf("[");

    Node *temp = someList->header->next;

    for (int num = 0; num < someList->size; num++) {

        printf("%s%s", (char *)temp->data,
               (num < someList->size - 1) ? " " : "");
        temp = temp->next;
    }
    printf("]\n");
}

// the last element of the list becomes the first and the
// first element becomes the last;
// the dummy header node header pointers change: the next points to the last,
// the previous points to the first;
// elements from second to second to last, need to change their next and
// previous pointers.
void invert(LinkedList *someList) {
    if (someList == NULL || someList->size <= 1) {
        return;
    }

    Node *current = someList->header;
    Node *temp;

    do {
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        current = temp;
    } while (current != someList->header);
}

// swap the two elements in the list as indicated by their indices
// if one or both of the positions/indices specified in the input
// are not on the list, exit the program with status 2
void swap(LinkedList *someList, unsigned int i, unsigned int j) {
    if (i >= (unsigned int)someList->size ||
        j >= (unsigned int)someList->size) {
        exit(2);
    }

    if (i == j) {
        return;
    }

    Node *nodeI = someList->header->next;
    Node *nodeJ = someList->header->next;

    for (unsigned int k = 0; k < i; k++) {
        nodeI = nodeI->next;
    }
    for (unsigned int k = 0; k < j; k++) {
        nodeJ = nodeJ->next;
    }

    void *tempData = nodeI->data;
    nodeI->data = nodeJ->data;
    nodeJ->data = tempData;
}

// modify the data in the given position in the List to
// be the newElement.  Return a pointer to the data that
// was over-written and deleted from the list
// if the position is illegal then exit the program with status 2
void *change(LinkedList *someList, int position, void *newElement) {
    if (position < 0 || position >= someList->size) {
        exit(2);
    }

    Node *target;

    if (position < someList->size / 2) {
        target = someList->header->next;
        for (int i = 0; i < position; i++) {
            target = target->next;
        }
    } else {
        target = someList->header->prev;
        for (int i = someList->size - 1; i > position; i--) {
            target = target->prev;
        }
    }

    void *oldElement = target->data;
    target->data = newElement;
    return oldElement;
}

// free all allocated memory in the list, including strings and nodes
void cleanAll(LinkedList *someList) {
    if (someList == NULL || someList->header == NULL) {
        return;
    }

    Node *current = someList->header->next;
    while (current != someList->header) {
        Node *nextNode = current->next;
        free(current->data);
        free(current);
        current = nextNode;
    }

    free(someList->header);
    someList->header = NULL;
    someList->size = 0;
}
