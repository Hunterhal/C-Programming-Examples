#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Node for adjency list represents edges
typedef struct node{
    int dest;
    struct node *next;
}node_t;

//Adjency list
typedef struct adjency_list{
    node_t *head;
}adjency_list_t;

//Graph
typedef struct graph{
    int number_of_vertices;
    adjency_list_t *list;
}graph_t;

typedef struct queue{
    node_t *front;
    node_t *rear;
    int size;
    int capacity;
}queue_t;

node_t *create_node( int dest )
{
    node_t *new_node = malloc( sizeof(node_t) );
    new_node->dest = dest;
    new_node->next = NULL;
    return new_node;
}

void enqueue(queue_t* q, int dest);
int dequeue(queue_t *q);

void enqueue(queue_t* q, int dest)
{
    node_t* new_node = malloc(sizeof(node_t));

    new_node->dest = dest;
    new_node->next = NULL;

    if(q->rear == NULL)
    {
        q->front = new_node;
        q->rear = new_node;
    }
    else if(q->size == q->capacity)
    {
        dequeue(q);
        q->rear->next = new_node;
        q->rear = new_node;
    }
    else
    {
        q->rear->next = new_node;
        q->rear = new_node;
    }
    
    q->size++;
}

//This function pops the first node of the list
int dequeue(queue_t *q)
{
    int dest;

	node_t *temp = q->front;

    //Check if head reference is NULL
    if(q->front == NULL)
    {
        puts("Queue is empty");
        return -1;
    }

    //This pops the node, most important part
	q->front = q->front->next;

    if(q->front == NULL)
        q->rear = NULL;
    
    dest = temp->dest;
    free(temp);

    q->size--;

	return dest;
}

graph_t *create_graph( int n )
{
    graph_t *graph = malloc( sizeof(graph_t) );

    graph->list = malloc( sizeof(node_t) * n );
    graph->number_of_vertices = n;

    for(int i=0; i<n; i++)
        graph->list[i].head = NULL;

    return graph;
}

void add_edge( graph_t *graph, int src, int dest)
{
    node_t *new_node = create_node( dest );
    new_node->next = graph->list[src].head; 
    graph->list[src].head = new_node;

    new_node = create_node( src );
    new_node->next = graph->list[dest].head; 
    graph->list[dest].head = new_node;
}

void print_graph( graph_t *graph )
{
    for(int i=0; i < graph->number_of_vertices; i++)
    {
        node_t *temp = graph->list[i].head;
        while( temp!=NULL )
        {
            printf("(%d -> %d)   ", i , temp->dest);
            temp = temp->next;
        }

        puts("");
    }
}

queue_t *create_queue( int capacity)
{
    //Create queue
    queue_t *new_queue = malloc(sizeof(queue_t));
    new_queue->rear = NULL;
    new_queue->front = NULL;
    new_queue->size = 0;
    new_queue->capacity = capacity;

    return new_queue;
}

int is_queue_empty( queue_t *q )
{
    if( q->size == 0)
        return 1;
    return 0;
}

void bfs( graph_t *graph, int start_vertex)
{
    int visited[ graph->number_of_vertices ];
    for( int i=0; i < graph->number_of_vertices; i++)
        visited[i] = 0;

    queue_t *q = create_queue( 10 );

    visited[ start_vertex ] = 1;
    enqueue(q, start_vertex);

    while( ! is_queue_empty( q ) )
    {
        int currentVertex = dequeue(q);
        printf("Visited %d\n", currentVertex);

        node_t* temp = graph->list[currentVertex].head;

        while (temp) 
        {
            int adjVertex = temp->dest;

            if (visited[adjVertex] == 0) 
            {
                visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }

}

void main()
{
    graph_t *new_graph;

    new_graph = create_graph( 5 );

    add_edge( new_graph, 0, 1);
    add_edge( new_graph, 0, 2);
    add_edge( new_graph, 1, 2);
    add_edge( new_graph, 1, 3);
    add_edge( new_graph, 3, 0);
    add_edge( new_graph, 3, 4);

    print_graph( new_graph );

    bfs( new_graph, 1);

    return;
}