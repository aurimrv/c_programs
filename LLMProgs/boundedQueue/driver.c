#include <stdio.h>
#include <malloc.h>
#include "boundedQueue.h"

void driver(int argc, char  *argv[])
{
int tc_number;
BoundedQueue  * q, * p;

   tc_number = atoi(argv[1]);
   switch (tc_number)
   {
        case 1:
            q = createQueue(5);
            enqueue(q, 1);
            enqueue(q, 2);
            enqueue(q, 3);
            enqueue(q, 4);
            printBoundedQueue(q);
            free(q);
            break;
        case 2:
            q = createQueue(0);
            free(q);
            q = createQueue(-1);
            printf("%d\n", q == NULL);
            free(q);
            break;
        case 3: // Test case for isEmpty
            q = createQueue(3);
            printf("%d\n", isEmpty(q));
            free(q);
            break;
        case 4: // Test case for isFull
            q = createQueue(2);
            enqueue(q, 1);
            enqueue(q, 2);
            printf("%d\n", isFull(q));
            free(q);
            break;
        case 5: // Test case for dequeue
            q = createQueue(3);
            enqueue(q, 1);
            enqueue(q, 2);
            enqueue(q, 3);
            printf("Dequeued: %d\n", dequeue(q));
            printBoundedQueue(q);
            free(q);
            break;
        case 6:
            q = createQueue(5);
            enqueue(q, 1);
            enqueue(q, 2);
            enqueue(q, 3);
            enqueue(q, 4);
            printBoundedQueue(q);
            free(q);
            break;
        case 7:
            q = createQueue(0);
            free(q);
            q = createQueue(-1);
            printf("%d\n", q == NULL);
            free(q);
            break;
        case 8: // Test case for isEmpty
            q = createQueue(3);
            printf("Queue is empty: %d\n", isEmpty(q));
            enqueue(q, 5);
            printf("Queue is empty after enqueue: %d\n", isEmpty(q));
            free(q);
            break;
        case 9: // Test case for isFull
            q = createQueue(2);
            enqueue(q, 1);
            enqueue(q, 2);
            printf("Queue is full: %d\n", isFull(q));
            printf("Dequeue element: %d\n", dequeue(q));
            printf("Queue is full after dequeue: %d\n", isFull(q));
            free(q);
            break;
        case 10: // Test case for dequeue
            q = createQueue(3);
            enqueue(q, 1);
            enqueue(q, 2);
            enqueue(q, 3);
            printf("Dequeued element: %d\n", dequeue(q));
            printBoundedQueue(q);
            free(q);
            break;
        case 11:
            q = createQueue(10);
            for (int i = 0; i < 10; i++) {
                enqueue(q, i + 1);
            }
            printf("Queue is full: %d\n", isFull(q));
            printBoundedQueue(q);
            free(q);
            break;
        case 12:
            q = createQueue(5);
            printf("Queue is empty: %d\n", isEmpty(q));
            enqueue(q, 10);
            printf("Queue is empty after enqueue: %d\n", isEmpty(q));
            printBoundedQueue(q);
            free(q);
            break;
        case 13:
            q = createQueue(3);
            enqueue(q, 1);
            enqueue(q, 2);
            printf("Dequeued element: %d\n", dequeue(q));
            printf("Queue is full: %d\n", isFull(q));
            enqueue(q, 3);
            printf("Dequeue element: %d\n", dequeue(q));
            printf("Queue is empty: %d\n", isEmpty(q));
            free(q);
            break;
        case 14:
            q = createQueue(4);
            enqueue(q, 100);
            printf("Queue is full: %d\n", isFull(q));
            printf("Dequeued element: %d\n", dequeue(q));
            printf("Queue is empty: %d\n", isEmpty(q));
            free(q);
            break;
        case 15:
            q = createQueue(3);
            enqueue(q, 10);
            enqueue(q, 20);
            printf("Dequeued element: %d\n", dequeue(q));
            printf("Queue is empty: %d\n", isEmpty(q));
            printf("Queue is full: %d\n", isFull(q));
            free(q);
            break;
        default:
            printf("Invalid test case number.\n");
            break;
        case 16:
            q = createQueue(2);
            enqueue(q, 10);
            enqueue(q, 20);
            enqueue(q, 30); // Exceeds capacity, should print "Queue is Full"
            printBoundedQueue(q);
            free(q);
            break;
        case 17:
            q = createQueue(2);
            dequeue(q); // Dequeue from empty queue, should print "Queue is already empty!"
            free(q);
            break;
        case 18:
            q = createQueue(1);
            dequeue(q); // Dequeue from empty queue, should print "Queue is already empty!"
            enqueue(q, 100);
            dequeue(q); // Empty queue again, should print "Queue is already empty!"
            printf("Dequeued: %d\n", dequeue(q)); // Trying to dequeue again, should return -1
            free(q);
            break;
        default:
            printf("Invalid test case number.\n");
            break;
   }
}
