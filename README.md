# Circular Singly Linked List Implementation in C++

This repository contains an implementation of a circular singly linked list using C++ and Object-Oriented Programming principles.

## Overview

### Classes
- **Node**: Represents individual nodes in the circular singly linked list.
- **Iterator**: Provides iteration capabilities over the linked list.
- **CircularSinglyLinkedList**: Implements the circular singly linked list and its functionalities.

## Classes and Functionality

### Node Class
The `Node` class represents individual elements in the circular singly linked list. Each node holds:
- `data`: Data of type `T`.
- `next`: Pointer to the next node.

### Iterator Class
The `Iterator` class provides functionality for iterating through the circular singly linked list. It includes methods to:
- Access node data.
- Set node data.
- Move to the next node.
- Access the current node.

### CircularSinglyLinkedList Class
The `CircularSinglyLinkedList` class implements a circular singly linked list with the following functionalities:
- Retrieving the head and tail nodes.
- Finding elements by value or index.
- Inserting elements at the beginning, end, or specific indices.
- Deleting nodes from the front, back, or at specific indices.
- Checking the existence of a value in the list.
- Concatenating two circular singly linked lists.
- Sorting the list in ascending or descending order.
- Removing duplicate elements.
- Swapping the positions of two elements.
- Updating the value of a specific node.
- Reversing the order of elements.
- Clearing the entire linked list.
- Printing the elements of the linked list.

## Usage

To use this circular singly linked list implementation, follow these steps:
1. Clone the repository.
2. Include the necessary header files in your C++ code: `Node.h`, `Iterator.h`, and `CircularSinglyLinkedList.h`.
3. Create a `CircularSinglyLinkedList` object and utilize its functionalities as per your requirements.

## Example

```cpp
// Example usage of the CircularSinglyLinkedList class
#include "CircularSinglyLinkedList.h"

int main() {
    CircularSinglyLinkedList<int> myIntsList; // list of integers
    CircularSinglyLinkedList<string> myStringsList; // list of strings
    
    // Perform operations like insertion, deletion, and retrieval here
    
    return 0;
}
