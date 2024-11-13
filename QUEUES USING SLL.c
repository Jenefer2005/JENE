#include <stdio.h>
#include <stdlib.h>

// Define a structure for the queue node
struct QueueNode {
    int data;
    struct QueueNode* next;
};

// Define a structure for the queue
struct Queue {
    struct QueueNode* front;  // Points to the front of the queue
    struct QueueNode* rear;   // Points to the rear of the queue
    int size;                 // Current size of the queue
    int maxSize;             // Maximum size of the queue
};

// Function to create a new queue node
struct QueueNode* createNode(int data) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    if (!newNode) {
        printf("Memory allocation error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the queue
struct Queue* createQueue(int maxSize) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;         // Initialize size to 0
    queue->maxSize = maxSize; // Set the maximum size
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return queue->front == NULL;
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    return queue->size >= queue->maxSize;
}

// Function to enqueue an item to the queue
void enqueue(struct Queue* queue, int data) {
    if (isFull(queue)) {
        printf("Queue overflow: Cannot enqueue %d, queue is full\n", data);
        return;
    }
    struct QueueNode* newNode = createNode(data);
    if (!newNode) return; // Memory allocation failed
    
    if (isEmpty(queue)) {
        queue->front = newNode; // Set the new node as front
    } else {
        queue->rear->next = newNode; // Link the new node at the end
    }
    queue->rear = newNode; // Move the rear pointer to the new node
    queue->size++;         // Increment the size
    printf("%d enqueued to queue\n", data);
}

// Function to dequeue an item from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow: Cannot dequeue, queue is empty\n");
        return -1; // Indicating queue is empty
    }
    struct QueueNode* temp = queue->front;
    int dequeuedData = temp->data;
    queue->front = queue->front->next; // Move front pointer to the next node
    if (queue->front == NULL) {
        queue->rear = NULL; // If the queue becomes empty, update rear as well
    }
    free(temp);
    queue->size--; // Decrement the size
    return dequeuedData;
}

// Function to display the queue
void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    struct QueueNode* current = queue->front;
    printf("Queue elements:\n");
    while (current) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

// Function to free the queue
void freeQueue(struct Queue* queue) {
    while (!isEmpty(queue)) {
        dequeue(queue);
    }
    free(queue);
}

// Function to show the menu
void showMenu() {
    printf("\nQueue Menu:\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int maxSize;
    printf("Enter the maximum size of the queue: ");
    scanf("%d", &maxSize);
    
    struct Queue* queue = createQueue(maxSize);
    int choice, value;

    while (1) {
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Enqueue
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(queue, value);
                break;
            case 2: // Dequeue
                value = dequeue(queue);
                if (value != -1) {
                    printf("%d dequeued from queue\n", value);
                }
                break;
            case 3: // Display
                display(queue);
                break;
            case 4: // Exit
                freeQueue(queue);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

