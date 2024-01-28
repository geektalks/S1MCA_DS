#include <stdio.h>
#include <stdlib.h>

// Node definition for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to push a new element onto the stack
void push(struct Node** top, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = *top;
    *top = newNode;
    printf("%d pushed to the stack.\n", value);
}

// Function to pop an element from the stack
int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack underflow: The stack is empty.\n");
        exit(EXIT_FAILURE);
    }

    struct Node* temp = *top;
    int poppedValue = temp->data;
    *top = temp->next;
    free(temp);

    return poppedValue;
}

// Function to display the elements of the stack
void display(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements: ");
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}

int main() {
    struct Node* top = NULL;

    push(&top, 10);
    push(&top, 20);
    push(&top, 30);

    display(top);

    printf("Popped element: %d\n", pop(&top));
    printf("Popped element: %d\n", pop(&top));

    display(top);

    return 0;
}
