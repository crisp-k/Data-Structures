#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
} node;

typedef struct list {
    struct node *head;
    struct node *tail;
} list;

list *createList(void)
{
    list *newList = (list *) malloc(sizeof(list));

    newList->head = NULL;
    newList->tail = NULL;

    return newList;
}

node *createNode(int data)
{
    node *newNode = (node *) malloc(sizeof(node));

    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

// passing the list as a whole for the sake of the user
list *insertFront(list *list, int data)
{
    node *newNode = createNode(data);

    if(list->head == NULL)
    {
        // we are considering this the first real initialization of the list, 
        // thus we create the next/prev here instead of elsewhere
        list->head = newNode;
        list->head->next = list->tail;
        list->head->prev = list->tail;

        list->tail = newNode;
        list->tail->next = list->head;
        list->tail->prev = list->tail;
    }
    else
    {
        // otherwise new node is now the head
        // tail is updated accordingly
        newNode->next = list->head;
        newNode->prev = list->tail;

        list->head->prev = newNode;
        list->tail->next = newNode;

        list->head = newNode;
    }

    return list;
}

void printListForwards(list *list)
{
    node *traversal = list->head;

    if(traversal == NULL)
    {
        printf("List empty!\n");
        return;
    }

    // first time using a do-while loop out of neccessity honestly
    do
    {
        printf("%d ", traversal->data);
        traversal = traversal->next;
    } while(traversal != list->head);

    printf("\n");
}

void printListBackwards(list *list)
{
    node *traversal = list->tail;

    if(list->tail == NULL)
    {
        printf("List empty!\n");
        return;
    }

    do
    {
        printf("%d ", traversal->data);
        traversal = traversal->prev;
    } while(traversal != list->tail);

    printf("\n");
}

int main(void)
{
    list *list = createList();

    for(int i = 10; i >= 0; i--)
        list = insertFront(list, i);

    printListForwards(list);
    printListBackwards(list);

}