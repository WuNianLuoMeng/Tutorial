#include <cstdio>
#include <cstdlib>
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
bst_serialize(Node *node, int *sequence, int *seq_top)
{
    if(node == nullptr) {
        sequence[(*seq_top)++] = -1;
        return;
    }

    sequence[(*seq_top)++] = node -> data;
    bst_serialize(node -> left, sequence, seq_top);
    bst_serialize(node -> right, sequence, seq_top);
}

void
bst_deserialize(Node **node, int *sequence, int *seq_top, int *node_cnt)
{
    if((*node_cnt) >= *(seq_top))
        return;
    int data = sequence[(*node_cnt)++];
    if(data != -1) {
       (*node) = (Node *)malloc(sizeof(Node));
        if((*node) == nullptr) {
            printf("malloc error\n");
            exit(1);
        }
        (*node) -> data = data;
        (*node) -> left = nullptr;
        (*node) -> right = nullptr;
        bst_deserialize(&((*node) -> left), sequence, seq_top, node_cnt);
        bst_deserialize(&((*node) -> right), sequence, seq_top, node_cnt);
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

    int *path = (int *)malloc(sizeof(int) * 100);
    int seq_top = 0, node_cnt = 0;
    bst_serialize(tree.root, path, &seq_top);

    for(int i = 0; i< seq_top; i++)
        printf("%d%c", path[i], (i == seq_top - 1) ? '\n' : ' ');

    bst_release(tree.root);

    bst_deserialize(&tree.root, path, &seq_top, &node_cnt);

    bst_pre_order(tree.root);

    bst_release(tree.root);
    free(path);
    return 0;
}