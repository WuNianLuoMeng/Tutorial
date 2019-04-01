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
print_list(List *list)
{
    if(list == NULL)
        return;
    Node *p = list -> head;
    printf("print list:\n");
    while(p != NULL) {
        printf("%d %p\n", p -> data, p);
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

void
delete_duplicate(List *list)
{
    if(list == NULL)
        return;
    Node *now, *p, *temp;

    p = list -> head;

    if(p == NULL)
        return;
    now = p -> next;

    while(now != NULL) {
        if(now -> data == p -> data) {
            temp = now;
            now = now -> next;
            p -> next = now; // 注意：容易忽略的地方。
            free(temp);
            continue;
        }
        p = now;
        now = now -> next;
    }

}


int
main(int argc, char *argv[])
{
    List list;
    list_initialize(&list);

    insert_to_tail(&list, 0);
    insert_to_tail(&list, 1);
    insert_to_tail(&list, 2);
    insert_to_tail(&list, 2);
    insert_to_tail(&list, 3);
    insert_to_tail(&list, 3);
    insert_to_tail(&list, 4);
    insert_to_tail(&list, 4);

    print_list(&list);

    delete_duplicate(&list);

    print_list(&list);

    release_list(&list);
    exit(EXIT_SUCCESS);
}
