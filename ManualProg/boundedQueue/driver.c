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
	    enqueue(q,1);
	    enqueue(q,2);
	    enqueue(q,3);
	    enqueue(q,4);
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
        case 3:
	    q = createQueue(5);
            printf("%d\n", dequeue(q));
	    enqueue(q,1);
            printf("%d\n", dequeue(q));
            printf("%d\n", dequeue(q));
   	    printBoundedQueue(q);
            free(q);
        break;
        case 4:
	    q = createQueue(3);
	    enqueue(q,1);
	    enqueue(q,2);
	    enqueue(q,3);
	    enqueue(q,4);
   	    printBoundedQueue(q);
            free(q);
        break;
        case 5:
        {
          int i;
          
	    q = createQueue(300);
	    p = createQueue(300);
            for (i = 0; i < 300; i++ )
            {
               enqueue(p,i);
               enqueue(q,i);
            }
   	    printBoundedQueue(q);
   	    printBoundedQueue(p);
            free(q);
            free(p);
            break;
        }
        case 6:
	    q = createQueue(0);
            enqueue(q,1);
            free(q);
        break;
        case 7:
	    q = createQueue(3);
	    enqueue(q,1);
	    enqueue(q,2);
	    enqueue(q,3);
            printf("%d", dequeue(q));
	    enqueue(q,4);
   	    printBoundedQueue(q);
            free(q);
        break;
        case 8:
	    q = createQueue(3);
	    enqueue(q,1);
	    enqueue(q,2);
	    enqueue(q,-3);
            printf("%d", dequeue(q));
	    enqueue(q,-4);
   	    printBoundedQueue(q);
            free(q);
        break;
        case 9:
	    q = createQueue(0);
            printf("Full: %d\n", isFull(q));
            printf("Empty: %d\n", isEmpty(q));
	    q = createQueue(3);
            printf("Full: %d\n", isFull(q));
            printf("Empty: %d\n", isEmpty(q));
	    enqueue(q,1);
	    enqueue(q,2);
	    enqueue(q,-3);
            printf("Full: %d\n", isFull(q));
            printf("Empty: %d\n", isEmpty(q));
            printf("%d", dequeue(q));
            printf("Full: %d\n", isFull(q));
            printf("Empty: %d\n", isEmpty(q));
	    enqueue(q,-4);
            printf("Full: %d\n", isFull(q));
            printf("Empty: %d\n", isEmpty(q));
   	    printBoundedQueue(q);
            free(q);
        break;
        case 10:
	    q = createQueue(3);
	    enqueue(q,1);
	    enqueue(q,2);
	    enqueue(q,-3);
            printf("%d", dequeue(q));
            printf("%d", dequeue(q));
            printf("%d", dequeue(q));
	    enqueue(q,-4);
            printf("%d", dequeue(q));
   	    printBoundedQueue(q);
            free(q);
        break;
        case 11:
	    q = createQueue(3);
	    enqueue(q,1);
	    enqueue(q,2);
	    enqueue(q,-3);
            printf("%d", dequeue(q));
            printf("%d", dequeue(q));
            printf("%d", dequeue(q));
	    enqueue(q,-4);
	    enqueue(q,-5);
	    enqueue(q,-6);
            printf("%d", dequeue(q));
            printf("%d", dequeue(q));
   	    printBoundedQueue(q);
            free(q);
        break;
        case 12:
	    q = createQueue(2);
	    enqueue(q,1);
	    enqueue(q,2);
	    enqueue(q,-3);
            printf("%d", dequeue(q));
            printf("%d", dequeue(q));
            printf("%d", dequeue(q));
	    enqueue(q,-4);
	    enqueue(q,-5);
	    enqueue(q,-6);
            printf("%d", dequeue(q));
            printf("%d", dequeue(q));
   	    printBoundedQueue(q);
            free(q);
        break;
        case 13:
	    q = createQueue(3);
	    enqueue(q,0);
	    enqueue(q,2);
	    enqueue(q,-3);
            printf("%d", dequeue(q));
	    enqueue(q,-4);
   	    printBoundedQueue(q);
            free(q);
        break;
   }
}
