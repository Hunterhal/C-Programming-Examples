#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node {
    char date[11];
    int cases;
    int deaths;
    struct node* next;
}node_t;

typedef struct queue {
    node_t* front;
    node_t* rear;
    int size;
    int capacity;
}queue_t;

queue_t* init_q(int capacity) {
    queue_t* new_queue = (queue_t*)malloc(sizeof(queue_t));
    new_queue->rear = NULL;
    new_queue->front = NULL;
    new_queue->size = 0;
    new_queue->capacity = capacity;
    return new_queue; //when I exit, new_queue goes out of scope, but the space allocated for it remains
}

void check_q(queue_t* queue) {
    if (queue->front == NULL) //front is null then for sure q empty
        printf("Queue is empty!\n");
    else if (queue->capacity == queue->size)
        printf("Queue is full!\n");
}

void enqueue(queue_t* q, char* date, int cases, int deaths);
char* dequeue(queue_t* q);
void list(queue_t* q);
void copy_queue(queue_t* dest, queue_t* source, int print);

void enqueue(queue_t* q, char* date, int cases, int deaths)
{
    node_t* new_node = malloc(sizeof(node_t));

    strcpy(new_node->date, date);
    new_node->cases = cases;
    new_node->deaths = deaths;
    new_node->next = NULL;

    if (q->rear == NULL)
    {
        q->front = new_node;
        q->rear = new_node;
    }
    else if (q->size == q->capacity)
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
char* dequeue(queue_t* q)
{
    char date[10];
    int cases;
    int deaths;

    char* return_buffer;

    return_buffer = (char*)malloc(sizeof(char) * 30);

    node_t* temp = q->front;

    //Check if head reference is NULL
    if (q->front == NULL)
    {
        puts("Queue is empty");
        return NULL;
    }

    //This pops the node, most important part
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    strcpy(date, temp->date);
    cases = temp->cases;
    deaths = temp->deaths;

    sprintf(return_buffer, "%s %d %d\n", date, cases, deaths);

    free(temp);

    q->size--;
    return return_buffer;
}

//This function lists the linked list
void list(queue_t* q)
{
    node_t* temp = q->front;
    if (temp == NULL)
    {
        puts("List is empty\n");
        return;
    }
    while (temp != NULL)
    {
        printf("Date: %s, Cases: %d, Deaths: %d\n", temp->date, temp->cases, temp->deaths);
        temp = temp->next;
    }
}

void copy_queue(queue_t* dest, queue_t* source, int print)
{
    node_t* temp = source->front;

    if (source->front == NULL)
    {
        puts("Source Queue is empty !!!");
    }

    while (temp != NULL)
    {
        enqueue(dest, temp->date, temp->cases, temp->deaths);
        temp = temp->next;
        if (print == 1)
        {
            puts("Destination queue is");
            list(dest);
            puts("");
        }

    }
}

//This code written using algorithm at
//https://codeforwin.org/2015/09/c-program-to-reverse-singly-linked-list.html
void reverse_queue(queue_t* q)
{
    node_t* head, * prevNode, * currNode;
    head = q->front;
    prevNode = head;
    head = head->next;
    currNode = head;
    prevNode->next = NULL;
    while (head != NULL)
    {
        head = head->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = head;
    }
    head = prevNode;

    q->rear = q->front;
    q->front = head;
}

void calculate_cummulative(queue_t* q)
{
    node_t* temp = q->front;
    int previous_cases = 0, previous_deaths = 0;

    while (temp->next != NULL)
    {
        temp->next->cases += temp->cases;
        temp->next->deaths += temp->deaths;
        temp = temp->next;
    }
}

void kdr(queue_t *q){
    double KDR;node_t*temp=q->front;
    
    if(temp==NULL){
        printf("List is empty.\n");
        return;
    }
    while(temp!=NULL){
        KDR=((double)(temp->deaths))/((double)(temp->cases));
        printf("Date:%s Deaths:%d Cases:%d KDR:%lf\n",temp->date,temp->deaths,temp->cases,KDR);
        temp=temp->next;
    }
}

void cumlt_q(queue_t*orig,queue_t*cumlt){
    copy_queue(cumlt,orig,0);
    calculate_cummulative(cumlt);
}

int main(void)
{
    //Create queue
    queue_t* covid_queue = init_q(1000);

    FILE* f;
    char buffer[30];
    char date[10];
    int cases;
    int deaths;

    enqueue(covid_queue, "18.04.2020", 80, 1);
    enqueue(covid_queue, "19.04.2020", 50, 0);

    puts(dequeue(covid_queue));
    puts(dequeue(covid_queue));

    //open the file for reading
    f = fopen("covid.txt", "r");

    while (!feof(f))
    {
        fgets(buffer, 30, f);
        sscanf(buffer, "%s %d %d\n", date, &cases, &deaths);
        enqueue(covid_queue, date, cases, deaths);
    }

    list(covid_queue);

    fclose(f);

    queue_t* weekly_covid = malloc(sizeof(queue_t));
    weekly_covid->rear = NULL;
    weekly_covid->front = NULL;
    weekly_covid->size = 0;
    weekly_covid->capacity = 7;

    puts("Weekly Queue is");
    copy_queue(weekly_covid, covid_queue, 0);

    reverse_queue(covid_queue);
    /*reverse the queue to fix it
      because in the text file, the first line is the most recent date
      then the first in into the queue is actually the most recent date
      it should be the opposite, the first enqueued should be the oldest date*/

    queue_t*cumulative_q=init_q(1000);
    cumlt_q(covid_queue,cumulative_q);

    kdr(cumulative_q);

}