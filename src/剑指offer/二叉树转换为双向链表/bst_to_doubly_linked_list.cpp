#include <cstdio>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

struct Node
{
    struct Node *left;
    struct Node *right;
    int data;
};

struct bst
{
    struct Node *root;
};

typedef struct Node Node;
typedef struct bst bst;

void
bst_initialize(bst *tree)
{
    if(tree == nullptr) 
        return;
    tree -> root = nullptr;
}

void
bst_insert(bst * tree, int data)
{
    if(tree == nullptr)
        return;
    
    Node *node = (Node *)malloc(sizeof(Node));

    if(node == nullptr) {
        printf("malloc error\n");
        return;
    }

    node -> left  = nullptr;
    node -> right = nullptr;
    node -> data  = data;

    if(tree -> root == nullptr) {
        tree -> root = node;
        return;
    }

    Node *parent;
    Node *now = tree -> root;
    while(now != nullptr) {
        parent = now;

        if(now -> data > data)
            now = now -> left;
        else 
            now = now -> right;
    }

    if(parent != nullptr) {
        if(parent -> data > data)
            parent -> left = node;
        else 
            parent -> right = node;
    }
}

void
bst_release(Node *node)
{
    if(node == nullptr)
        return;
    
    bst_release(node -> left);
    bst_release(node -> right);

    free(node);
}

void
bst_pre_order(Node *node)
{
    if(node == nullptr)
        return;
    
    printf("%d\n", node -> data);
    bst_pre_order(node -> left);
    bst_pre_order(node -> right);
}

void
__change(Node *now, Node **last)
{
    if(now == nullptr)
        return;

    if(now -> left != nullptr)
        __change(now -> left, last);
    
    now -> left = *last;

    if(*last != nullptr)
        (*last) -> right = now;
    
    *last = now;

    if(now -> right != nullptr)
        __change(now -> right, last);

}

Node *
bst_to_doubly_linked_list(bst *tree)
{
    if(tree == nullptr)
        return nullptr;
    
    Node *last = nullptr;

    __change(tree -> root, &last);

    Node *head = last;

    while(head != nullptr && head -> left != nullptr)
        head = head -> left;
    
    return head;
}

void
print_list(Node *node)
{
    while(node != nullptr) {
        Node *temp = node;
        node = node -> right;
        printf("%d\n", temp -> data);
        free(temp);
    }
}

int
main(int argc, char *argv[])
{
    bst tree;

    bst_initialize(&tree);

    bst_insert(&tree, 8);
    bst_insert(&tree, 4);
    bst_insert(&tree, 12);
    bst_insert(&tree, 2);
    bst_insert(&tree, 6);
    bst_insert(&tree, 10);
    bst_insert(&tree, 14);
    bst_insert(&tree, 1);
    bst_insert(&tree, 3);
    bst_insert(&tree, 5);
    bst_insert(&tree, 7);
    bst_insert(&tree, 9);
    bst_insert(&tree, 11);
    bst_insert(&tree, 13);
    bst_insert(&tree, 15);

    //bst_pre_order(tree.root);

    Node *head = bst_to_doubly_linked_list(&tree);

    print_list(head);

    //bst_release(tree.root);
    return 0;
}