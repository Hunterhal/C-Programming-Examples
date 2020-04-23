#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char date[10];
    int cases;
    int deaths;
    struct node *next;
}node_t;

//This function adds new node to beginning of the linked list
//The string data is parsed inside the function
void push(node_t** head_ref, char* date, int cases, int deaths)
{
    node_t* new_node = malloc(sizeof(node_t));

    strcpy(new_node->date, date);
    new_node->cases = cases;
    new_node->deaths = deaths;

    new_node->next = *head_ref;
    *head_ref = new_node;
}

//This function pops the first node of the list
char* pop(node_t **head_ref)
{
    char date[10];
    int cases;
    int deaths;

    char *return_buffer;

    return_buffer = (char*) malloc(sizeof(char) * 30);

	node_t *temp = *head_ref;

    //Check if head reference is NULL
    if(*head_ref == NULL)
    {
        puts("List is empty");
        return;
    }

    //This pops the node, most important part
	*head_ref = (*head_ref)->next;

    strcpy(date, temp->date);
    cases = temp->cases;
    deaths = temp->deaths;

    sprintf(return_buffer, "%s %d %d\n", date, cases, deaths);

	return return_buffer;
}

//This function lists the linked list
void list(node_t *head)
{
    node_t *temp = head;
    if(head == NULL)
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

int main(void)
{
    node_t *head = NULL;
    FILE *f;
    char buffer[30];
    char date[10];
    int cases;
    int deaths;

    push(&head, "12.03.2020", 251, 46);
    push(&head, "13.03.2020", 241, 47);

    puts(pop(&head));
    puts(pop(&head));

    //open the file for reading
    f = fopen("covid.txt", "r");

    while(!feof(f))
    {
        fgets(buffer, 30, f);
        sscanf(buffer, "%s %d %d\n", date, &cases, &deaths);
        push(&head, date, cases, deaths);

    }

    list(head);

    fclose(f);
}
