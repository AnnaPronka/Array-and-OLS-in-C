# Array and OLS (Linked List) Stack Implementation in C

This project demonstrates how to implement two types of stacks in C:
1. **Array-based stack**: A stack implemented using a dynamic array.
2. **Linked List-based stack (OLS)**: A stack implemented using a linked list.

Each stack supports basic stack operations like initialization, push, pop, peek, checking if empty, and freeing memory.

## Table of Contents
- [Getting Started](#getting-started)
- [Stack Operations](#stack-operations)
  - [Array-Based Stack](#array-based-stack)
  - [Linked List-Based Stack (OLS)](#linked-list-based-stack-ols)
- [How to Run](#how-to-run)
- [Contributing](#contributing)
- [License](#license)

## Getting Started

### Prerequisites
To compile and run this C program, you'll need:
- A C compiler such as `gcc`.
- Basic understanding of stacks and data structures.

### Files
- `main.c`: Contains the implementation of the array-based stack and the OLS (linked list-based) stack.
  
## Stack Operations

### Array-Based Stack
The array-based stack is a dynamic array that grows as elements are pushed to it. It includes the following operations:
- **Initialization**: Creates an empty stack with an initial capacity of 5.
- **Push**: Adds an element to the top of the stack. If the stack is full, the capacity is doubled.
- **Pop**: Removes the top element from the stack.
- **Peek**: Returns the top element without removing it.
- **Is Empty**: Checks whether the stack is empty.
- **Clean**: Resets the stack but keeps the allocated memory.
- **Free**: Frees the memory allocated for the stack.

### Linked List-Based Stack (OLS)
The linked list-based stack uses a linked list where each node contains a data value and a pointer to the next node. It supports the following operations:
- **Initialization**: Creates an empty linked list stack.
- **Push**: Adds a node to the top of the stack.
- **Pop**: Removes the top node from the stack.
- **Peek**: Returns the top node’s value without removing it.
- **Is Empty**: Checks whether the stack is empty.
- **Clean**: Removes all nodes from the stack but keeps the stack structure intact.
- **Free**: Frees the entire linked list and the memory allocated for the stack.

## How to Run

1. **Clone the Repository**
   ```bash
   git clone https://github.com/AnnaPronka/Array-and-OLS-in-C.git
   cd Array-and-OLS-in-C
