typedef struct 
{
	int capacity;
	int size;
	int front;
	int back;
	int *elements;
}   BoundedQueue; 

BoundedQueue * createQueue(int maxElements);

