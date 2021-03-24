#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node;

node *createNode(int data)
{
    node *newNode = (node*) malloc(sizeof(node));

    newNode->data = data;
    newNode->next = NULL;

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
        head = newNode;
    }

    return head;
}

node *insertEnd(node *head, int data)
{
    node *newNode = createNode(data);

    if(head == NULL)
        head = newNode;
    else if(head->next == NULL)
    {
        head->next = newNode;
    }
    else
    {
        node *traversal = head;

        while(traversal->next != NULL)
            traversal = traversal->next;

        traversal->next = newNode;
    }

    return head;
}

node *insertAfter(node *head, int data, int newData)
{
    node *newNode = createNode(newData);

    if(head == NULL)
        head = newNode;
    else if(head->next == NULL)
        head->next = newNode;
    else
    {
        node *traversal = head;

        while(traversal->data != data && traversal != NULL)
            traversal = traversal->next;

        if(traversal == NULL)
            printf("Node not found\n");

        newNode->next = traversal->next;
        traversal->next = newNode;
    }

    return head;
}

node *delete(node *head, int data)
{
    node *traversal;

    if(head == NULL)
        return head;
    else if(head->data == data)
    {
        traversal = head->next;
        
        free(head);

        head = traversal;
    }
    else
    {
        node *delete;

        while(traversal->next->data != data && traversal->next != NULL)
            traversal = traversal->next;

        if(traversal->next == NULL)
            printf("Node not found\n");
        else
        {
            delete = traversal->next;

            traversal->next = delete->next;

            free(delete);
        }
    } 

    return head;
}

node *search(node *head, int data)
{
    if(head == NULL)
    {
        printf("List empty!\n");
        return head;
    }
        
    else
    {
        node *traversal = head;

        while(traversal->data != data && traversal != NULL)
            traversal = traversal->next;

        if(traversal == NULL)
            printf("Node not found!\n");
        

        return traversal;
    }
}

void updateNode(node *head, int data, int newData)
{
    node *updateNode = search(head, data);

    updateNode->data = newData;
}


void printList(node* head)
{
    node *traversal = head;

    if(head == NULL)
    {
        printf("List empty!\n");
        return;
    }
    
    while(traversal != NULL)
    {
        printf("%i ", traversal->data);
        traversal = traversal->next;
    }

    printf("\n");
}

void sortList(node *head)
{
    node *traversal, *sweep;
    int temp;

    traversal = head;

    while(traversal->next != NULL)
    {
        sweep = traversal;

        while(sweep != NULL)
        {
            if(sweep->data <= traversal->data)
            {
                temp = sweep->data;
                sweep->data = traversal->data;
                traversal->data = temp;
            }

            sweep = sweep->next;
        }

        traversal = traversal->next;
    }
}

node *deleteList(node *head)
{
    node *temp;
    while(head != NULL)
    {
        temp = head;
        head = head->next;
        
        free(temp);
    }


    return head;
}

int main(void)
{
    node *list = NULL;

    for(int i = 0; i < 5; i++)
    {
        list = insertFront(list, i);
        list = insertEnd(list, i);
    }
        

    list = insertAfter(list, 2, 6);

    list = delete(list, 6);

    printList(list);

    node *desiredNode = search(list, 4);
    printf("node: %i\n", desiredNode->data);

    updateNode(list, 3, 5);
    printList(list);

    sortList(list);
    printList(list);

    list = deleteList(list);
    printList(list);

    free(list);

    return 0;
}