/* This code based from the website below to demonstrate
queue using array in the lecture, please refer to site:
https://www.geeksforgeeks.org/queue-set-1introduction-and-array-implementation/
Halil DURMUÞ 09.03.2018
BLG221 Data Structures ITU
*/
// C program for array implementation of queue
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// A structure to represent a queue
struct Queue
{
	int front, rear, size;
	unsigned capacity;
	int* array;
};

// function to create a queue of given capacity. 
// It initializes size of queue as 0
struct Queue* createQueue(unsigned capacity)
{
	struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
	queue->capacity = capacity;
	queue->front = queue->size = 0;
	queue->rear = capacity - 1;  // This is important, see the enqueue
	queue->array = (int*)malloc(queue->capacity * sizeof(int));
	return queue;
}

// Queue is full when size becomes equal to the capacity 
int isFull(struct Queue* queue)
{
	return (queue->size == queue->capacity);
}

// Queue is empty when size is 0
int isEmpty(struct Queue* queue)
{
	return (queue->size == 0);
}

// Function to add an item to the queue.  
// It changes rear and size
void enqueue(struct Queue* queue, int item)
{
	if (isFull(queue))
		return;
	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->array[queue->rear] = item;
	queue->size = queue->size + 1;
	printf("%d enqueued to queue\n", item);
}

// Function to remove an item from queue. 
// It changes front and size
int dequeue(struct Queue* queue)
{
	if (isEmpty(queue))
		return INT_MIN;
	int item = queue->array[queue->front];
	queue->front = (queue->front + 1) % queue->capacity;
	queue->size = queue->size - 1;
	return item;
}

// Function to get front of queue
int front(struct Queue* queue)
{
	if (isEmpty(queue))
		return INT_MIN;
	printf("Front index : %d\n", queue->front);
	return queue->array[queue->front];
}

// Function to get rear of queue
int rear(struct Queue* queue)
{
	if (isEmpty(queue))
		return INT_MIN;
	printf("Rear index : %d\n", queue->rear);
	return queue->array[queue->rear];
}

void printQueue(struct Queue* queue)
{
    if(isEmpty(queue))
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Right is front.\n");
    int i = queue->rear;
    int s = queue->size;
    while(s-->0)
    {
        printf("%d ", queue->array[i]);
        i = (i-1)%queue->capacity;
    } 
    printf("\n");
    
}

// Driver program to test above functions./
int main()
{
	struct Queue* queue = createQueue(1000);

	enqueue(queue, 10);
	enqueue(queue, 20);
	enqueue(queue, 30);
	enqueue(queue, 40);

	printf("%d dequeued from queue\n", dequeue(queue));

	printf("Front item is %d\n", front(queue));
	printf("Rear item is %d\n", rear(queue));

	getchar();
	return 0;
}
