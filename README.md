# LinkedLists-in-C

A lightweight, macro-based generic linked list implementation in C. This project demonstrates advanced C macro patterns while providing a type-safe, reusable linked list data structure.

**Purpose:** Educational project to improve C logic skills and master macro programming techniques.

---

## Table of Contents

- [Features](#features)
- [Getting Started](#getting-started)
- [Usage](#usage)
  - [Creating a List](#creating-a-list)
  - [Available Functions](#available-functions)
  - [Example Code](#example-code)
- [How It Works](#how-it-works)
- [Limitations](#limitations)
- [Contributing](#contributing)

---

## Features

- ✅ **Type-Safe Generic Lists** - Create linked lists for any data type using macros
- ✅ **Zero Dependencies** - Pure C, no external libraries required
- ✅ **Memory Safe** - Manual memory management with cleanup functions
- ✅ **Learning Resource** - Excellent for understanding C macros and metaprogramming
- ✅ **Simple API** - Easy-to-use function naming convention

---

## Getting Started

### Compilation

```bash
gcc -o main main.c -Wall -Wextra -std=c99
```

### Basic Setup

Include the macro header in your C file and define the list type you need:

```c
#include "your_linked_list_header.h"

// Create a list type for integers
DEFINE_LIST(int, Int);

// Create a list type for floats
DEFINE_LIST(float, Float);
```

---

## Usage

### Creating a List

Use the `DEFINE_LIST(type, name)` macro to generate a linked list type:

```c
DEFINE_LIST(int, Int);
```

This creates:
- A typedef `IntList` - the linked list type
- A struct with size 8 bytes (node pointer + size counter)

**Example:**
```c
printf("Size of IntList: %zu bytes\n", sizeof(IntList));
// Output: Size of IntList: 8
```

### Available Functions

After defining a list with `DEFINE_LIST(type, name)`, the following functions are automatically generated:

| Function | Description | Returns |
|----------|-------------|---------|
| `name_new()` | Create and initialize a new empty list | `nameList` |
| `name_push(list, value)` | Add an element to the front of the list | `void` |
| `name_popHead(list)` | Remove and return the first element | `type` |
| `name_popTail(list)` | Remove and return the last element | `type` |
| `name_find(list, value)` | Search for a value in the list | `int` (1 if found, 0 if not) |
| `name_free(list)` | Free all allocated memory | `void` |

**Naming Convention:**
```c
IntList_new();      // Create new list
IntList_push(...);  // Add element
IntList_popHead(...); // Remove from front
IntList_popTail(...); // Remove from back
IntList_find(...);  // Search
IntList_free(...);  // Cleanup
```

### Example Code

Here's a complete working example:

```c
#include <stdio.h>
#include "linked_list.h"

DEFINE_LIST(int, Int);

int main() {
    // Create a new list
    IntList myList = IntList_new();
    
    // Add elements to the list
    IntList_push(myList, 10);
    IntList_push(myList, 20);
    IntList_push(myList, 30);
    IntList_push(myList, 40);
    
    printf("List size: %d\n", myList.size);
    // Output: List size: 4
    
    // Search for an element
    if (IntList_find(myList, 20)) {
        printf("Found 20 in the list!\n");
    }
    
    // Remove elements
    int head = IntList_popHead(myList);
    printf("Removed from head: %d\n", head);
    // Output: Removed from head: 40
    
    int tail = IntList_popTail(myList);
    printf("Removed from tail: %d\n", tail);
    // Output: Removed from tail: 10
    
    // Free memory
    IntList_free(myList);
    
    return 0;
}
```

---

## How It Works

The `DEFINE_LIST` macro is a metaprogramming tool that generates:

1. **A Node Structure** - Holds data and pointer to next node
2. **A List Structure** - Tracks head pointer and size
3. **API Functions** - All operations (push, pop, find, free)

**Generated Structure (Conceptually):**
```c
// For DEFINE_LIST(int, Int):
typedef struct IntNode {
    int data;
    struct IntNode* next;
} IntNode;

typedef struct {
    IntNode* head;
    int size;
} IntList;
```

This approach provides **type safety** while avoiding code duplication across different data types.

---

## Limitations

- ⚠️ **No Random Access** - Can only iterate from head to tail; use `find()` for searching
- ⚠️ **Manual Memory Management** - Must call `name_free()` to prevent memory leaks
- ⚠️ **Macro Limitations** - Macro expansion can be complex to debug
- ⚠️ **Single-Linked** - Only forward traversal; use a different implementation for bidirectional access

---

## Contributing

Contributions are welcome! Areas for improvement:

- [ ] Add a doubly-linked list variant
- [ ] Add `insert_at()` and `remove_at()` position-based functions
- [ ] Add `print_list()` macro for debugging
- [ ] Add comprehensive unit tests
- [ ] Add support for custom comparison functions

Feel free to open issues or submit pull requests!

---

## License

This is an educational project. Use freely and modify as needed.
