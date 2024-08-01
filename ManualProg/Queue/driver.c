
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
                display(&q);
            break;
            case 2:
                init(&q);
                enqueue(&q, "1");
                enqueue(&q, "2");
                display(&q);
            break;
            case 3:
                init(&q);
                enqueue(&q, "1");
                enqueue(&q, "2");
                printf("%s%s", dequeue(&q), "\n");
                printf("%s%s", dequeue(&q), "\n");
                display(&q);
            break;
            case 4:
                init(NULL);
            break;
            case 5:
                init(&q);
                enqueue(&q, "1");
                enqueue(&q, "2");
                enqueue(&q, "1");
                enqueue(&q, "2");
                enqueue(&q, "1");
                enqueue(&q, "2");
                enqueue(&q, "1");
                enqueue(&q, "2");
                enqueue(&q, "1");
                enqueue(&q, "2");
                enqueue(&q, "1");
                enqueue(&q, "2");
                display(&q);
            break;
            case 6:
                is_full(NULL);
                enqueue(NULL, NULL);
                dequeue(NULL);
            break;
            case 7:
                init(&q);
                enqueue(&q, "1");
                dequeue(&q);
                dequeue(&q);
                display(&q);
            break;
            case 8:
                init(&q);
                enqueue(&q, "1");
                printf("%s", dequeue(&q));
            break;
            case 9:
                init(&q);
                printf("%s \n", dequeue(&q));
            break;
            case 10:
                printf("%d\n", is_full(NULL));
                printf("%d\n", is_empty(NULL));
            break;
            case 11:
                init(&q);
                printf("%d\n", is_full(&q));
                printf("%d\n", is_empty(&q));
                enqueue(&q, "0");
                printf("%s%s", dequeue(&q), "\n");
                enqueue(&q, "1");
                printf("%s%s", dequeue(&q), "\n");
                enqueue(&q, "2");
                printf("%s%s", dequeue(&q), "\n");
                enqueue(&q, "3");
                printf("%s%s", dequeue(&q), "\n");
                enqueue(&q, "4");
                printf("%s%s", dequeue(&q), "\n");
                enqueue(&q, "5");
                printf("%s%s", dequeue(&q), "\n");
                enqueue(&q, "6");
                printf("%s%s", dequeue(&q), "\n");
                enqueue(&q, "7");
                printf("%s%s", dequeue(&q), "\n");
                enqueue(&q, "8");
                printf("%s%s", dequeue(&q), "\n");
                enqueue(&q, "9");
                printf("%s%s", dequeue(&q), "\n");
                enqueue(&q, "10");
                printf("%s%s", dequeue(&q), "\n");
                enqueue(&q, "11");
                printf("%s%s", dequeue(&q), "\n");
                display(&q);
            break;
            case 12:
                display(NULL);
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
