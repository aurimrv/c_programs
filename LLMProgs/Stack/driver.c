
#include <stdio.h>

#include "stack.h"

extern link top;
extern link bottom;
extern int size;


void driver(int tc_number, int argc, char *argv[])
{
int i;

    switch (tc_number)
    {
        case 1:
            // Test case for push and pop functions
            push(0);
            push(-1);
            printf("Popped value: %d\n", pop());
            printf("Popped value: %d\n", pop());
            print_stack();
            break;
        
        case 2:
            // Test case for isEmpty function
            printf("Is stack empty? %s\n", isEmpty() ? "Yes" : "No");
            break;
        
        case 3:
            // Test case for removeBottom function
            push(10);
            push(20);
            push(30);
            printf("Removed element from bottom: %d\n", removeBottom());
            print_stack();
            break;
        
        case 4:
            // Test case for push and pop with multiple elements
            push(5);
            push(10);
            push(15);
            push(20);
            printf("Popped value: %d\n", pop());
            printf("Popped value: %d\n", pop());
            print_stack();
            break;

        case 5:
            // Test case for removeBottom with multiple elements
            push(3);
            push(6);
            push(9);
            printf("Removed element from bottom: %d\n", removeBottom());
            printf("Removed element from bottom: %d\n", removeBottom());
            print_stack();
            break;

        case 6:
            // Test case for push and pop with large number of elements
            for (int i = 0; i < 1000; ++i) {
                push(i);
            }
            printf("Popped value: %d\n", pop());
            printf("Popped value: %d\n", pop());
            print_stack();
            break;
        
        case 7:
            // Test case for removing all elements
            while (!isEmpty()) {
                printf("Popped value: %d\n", pop());
            }
            printf("Is stack empty? %s\n", isEmpty() ? "Yes" : "No");
            break;

        case 8:
            // Test case for pushing and popping alternating between stacks
            push(1);
            printf("Popped value from stack 1: %d\n", pop());
            push(2);
            printf("Popped value from stack 2: %d\n", pop());
            push(3);
            push(4);
            printf("Popped value from stack 1: %d\n", pop());
            printf("Popped value from stack 2: %d\n", pop());
            print_stack();
            break;

        case 9:
            // Test case for pushing and removing from bottom with alternating stacks
            push(100);
            push(200);
            printf("Removed element from bottom of stack 1: %d\n", removeBottom());
            push(300);
            push(400);
            printf("Removed element from bottom of stack 2: %d\n", removeBottom());
            print_stack();
            break;

        // Add more test cases for other functions as needed
        
        default:
            printf("Invalid test case number\n");
            break;
    }
}
