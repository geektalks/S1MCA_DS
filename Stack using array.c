#include <stdio.h>
#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

// Function to check if the stack is empty
int isEmpty() {
    return top == -1;
}

// Function to check if the stack is full
int isFull() {
    return top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(int item) {
    if (isFull()) {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = item;
}

// Function to pop an element from the stack
int pop() {
    if (isEmpty()) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return stack[top--];
}

// Function to return the top element of the stack
int peek() {
    if (isEmpty()) {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack[top];
}

// Function to display the elements of the stack
void display() {
    if (isEmpty()) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= top; i++)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    push(1);
    push(2);
    push(3);

    display();

    printf("Top element: %d\n", peek());

    printf("Popped element: %d\n", pop());

    display();

    return 0;
}
