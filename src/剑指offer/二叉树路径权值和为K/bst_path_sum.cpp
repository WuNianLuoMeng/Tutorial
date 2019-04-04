/**
 * 
 * 输出路径权值和为K的全部路径。
 */
#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

struct Node
{
    struct Node *left;
    struct Node *right;
    int val;
};

struct BST
{
    struct Node *root;
};

typedef struct Node Node;
typedef struct BST  BST;

#define MAXSIZE 100


void
bst_init(BST * tree)
{
    if(tree == nullptr) 
        return;
    tree -> root = nullptr;
}

void
bst_insert(BST *tree, int val)
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
    node ->val    = val; 

    if(tree -> root == nullptr) {
        tree -> root = node;
        return;
    }
    Node *ptr = tree -> root;
    Node *qtr = ptr;
    while(ptr != nullptr) {
        qtr = ptr;
        if(ptr -> val > val)
            ptr = ptr -> left;
        else 
            ptr = ptr -> right;
    }

    if(qtr != nullptr) {
        if(qtr -> val > val)
            qtr -> left = node;
        else
            qtr -> right = node;
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
__find(Node *node, int *path, int k, int *path_ptr, int sum, int *path_cnt)
{
    if(node == nullptr)
        return;
    if(path == nullptr)
        return;

    if(sum == k) {
        int i;
        printf("Path %d: ", ++(*path_cnt));
        for(i = 0; i < *path_ptr; ++i)
            printf("%d%c", path[i], (i == *path_ptr - 1 ? '\n' : ' '));
    }
    
    if(node -> left != nullptr) {
        path[(*path_ptr)++] = node -> left -> val;
        __find(node -> left, path, k, path_ptr, sum + node -> left -> val, path_cnt);
        (*path_ptr)--;
    }
        
    if(node -> right != nullptr) {
        path[(*path_ptr)++] = node -> right -> val;
        __find(node -> right, path, k, path_ptr, sum + node -> right -> val, path_cnt);
        (*path_ptr)--;
    }
        

    
    
}

void
find_path(BST *tree, int k)
{
    if(tree == nullptr || tree -> root == nullptr)
        return;
    int *path = (int *)malloc(sizeof(int) * MAXSIZE);

    if(path == nullptr)
        return;

    int i;
    for(i = 0; i < MAXSIZE; ++i) path[i] = -1;
    int path_ptr = 0;
    int path_cnt = 0;
    path[path_ptr++] = tree -> root -> val;
    __find(tree -> root, path, k, &path_ptr, tree -> root -> val, &path_cnt);

    free(path);
}

int
main(int argc, char *argv[])
{
    BST tree;
    bst_init(&tree);

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

    find_path(&tree, 23);

    bst_release(tree.root);

    return 0;
}