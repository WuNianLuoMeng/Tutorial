#include <stack>
#include <ctime>
#include <iostream>

using std::cout;
using std::endl;
using std::stack;

class my_stack
{
private:
    stack<int> sta;
    stack<int> aux;
public:
    my_stack() = default;
    void push(int data);
    void pop();
    int min();
};

void 
my_stack::push(int data)
{
    sta.push(data);

    if(aux.empty() || data < aux.top())
        aux.push(data);
    else 
        aux.push(aux.top());
    
}
void
my_stack::pop()
{
    sta.pop();
    aux.pop();
}
int
my_stack::min()
{
    return aux.top();
}

int
main(int argc, char *argv[])
{
    my_stack st;
    
    srand(47);
    for(int i = 10; i >= 0; i--) {
        st.push(rand());
    }
    cout << st.min() << endl;
    return 0;
}