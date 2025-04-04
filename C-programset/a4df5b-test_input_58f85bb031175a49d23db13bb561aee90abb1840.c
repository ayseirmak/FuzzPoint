#include <stdio.h>
#include <stdlib.h>

// Structure definition for a node in a singly linked list.
struct foo {
    struct foo *next;
};

// Function prototypes.
struct foo *test(struct foo *node);
int bar(void);
int baz(void);

// Function definition for `bar`, always returns 0.
int bar(void) {
    return 0;
}

// Function definition for `baz`, always returns 0.
int baz(void) {
    return 0;
}

// Function definition for `test`, traverses the linked list and can potentially stop early.
struct foo *test(struct foo *node) {
    while (node) {
        if (bar() && !baz()) {
            break;
        }
        node = node->next;
    }
    return node;
}

// Main function, sets up the linked list, tests the functionality, and ensures correctness.
int main(void) {
    struct foo a, b, *c;

    // Initialize the linked list where `b.next` is set to NULL to avoid undefined behavior.
    a.next = &b;
    b.next = NULL;

    // Call `test` and check if the returned pointer is NULL.
    c = test(&a);

    // `test` should return NULL since `bar()` always returns 0, meaning the loop never breaks early.
    if (c != NULL) {
        abort();  // If c is not NULL, something went wrong.
    }

    // Exit the program successfully.
    exit(0);
}