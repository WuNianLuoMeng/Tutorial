#include <stack>
#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::stack;

bool
check(int *in, int *out, int length)
{
    int i, j;
    i = 0;
    j = 0;
    stack<int> st;
    while(i < length || j < length) {
        if(i < length && (st.empty() || st.top() != out[j]))
            st.push(in[i++]);
        else if(st.top() == out[j]) {
            st.pop();
            j++;
        }
        else 
            break;
    }

    return i >= length && j >=length;
}

int
main(int argc, char *argv[])
{
    int in[]  = {1, 2, 3, 4, 5};
    int out[] = {4, 5, 3, 2, 1};

    cout << (check(in, out, 5) ? "True" : "False") << endl;
    return 0;
}