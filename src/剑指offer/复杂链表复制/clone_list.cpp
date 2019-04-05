#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

struct Node
{
    struct Node *next;
    struct Node *sibling;
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
    if(list == nullptr)
        return;
    list -> head = nullptr;
}

void
list_insert_tail(List *list, int data)
{
    if(list == nullptr)
        return;
    
    Node *node = (Node *)malloc(sizeof(Node));
    if(node == nullptr) {
        printf("malloc error\n");
        return;
    }

    node -> data = data;
    node -> next = nullptr;
    node -> sibling = nullptr;

    if(list -> head == nullptr) {
        list -> head = node;
        return;
    }

    Node *ptr = list -> head;

    while(ptr -> next != nullptr) 
        ptr = ptr -> next;
    
    ptr -> next = node;
}

void
list_release(List *list)
{
    if(list == nullptr)
        return;
    
    if(list -> head == nullptr)
        return;

    Node *ptr = list -> head;
    Node *temp;
    while(ptr != nullptr) {
        temp = ptr;
        ptr = ptr -> next;
        free(temp);
    }
}

void
list_print(List *list)
{
    if(list == nullptr)
        return;
    
    if(list -> head == nullptr)
        return;
    
    Node *ptr = list -> head;
    
    printf("List: \n");
    while(ptr != nullptr) {
        printf("%d\n", ptr -> data);
        ptr = ptr -> next;
    }
}

void 
copy_list(List *list, List *new_list)
{
    if(list == nullptr || list -> head == nullptr)
        return;
    
    if(new_list == nullptr) 
        return;
    
    Node *ptr = list -> head;

    while(ptr != nullptr) {
        Node *node = (Node *)malloc(sizeof(Node));
        if(node == nullptr) {
            printf("malloc error");
            return;
        }
        node -> data = ptr -> data;
        node -> next = ptr -> next;
        ptr -> next = node;
        ptr = node -> next;
    }

    ptr = list -> head;
    Node *copy_node = ptr -> next;

    while(ptr != nullptr) {
        copy_node -> sibling = ptr -> sibling;
        ptr = copy_node -> next;
        if(ptr != nullptr)
            copy_node = ptr -> next;
        else 
            break;
    }
    
    ptr = list -> head;
    new_list -> head = ptr -> next;
    Node *q = new_list -> head;
    while(q != nullptr) {
        ptr -> next = q -> next;
        ptr = ptr -> next;
        if(ptr == nullptr)
            break;
        q -> next = ptr -> next;
        q = q -> next;

    }
    //ptr -> next = nullptr;
    //q -> next = nullptr;
    

}

int
main(int argc, char *argv[])
{
    List list, l2;
    list_initialize(&list);
    list_initialize(&l2);

    int i;
    for(i = 0; i < 4; ++i)
        list_insert_tail(&list, i);
    
    //list_print(&list);
    copy_list(&list, &l2);
    list_print(&l2);
    //list_print(&list);
    list_release(&list);
    list_release(&l2);
    return 0;
}