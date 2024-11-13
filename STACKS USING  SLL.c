#include <stdio.h>
#include <stdlib.h>

// Define a structure for the stack node
struct StackNode {
    int data;
    struct StackNode* next;
};

// Define a structure for the stack
struct Stack {
    struct StackNode* top;
    int size;      // Keep track of the current size of the stack
    int maxSize;   // Maximum size of the stack
};

// Function to create a new stack node
struct StackNode* createNode(int data) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    if (!newNode) {
        printf("Memory allocation error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the stack
struct Stack* createStack(int maxSize) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    stack->size = 0; // Initialize size to 0
    stack->maxSize = maxSize; // Set the maximum size
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->size >= stack->maxSize;
}

// Function to push an item onto the stack
void push(struct Stack* stack, int data) {
    if (isFull(stack)) {
        printf("Stack overflow: Cannot push %d, stack is full\n", data);
        return;
    }
    struct StackNode* newNode = createNode(data);
    if (!newNode) return; // Memory allocation failed
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++; // Increment the size
    printf("%d pushed to stack\n", data);
}

// Function to pop an item from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow: Cannot pop, stack is empty\n");
        return -1; // Indicating stack is empty
    }
    struct StackNode* temp = stack->top;
    int poppedData = temp->data;
    stack->top = stack->top->next;
    free(temp);
    stack->size--; // Decrement the size
    return poppedData;
}

// Function to display the stack
void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    struct StackNode* current = stack->top;
    printf("Stack elements:\n");
    while (current) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

// Function to free the stack
void freeStack(struct Stack* stack) {
    while (!isEmpty(stack)) {
        pop(stack);
    }
    free(stack);
}

// Function to show the menu
void showMenu() {
    printf("\nStack Menu:\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int maxSize;
    printf("Enter the maximum size of the stack: ");
    scanf("%d", &maxSize);
    
    struct Stack* stack = createStack(maxSize);
    int choice, value;

    while (1) {
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Push
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(stack, value);
                break;
            case 2: // Pop
                value = pop(stack);
                if (value != -1) {
                    printf("%d popped from stack\n", value);
                }
                break;
            case 3: // Display
                display(stack);
                break;
            case 4: // Exit
                freeStack(stack);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}



