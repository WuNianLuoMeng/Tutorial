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

typedef struct Node Node;
typedef struct List List;

void
list_initialize(List *list)
{
    if(list == NULL)
        return;
    list -> head = NULL;
}

void
insert_to_tail(List *list, int data)
{
    if(list == NULL)
        return;

    Node *node = (Node *)malloc(sizeof(Node));
    if(node == NULL) {
        printf("malloc error");
        return;
    }

    node -> next = NULL;
    node -> data = data;

    if(list -> head == NULL) {
        list -> head = node;
        return;
    }

    Node *p = list -> head;

    while(p -> next != NULL)
        p = p -> next;
    p -> next = node;
}

void
delete_node(Node *node)
{
    if(node == NULL)
        return;
    if(node -> next == NULL) {
        free(node);
        return;
    }

    Node *p = node -> next;
    node -> data = p -> data;
    node -> next = p -> next;
    free(p);
}

void
print_list(List *list)
{
    if(list == NULL)
        return;
    Node *p = list -> head;
    printf("print list:\n");
    while(p != NULL) {
        printf("%d\n", p -> data);
        p = p -> next;
    }
}

void
release_list(List *list)
{
    if(list == NULL)
        return;

    Node *p = list -> head;
    Node *temp;
    while(p != NULL) {
        temp = p;
        p = p -> next;
        free(temp);
    }
}

int
main(int argc, char *argv[])
{
    List list;
    list_initialize(&list);

    int i;
    for(i = 0; i < 10; i++) insert_to_tail(&list, i);

    print_list(&list);

    Node *p = list.head -> next -> next;
    delete_node(p);

    print_list(&list);

    release_list(&list);

    exit(EXIT_SUCCESS);
}
