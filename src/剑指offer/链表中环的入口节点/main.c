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

Node *
list_meet(List *list)
{
    if(list == NULL)
        return NULL;
    Node *fast, *slow;

    fast = list -> head;
    if(fast == NULL)
        return NULL;

    slow = fast -> next;
    if(slow == NULL)
        return NULL;

    fast = slow -> next;

    while(fast != NULL && slow != NULL) {
        if(fast == slow)
            return fast;
        slow = slow -> next;

        fast = fast -> next;

        if(fast != NULL)
            fast = fast -> next;
    }

    return NULL;
}

Node *
list_loop_entry(List *list)
{
    if(list == NULL)
        return NULL;

    Node *meet, *ptr, *q;
    int loop_nodes_count = 0, i;

    meet = list_meet(list);
    ptr = meet;

    //count the number of nodes in the loop
    while(ptr -> next != meet) {
        ++loop_nodes_count;
        ptr = ptr -> next;
    }

    ptr = list -> head;
    for(i = 0; i <= loop_nodes_count; ++i)
        ptr = ptr -> next;

    q = list -> head;

    while(ptr != q) {
        ptr = ptr -> next;
        q = q -> next;
    }

    return ptr;
}

int
main(int argc, char *argv[])
{
    int i;
    List list;
    list_initialize(&list);

    for(i = 0; i < 10; i++)
        list_insert_tail(&list, i);

    //list_print(&list);

    Node *p = list.head;
    while(p -> next != NULL)
        p = p -> next;

    p -> next = list.head -> next -> next;

    Node *entry = list_loop_entry(&list);
    if(entry != NULL)
        printf("Entry: %d\n", entry -> data);
    else
        printf("failed\n");

    p -> next = NULL;

    list_release(&list);

    return 0;
}
