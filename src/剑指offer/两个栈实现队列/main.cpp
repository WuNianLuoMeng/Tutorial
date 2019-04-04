#include <stack>
#include <iostream>

using std::stack;
using std::cin;
using std::cout;
using std::endl;

class MyQueue
{
private:
    stack<int> head;
    stack<int> tail;
public:
    MyQueue() = default;
    ~MyQueue() = default;
    void push(int data);
    void pop();
    int top();
    bool empty();
    void print();
};

void MyQueue::push(int data)
{
    tail.push(data);
}

void MyQueue::pop()
{
    if(!head.empty()) {
        head.pop();
        return;
    }

    while(!tail.empty()) {
        head.push(tail.top());
        tail.pop();
    }
}

int MyQueue::top()
{
    if(!head.empty()) {
        return head.top();
    }

    while(!tail.empty()) {
        head.push(tail.top());
        tail.pop();
    }
    return head.top();
}

bool MyQueue::empty()
{
    return head.empty() && tail.empty();
}

void MyQueue::print()
{
    stack<int> a = head;
    stack<int> b = tail;
    cout << "Head: ";
    while(!a.empty()) {
        std::cout << a.top() << " ";
        a.pop();
    }
    cout << endl;
    cout << "Tail: ";
    while(!b.empty()) {
        cout << b.top() << " ";
        b.pop();
    }
    cout << endl;
}

int main()
{
    MyQueue mq;
    for(int i = 0; i < 10; i++)
        mq.push(i);

    mq.print();
    while(!mq.empty()) {
        std::cout << mq.top() << std::endl;
        //mq.print();
        mq.pop();
    }
    return 0;
}
