#include <stdio.h>
#include <stdlib.h>

/* **** Functions for array **** */
#define STACK_SIZE 5

typedef struct {
    int *elements;
    int top;
    int capacity;
} ArrayStack;

// Initialization stack
void initializeStack(ArrayStack **stack);
// Add element to stack
void push(ArrayStack **stack, int value);
// Delete upper element in array
int pop(ArrayStack **stack);
// Print stack
void printStack(ArrayStack *stack);
// Show first element in stack
void peek (ArrayStack *stack);
// Free array
void cleanStack(ArrayStack **stack);
// Check if array is empty
int isEmpty(ArrayStack *stack);
// Free memory for array
void freeStack(ArrayStack **stack);

/* **** Functions for OLS **** */
// Struct for list
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Structure for the OLS-based stack
typedef struct {
    Node *top;
} LinkedListStack;

// Initialization stack
void initializeStack_OLS(LinkedListStack **stack);
// Add element to stack
void push_OLS(LinkedListStack **stack, int value);
// Delete upper element in array
int pop_OLS(LinkedListStack **stack);
// Print stack
void printStack_OLS(LinkedListStack *stack);
// Show first element in stack
void peek_OLS(LinkedListStack *stack);
// Free array
void cleanStack_OLS(LinkedListStack **stack);
// Check if array is empty
int isEmpty_OLS(LinkedListStack *stack);
// Free memory for array
void freeStack_OLS(LinkedListStack **stack);


int main() {
    int choice;
    int value;
    ArrayStack* stack = NULL;
    LinkedListStack *stack1 = NULL;

    while (1) {
        printf("\n========== Menu ==========\n");
        printf("1. Array\n");
        printf("2. OLS\n");
        printf("3. Exit\n");
        printf("=================================\n");
        printf("Enter your option: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            break;
        }

        switch (choice) {
            case 1:
                do {
                    printf("\n========== Array menu ==========\n");
                    printf("1. Initialization stack\n");
                    printf("2. Add element to stack\n");
                    printf("3. Delete upper element in array\n");
                    printf("4. Print stack\n");
                    printf("5. Show first element in stack\n");
                    printf("6. Free array\n");
                    printf("7. Check if array is empty\n");
                    printf("8. Exit & Free memory\n");
                    printf("=================================\n");
                    printf("Enter your option: ");
                    if (scanf("%d", &choice) != 1) {
                        printf("Invalid input.\n");
                        break;
                    }
                    switch (choice) {
                        case 1:
                            initializeStack(&stack);
                            break;
                        case 2:
                            printf("Enter the value you want to add: ");
                            if (scanf("%d", &value) != 1) {
                                printf("Invalid input.\n");
                                break;
                            }
                            push(&stack, value);
                            break;
                        case 3:
                            pop(&stack);
                            break;
                        case 4:
                            printStack(stack);
                            break;
                        case 5:
                            peek(stack);
                            break;
                        case 6:
                            cleanStack(&stack);
                            break;
                        case 7:
                            if (isEmpty(stack)) {
                                printf("Is empty");
                            } else {
                                printf("Is NOT empty");
                            }
                            break;
                        case 8:
                            freeStack(&stack);
                            printf("Exiting menu.\n");
                            break;
                        default:
                            printf("Invalid option.\n");
                    }
                } while (choice != 8);
                break;
            case 2:
                do {
                    printf("\n========== OLS menu ==========\n");
                    printf("1. Initialization stack\n");
                    printf("2. Add element to stack\n");
                    printf("3. Delete upper element in list\n");
                    printf("4. Print stack\n");
                    printf("5. Show first element in stack\n");
                    printf("6. Free list\n");
                    printf("7. Check if list is empty\n");
                    printf("8. Exit & Free memory\n");
                    printf("=================================\n");
                    printf("Enter your option: ");
                    if (scanf("%d", &choice) != 1) {
                        printf("Invalid input.\n");
                        break;
                    }
                    switch (choice) {
                        case 1:
                            initializeStack_OLS(&stack1);
                            break;
                        case 2:
                            printf("Enter the value you want to add: ");
                            if (scanf("%d", &value) != 1) {
                                printf("Invalid input.\n");
                                break;
                            }
                            push_OLS(&stack1, value);
                            break;
                        case 3:
                            pop_OLS(&stack1);
                            break;
                        case 4:
                            printStack_OLS(stack1);
                            break;
                        case 5:
                            peek_OLS(stack1);
                            break;
                        case 6:
                            cleanStack_OLS(&stack1);
                            break;
                        case 7:
                            if (isEmpty_OLS(stack1)) {
                                printf("Is empty");
                            } else {
                                printf("Is NOT empty");
                            }
                            break;
                        case 8:
                            freeStack_OLS(&stack1);
                            printf("Exiting menu.\n");
                            break;
                        default:
                            printf("Invalid option.\n");
                    }
                } while (choice != 8);
                break;
            case 3:
                printf("Exiting program.\n");
                freeStack(&stack);
                freeStack_OLS(&stack1);
                return 0;
            default:
                printf("Invalid option.\n");
        }
    }
}

/* **** Functions for array **** */
void initializeStack(ArrayStack **stack) {
    *stack = (ArrayStack*)malloc(sizeof(ArrayStack));
    if (*stack == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    (*stack)->capacity = STACK_SIZE;
    (*stack)->top = -1;
    (*stack)->elements = (int *)malloc((*stack)->capacity * sizeof(int));
    if ((*stack)->elements == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
}

void push(ArrayStack **stack, int value) {
    if (*stack == NULL) {
        printf("Stack is not initialized.\n");
        return;
    }
    if ((*stack)->top == (*stack)->capacity - 1) {
        (*stack)->capacity *= 2;
        (*stack)->elements = (int*) realloc((*stack)->elements, (*stack)->capacity * sizeof(int));
        if ((*stack)->elements == NULL) {
            printf("Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }
    }
    (*stack)->elements[++((*stack)->top)] = value;
}

int pop(ArrayStack **stack) {
    if (*stack == NULL) {
        printf("Stack is not initialized.\n");
        return 0;
    }
    if ((*stack)->top == -1) {
        printf("Stack is empty.\n");
        return 0;
    }
    return (*stack)->elements[((*stack)->top)--];
}

void printStack(ArrayStack *stack) {
    if (stack == NULL) {
        printf("Stack is not initialized.\n");
        return;
    }
    printf("Stack: ");
    int i;
    for (i = 0; i <= stack->top; i++) {
        printf("%d ", stack->elements[i]);
    }
    printf("\n");
}

void peek (ArrayStack *stack) {
    if (stack == NULL) {
        printf("Stack is not initialized.\n");
        return;
    }
    if (stack->top == -1) {
        printf("Stack is empty.");
        return;
    }
    if (stack->top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("First element: %d", stack->elements[stack->top]);
}

void cleanStack(ArrayStack **stack) {
    if (*stack == NULL) {
        printf("Stack is not initialized.\n");
        return;
    }
    if ((*stack)->top == -1) {
        printf("Stack is empty.");
        return;
    }
    (*stack)->top = -1;
}

int isEmpty(ArrayStack *stack) {
    if (stack == NULL) {
        printf("Stack is not initialized.\n");
        return 0;
    }
    return (stack->top == -1);
}

void freeStack(ArrayStack **stack) {
    if (*stack == NULL) {
        printf("Stack is not initialized.\n");
        return;
    }
    if ((*stack)->top == -1) {
        printf("Stack is empty.");
        return;
    }
    free((*stack)->elements);
    free(*stack);
}

/* **** Functions for OLS **** */

// Function to initialize the stack
void initializeStack_OLS(LinkedListStack **stack) {
    *stack = (LinkedListStack *)malloc(sizeof(LinkedListStack));
    if (*stack == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    (*stack)->top = NULL;
}

// Function to insert an element into the stack
void push_OLS(LinkedListStack **stack, int value) {
    if (*stack == NULL) {
        printf("Stack is not initialized.\n");
        return;
    }
    if (*stack == NULL) {
        printf("Stack is not initialized.\n");
        return;
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = (*stack)->top;
    (*stack)->top = newNode;
}

// Function to remove the top element from the stack
int pop_OLS(LinkedListStack **stack) {
    if (*stack == NULL) {
        printf("Stack is not initialized.\n");
        return 0;
    }
    if (*stack == NULL || (*stack)->top == NULL) {
        printf("Stack is empty.\n");
        return 0;
    }
    Node *temp = (*stack)->top;
    int value = temp->data;
    (*stack)->top = (*stack)->top->next;
    free(temp);
    return value;
}

// Function to print all elements of the stack
void printStack_OLS(LinkedListStack *stack) {
    if (stack == NULL) {
        printf("Stack is not initialized.\n");
        return;
    }
    if (stack == NULL || stack->top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack: ");
    Node *current = stack->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to show the top element of the stack
void peek_OLS(LinkedListStack *stack) {
    if (stack == NULL) {
        printf("Stack is not initialized.\n");
        return;
    }
    if (stack->top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("First element: %d", stack->top->data);
}

// Function to clear the stack
void cleanStack_OLS(LinkedListStack **stack) {
    if (*stack == NULL) {
        printf("Stack is not initialized.\n");
        return;
    }
    if (*stack == NULL || (*stack)->top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    Node *current = (*stack)->top;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    (*stack)->top = NULL;
}

// Function to check if the stack is empty
int isEmpty_OLS(LinkedListStack *stack) {
    if (stack == NULL) {
        printf("Stack is not initialized.\n");
        return 0;
    }
    return (stack == NULL || stack->top == NULL);
}

// Function to free the memory allocated for the stack
void freeStack_OLS(LinkedListStack **stack) {
    if (*stack == NULL) {
        printf("Stack is not initialized.\n");
        return;
    }
    cleanStack_OLS(stack);
    free(*stack);
}
