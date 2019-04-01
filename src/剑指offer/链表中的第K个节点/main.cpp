#include <cstdio>
#include <cstdlib>

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

Node *find_last_Kth(List *list, int k)
{
    if(list == NULL && k == 0)
        return NULL;

    Node *p = list -> head;
    Node *q = list -> head;

    for(int i = 0; i < k; i++) {
        p = p -> next;
        if(p == NULL) {
            printf("K is too large and list is too shout\n");
            return NULL;
        }
    }

    while(p != NULL) {
        p = p -> next;
        q = q -> next;
    }
    return q;
}

int
main(int argc, char *argv[])
{
    List list;
    list_initialize(&list);

    for(int i = 0; i < 20; i++) {
        insert_to_tail(&list, i);
    }

    print_list(&list);

    Node *result = find_last_Kth(&list, 76);

    if(result != NULL)
        printf("Result: %d\n", result -> data);
    else
        printf("main.cpp said that he Cant't find it :)\n");

    release_list(&list);

    return 0;
}
