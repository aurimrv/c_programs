
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
        case 0:
            push(0);
            push(1);
            printf("%d\n", pop());
            print_stack();
        break;
        case 1:
            pop();
            printf("%d\n", isEmpty());
            print_stack();
            break;
        case 2:            
            push(0);
            push(-1);
            printf("%d\n", pop());
            printf("%d\n", pop());
            print_stack();
            push(0);
            push(-1);
            printf("%d\n", pop());
            print_stack();
        break;
        case 3:
            push(0);
            push(1);
            print_stack();
        break;
        case 4:
            push(0);
            join(NULL, top);
        break;
        case 5:
            push(0);
            push(-1);
            push(1);
            push(2);
            push(3);
            push(4);
            push(5);
            push(6);
            push(7);
            push(8);
            print_stack();
        break;
        case 6:
            push(0);
            push(-1);
            push(1);
            push(2);
            push(3);
            push(4);
            printf("%d\n", removeBottom());
            push(5);
            push(6);
            push(7);
            push(8);
            print_stack();
        break;
        case 7:
            push(2);
            push(3);
            push(4);
            printf("%d\n", removeBottom());
            push(5);
            push(6);
            push(7);
            push(8);
            print_stack();
        break;
        case 8:
            for (i = 0; i < 1024 * 1024; i++)
            {
                 push(i);
            }
            for (i = 0; i < 1024 * 1024 - 10; i++)
            {
                 pop();
            }
            print_stack();
        break;
        case 9:
            push(2);
            printf("%d\n", removeBottom());
            push(5);
            push(6);
            push(7);
            push(8);
            print_stack();
        break;
        case 10:
            push(-2);
            printf("%d\n", removeBottom());
            push(0);
            push(6);
            printf("%d\n", removeBottom());
            push(7);
            push(8);
            print_stack();
        break;
    }
}
