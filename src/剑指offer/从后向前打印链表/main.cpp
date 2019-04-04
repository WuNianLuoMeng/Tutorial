#include <iostream>

class List;

class Node
{
private:
    int data;
    Node *next;
public:
    Node() = default;
    ~Node() = default;
    friend class List;
};

class List
{
private:
    Node *head;
    int cnt;
    void print(Node *node);
public:
    List();
    ~List();
    void insert(int data);
    void print();
};

List::List()
{
    head = NULL;
    cnt = 0;
}

List::~List()
{
    Node *temp;
    while(head != NULL) {
        temp = head;
        head = head -> next;
        delete temp;
    }
}

void List::insert(int data)
{
    Node *newNode = new Node;
    newNode -> data = data;
    newNode -> next = NULL;
    if(head == NULL) {
        head = newNode;
        return;
    }
    Node *p = head;
    while(p) {
        if(p -> next == NULL) {
            p -> next = newNode;
            break;
        }
        p = p -> next;
    }
}

void List::print(Node *node)
{
    if(node == NULL)
        return;
    print(node -> next);
    std::cout << node -> data << std::endl;
}

void List::print()
{
    print(head);
}


int main()
{
    List li;
    for(int i = 0; i < 10; i++)
        li.insert(i);
    li.print();
    return 0;
}
