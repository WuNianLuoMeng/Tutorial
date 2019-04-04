#include <stack>
#include <queue>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::stack;
using std::queue;

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

/**
 * 
 * 层序遍历
 */
void
bst_level_order(BST *tree)
{
    if(tree == nullptr)
        return;
    queue<Node *> Q;

    Node *root = tree -> root;
    if(root == nullptr)
        return;
    Q.push(root);

    while(!Q.empty()) {
        Node *now = Q.front();
        Q.pop();
        printf("%d ", now -> val);
        if(now -> left != nullptr)
            Q.push(now -> left);

        if(now -> right != nullptr)
            Q.push(now -> right);
    } 
    printf("\n");
}

/**
 * 
 * 分层打印二叉树
 */
void
bst_level_order2(BST *tree)
{
    if(tree == nullptr)
        return;
    queue<Node *> Q;

    Node *root = tree -> root;
    if(root == nullptr)
        return;
    Q.push(root);
    int to_be_print = 1;
    int next_level = 0;
    while(!Q.empty()) {
        Node *now = Q.front();
        Q.pop();
        printf("%d ", now -> val);
        --to_be_print;
        if(now -> left != nullptr) {
            Q.push(now -> left);
            ++next_level;
        }
            
        if(now -> right != nullptr) {
            Q.push(now -> right);
            ++next_level;
        }
        if(to_be_print == 0) {
            to_be_print = next_level;
            next_level = 0;
            printf("\n");
        }
            
    } 
    printf("\n");
}

/**
 * 之字形打印二叉树
 */
void
bst_level_order3(BST *tree)
{
    if(tree == nullptr)
        return;
    stack<Node *> odd;
    stack<Node *> even;
    Node *root = tree -> root;
    if(root == nullptr)
        return;
    odd.push(root);
    int to_be_print = 1;
    int next_level = 0;
    int level = 1;
    while(!odd.empty() || !even.empty()) {
        Node *now;
        to_be_print--;
        if(level & 1) {
            now = odd.top();
            odd.pop();
            printf("%d ", now -> val);
            if(now -> left != nullptr) {
                even.push(now -> left);
                next_level++;
            }
                
            if(now -> right != nullptr) {
                even.push(now -> right);
                next_level++;
            }
            
            if(to_be_print == 0) {
                to_be_print = next_level;
                next_level = 0;
                if(odd.empty())
                    printf("\n");
                level++;
            }
            
        }
        else {
            now = even.top();
            even.pop();
            printf("%d ", now -> val);
            if(now -> right != nullptr) {
                odd.push(now -> right);
                next_level++;
            }
                
            if(now -> left != nullptr) {
                odd.push(now -> left);
                next_level++;
            }
            
            if(to_be_print == 0) {
                to_be_print = next_level;
                next_level = 0;
                if(even.empty())
                    printf("\n");
                level++;
            }

        }
    }
    printf("\n");
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
    
    bst_level_order3(&tree);

    bst_release(tree.root);
    return 0;
}