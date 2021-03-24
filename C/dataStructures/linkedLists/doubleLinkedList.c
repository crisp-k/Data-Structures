#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
} node;

node *createNode(int data)
{
    node *newNode = (node *) malloc(sizeof(node));

    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

node *insertFront(node *head, int data)
{
    node *newNode = createNode(data);

    if(head == NULL)
        head = newNode;
    else
    {
        newNode->next = head;
        head->prev = newNode;

        head = newNode;
    }

    return head;
}

node *insertEnd(node *head, int data)
{
    node *newNode = createNode(data);

    if(head->next == NULL)
    {
        head->next = newNode;
        newNode->prev = head;
    }
    else
    {
        node *traversal = head;

        while(traversal->next != NULL)
            traversal = traversal->next;

        traversal->next = newNode;
        newNode->prev = traversal;
    }

    return head;
}

node *insertAfter(node *head, int data, int newData)
{
    node *newNode = createNode(newData);
    node *traversal = head;

    while(traversal->data != data && traversal != NULL)
        traversal = traversal->next;

    if(traversal == NULL)
        printf("Node not found!\n");
    else
    {
        newNode->next = traversal->next;
        newNode->prev = traversal;

        traversal->next = newNode;
    }

    return head;
}

node *delete(node *head, int data)
{
    node *deleteNode;

    if(head == NULL)
    {
        printf("List empty!\n");
    }
    else if(head->data == data)
    {
        deleteNode = head;
        head = head->next;

        free(deleteNode);
    }
    else
    {
        node *traversal = head;
        
        while(traversal->next->data != data && traversal != NULL)
            traversal = traversal->next;

        if(traversal == NULL)
            printf("Node not found\n");
        else
        {
            deleteNode = traversal->next;

            deleteNode->next->prev = traversal;
            traversal->next = deleteNode->next;

            free(deleteNode);
        }
    }

    return head;
}

node *search(node *head, int data)
{
    node *traversal = head;

    while(traversal->data != data && traversal->next != NULL)
        traversal = traversal->next;

    if(traversal->next == NULL)
    {
        printf("Node not found!\n");
        return NULL;
    }

    return traversal;
    
}

void update(node *head, int data, int newData)
{
    node *traversal = search(head, data);

    traversal->data = newData;
}

void sortList(node *head)
{
    if(head == NULL)
    {
        printf("List sorted.\n");
    }
    else
    {
        node *traversal = head;
        node *compare;
        int temp;

        while(traversal->next != NULL)
        {
            compare = traversal;

            while(compare != NULL)
            {
                if(compare->data < traversal->data)
                {
                    temp = traversal->data;
                    traversal->data = compare->data;
                    compare->data = temp;
                }

                compare = compare->next;
            }

            traversal = traversal->next;
        }
    }
}

void printList(node *head)
{
    if(head == NULL)
    {
        printf("List empty!\n");
        return;
    }  
    else
    {
        node *traversal = head;
        
        while(traversal != NULL)
        {
            printf("%i ", traversal->data);
            traversal = traversal->next;
        }

        printf("\n");
    }
}

node *deleteList(node *head)
{
    if(head == NULL)
        printf("List already empty!");
    else
    {
        while(head != NULL)
        {
            node *temp = head;
            head = head->next;

            free(temp);
        }
    }

    return head;
}

int main(void)
{
    node *list = NULL;

    printList(list);

    for(int i = 0; i <= 5; i++)
    {
        list = insertFront(list, i);
        list = insertEnd(list, i);
        list = insertAfter(list, i, i * 5);
    }

    list = delete(list, 5);
    list = delete(list, 20);

    printList(list);

    node *searchedNode;
    searchedNode = search(list, 23);

    searchedNode = search(list, 15);
    printf("Searched node data: %i\n", searchedNode->data);

    sortList(list);
    printList(list);

    list = deleteList(list);
    printList(list);

    return 0;
}