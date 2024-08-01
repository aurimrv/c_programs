
#include <stdio.h>
#include "Queue.h"

void driver(int tc_number)
{
    char str[30];
    QUEUE q;

     switch (tc_number)
     {
            case 1:
            init(&q);
            enqueue(&q, "1");
            enqueue(&q, "2");
            if (is_full(&q) != -1) {
                printf("Test Case 1 Failed\n");
            }
            break;
        case 2:
            init(&q);
            enqueue(&q, "1");
            dequeue(&q);
            if (is_empty(&q) != 1) {
                printf("Test Case 2 Failed\n");
            }
            break;
        case 3:
            init(&q);
            enqueue(&q, "1");
            enqueue(&q, "2");
            dequeue(&q);
            dequeue(&q);
            if (is_empty(&q) != 1) {
                printf("Test Case 3 Failed\n");
            }
            break;
        case 4:
            init(&q);
            enqueue(&q, "1");
            display(&q);
            break;
        case 5:
            init(&q);
            enqueue(&q, "1");
            enqueue(&q, "2");
            dequeue(&q);
            display(&q);
            break;
        case 6:
            init(&q);
            enqueue(&q, "1");
            enqueue(&q, "2");
            enqueue(&q, "3");
            enqueue(&q, "4");
            dequeue(&q);
            dequeue(&q);
            enqueue(&q, "5");
            enqueue(&q, "6");
            if (is_full(&q) != -1) {
                printf("Test Case 6 Failed\n");
            }
            break;
        case 7:
            init(&q);
            enqueue(&q, "1");
            dequeue(&q);
            dequeue(&q);
            if (is_empty(&q) != 1) {
                printf("Test Case 7 Failed\n");
            }
            break;
        case 8:
            init(&q);
            dequeue(&q);
            if (is_empty(&q) != 1) {
                printf("Test Case 8 Failed\n");
            }
            break;
        case 9:
            init(&q);
            enqueue(&q, "1");
            enqueue(&q, "2");
            dequeue(&q);
            enqueue(&q, "3");
            enqueue(&q, "4");
            if (is_full(&q) != -1) {
                printf("Test Case 9 Failed\n");
            }
            break;
        case 10:
            init(&q);
            dequeue(&q);
            display(&q);
            break;
        default:
            printf("Invalid test case number\n");
            break;
        case 11:
            init(NULL); // Test case to hit line 17: Invalid Queue
            break;
        case 12:
            init(&q);
            is_full(NULL); // Test case to hit line 27: Invalid Queue
            break;
        case 13:
            init(&q);
            is_empty(NULL); // Test case to hit line 37: Invalid Queue
            break;
        case 14:
            enqueue(NULL, "Test"); // Test case to hit line 54: Invalid Queue
            break;
        case 15:
            init(&q);
            for (int i = 0; i < QSIZE; i++) {
                sprintf(str, "Item %d", i);
                enqueue(&q, str);
            }
            enqueue(&q, "Overflow"); // Test case to hit line 60: Queue is full
            break;
        case 16:
            dequeue(NULL); // Test case to hit line 71: Invalid Queue
            break;
        case 17:
            init(&q);
            dequeue(&q); // Test case to hit line 77: Queue is empty
            break;
        case 18:
            display(NULL); // Test case to hit line 88: Invalid Queue
            break;
       }
}

/*
int main()
{
    int choice;
    char str[30];
    QUEUE q;
    pq=&q;
    init();
    do
    {
        printf("\n\n\t\tEnter your Choice:");
        printf("\n\t\t:1 for Add into the Queue.. ");
        printf("\n\t\t:2 for Delete from the Queue.. ");
        printf("\n\t\t:3 Display Elements of the Queue.. ");
        printf("\n\t\t:4 For Exit..\n\t\t\t :: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            if(is_full())
                printf("\n\n\t\t Error: Queue Overflow..!!");
            else
            {
                printf("\n\n\t\t Enter a Name:");
                fflush(stdin);
                gets(str);
                enqueue(str);
            }
            break;
        case 2:
            if(is_empty())
            {
                printf("\n\n\t\t Error: Queue UnderFlow..!!");
                init();
            }
            else
                printf("\n\n\t\t Deleted Queue Element is %s",dequeue());
            break;
        case 3:
            if(is_empty())
                printf("\n\n\t\t Error: Queue is Empty..!!");
            else
                display();
            break;
        case 4:
            exit(0);
        default:
            printf("\n\n\t\t Plz press 1,2,3 or 4 key..");
        }
    }
    while(1);
    return 0;
}
*/
