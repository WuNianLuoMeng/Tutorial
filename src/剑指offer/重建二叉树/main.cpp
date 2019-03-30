#include <stdio.h>

struct Node
{
    struct Node *left;
    struct Node *right;
    char ch;
};

typedef struct Node Node;

Node *rebuild_1(const char *pre, const char *in, int length)
{
    if(length <= 0)
        return nullptr;

    Node *node = new Node();
    node -> left = nullptr;
    node -> right = nullptr;
    node -> ch = *pre;

    int pos = 0;
    for(int i = 0; i < length; ++i, ++pos)
        if(*(in + i) == *pre)
            break;

    node -> left = rebuild_1(pre + 1, in, pos);
    node -> right = rebuild_1(pre + pos + 1, in + pos + 1, length - pos - 1);
    return node;
}

Node *rebuild_2(const char *post, const char *in, int length)
{
    if(length <= 0)
        return nullptr;

    Node *node = new Node();

    node -> left = nullptr;
    node -> right = nullptr;
    node -> ch = *(post + length - 1);

    int pos = 0;
    for(int i = 0; i < length; i++, pos++)
        if(in[i] == node -> ch)
            break;

    node -> left = rebuild_2(post, in, pos);
    node -> right = rebuild_2(post + pos, in + pos + 1, length - pos - 1);
    return node;
}

void postOrder(Node *node)
{
    if(node == nullptr)
        return;

    postOrder(node -> left);
    postOrder(node -> right);

    printf("%c", node -> ch);
    delete node;
}

void preOrder(Node *node)
{
    if(node == nullptr)
        return;

    Node *right = node -> right;
    Node *left  = node -> left;

    printf("%c", node -> ch);

    preOrder(left);
    preOrder(right);
}

int main()
{
    const char *pre = "ABCDEF";
    const char *in  = "CBAEDF";
    const char *pos = "74258631";

    Node *root = rebuild_1(pre, in, 6);
    postOrder(root);
    printf("\n");
    //root = rebuild_2(pos, in, 8);
    //preOrder(root);
    //printf("\n");
    return 0;
}
