#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *next;
    int data;
};

struct List
{
    struct Node *head;
};

typedef struct List List;
typedef struct Node Node;

void
list_initialize(List *list)
{
    if(list == NULL) {
        printf("list initialize failed\n");
        return;
    }

    list -> head = NULL;
}

void
list_insert_tail(List *list, int data)
{
    if(list == NULL) {
        printf("list insert failed\n");
        return;
    }

    Node *node = (Node *)malloc(sizeof(Node));

    if(node == NULL) {
        printf("malloc error");
    }

    //initialize new node
    node -> next = NULL;
    node -> data = data;

    if(list -> head == NULL) {
        list -> head = node;
        return;
    }

    Node *ptr = list -> head;

    while(ptr -> next != NULL)
        ptr = ptr -> next;

    ptr -> next = node;
}

void
list_print(List *list)
{
    if(list == NULL)
        return;
    printf("print list:\n");
    Node *ptr = list -> head;

    int cnt = 0;
    while(ptr != NULL) {
        printf("   Node: %d\nAddress: %p\n   Data: %d\n   Next: %p\n\n",
               ++cnt, ptr, ptr -> data, ptr -> next);
        ptr = ptr -> next;
    }
    printf("finish!\n");
}

void
list_insert_node(List *list, Node *node)
{
    if(list == NULL || node == NULL)
        return;
    node -> next = NULL;
    if(list -> head == NULL) {
        list -> head = node;
        return;
    }

    Node *ptr = list -> head;

    while(ptr -> next != NULL)
        ptr = ptr -> next;

    ptr -> next = node;
}

void
list_release(List *list)
{
    if(list == NULL)
        return;

    Node *ptr = list -> head;
    Node *temp;

    while(ptr != NULL) {
        temp = ptr;
        ptr = ptr -> next;
        free(temp);
    }

    list -> head = NULL;
}

void
list_merge(List *list_1, List *list_2, List *list_merged)
{
    if(list_1 == NULL || list_2 == NULL || list_merged == NULL)
        return;
    Node *p1 = list_1 -> head;
    Node *p2 = list_2 -> head;
    Node *temp;
    while(p1 != NULL && p2 != NULL) {
        if(p1 -> data < p2 -> data) {
            temp = p1 -> next;
            list_insert_node(list_merged, p1);
            p1 = temp;
        }
        else {
            temp = p2 -> next;
            list_insert_node(list_merged, p2);
            p2 = temp;
        }
    }

    while(p1 != NULL) {
        temp = p1 -> next;
        list_insert_node(list_merged, p1);
        p1 = temp;
    }

    while(p2 != NULL) {
        temp = p2 -> next;
        list_insert_node(list_merged, p2);
        p2 = temp;
    }

    list_1 -> head = NULL;
    list_2 -> head = NULL;
}


int
main(int argc, char *argv[])
{
    int i;
    List list_1, list_2, list_merged;

    list_initialize(&list_1);
    list_initialize(&list_2);
    list_initialize(&list_merged);

    for(i = 1; i <= 10; i+=2)
        list_insert_tail(&list_1, i);

    list_print(&list_1);

    for(i = 2; i <= 10; i+=2)
        list_insert_tail(&list_2, i);

    list_print(&list_2);

    list_merge(&list_1, &list_2, &list_merged);

    list_print(&list_merged);

    list_release(&list_merged);

    return 0;
}
