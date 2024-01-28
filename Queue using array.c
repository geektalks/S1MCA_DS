#include <stdio.h>
#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;

// Function to check if the queue is empty
int isEmpty() {
    return (front == -1 && rear == -1);
}

// Function to check if the queue is full
int isFull() {
    return (rear == MAX_SIZE - 1);
}

// Function to add an element to the queue
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full. Cannot enqueue element.\n");
        return;
    } else if (isEmpty()) {
        front = rear = 0;
    } else {
        rear++;
    }
    queue[rear] = value;
}

// Function to remove an element from the queue
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue element.\n");
        return;
    } else if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

// Function to get the element at the front of the queue
int peek() {
    if (isEmpty()) {
        printf("Queue is empty. No elements to peek.\n");
        return -1;
    }
    return queue[front];
}

// Function to display the elements of the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty. No elements to display.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    // Enqueue some elements
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);

    // Display the queue
    display();

    // Dequeue an element
    dequeue();

    // Display the queue after dequeue
    display();

    // Peek the front element
    printf("Front element: %d\n", peek());

    return 0;
}
