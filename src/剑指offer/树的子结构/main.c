#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *left;
    struct Node *right;
    int data;
};

struct Tree
{
    struct Node *root;
};

typedef struct Node Node;
typedef struct Tree Tree;

void
tree_initialize(Tree *tree)
{
    if(tree == NULL)
        return;
    tree -> root = NULL;
}

void
tree_insert(Tree *tree, int data)
{
    if(tree == NULL)
        return;

    Node *node = (Node *)malloc(sizeof(Node));
    Node *ptr, pos;
    if(node == NULL) {
        printf("malloc error\n");
        return;
    }

    node -> left = NULL;
    node -> right = NULL;
    node -> data = data;

    ptr = tree -> root;
    pos = ptr;

    while(ptr != NULL) {
        pos = ptr;
        if(ptr -> data > data)
            ptr = ptr -> left;
        else
            ptr = ptr -> right;
    }

    if(pos != NULL) {
        if(pos -> data < data)
            pos -> right = node;
        else
            pos -> left = node;
    }
}

void
tree_release(Node *node)
{
    if(tree == NULL)
        return;

    tree_release(node -> left);
    tree_release(node -> right);
    free(node);
}

void
has_subtree2(Node *bigtree, Node *smalltree)
{
    if(smalltree == NULL)
        return 1;
    if(bigtree == NULL)
        return 0;

    if(bigtree -> data != smalltree -> data)
        return 0;
    return has_subtree2(bigtree -> left, smalltree -> left) &&
           has_subtree(bigtree -> right, bigtree -> right);
}

int
has_subtree(Node *root1, Node *root2)
{
    int result = 0;

    if(root1 != NULL && root2 != NULL) {
        if(root1 -> data == root2 -> data)
            return has_subtree2(root1, root2);
        if(result == 0)
            result = has_subtree(root -> left, root2);
        if(result == 0)
            result = has_subtree(root -> right, root2);

    }

    return result;
}

int
main(int argc, char *argv[])
{

    return 0;
}
