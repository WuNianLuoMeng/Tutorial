#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int n;
    while(cin >> n) {
        if(n == 1) {
            cout << 0 << endl;
            continue;
        }

        if(n == 2) {
            cout << 1 << endl;
            continue;
        }

        int a = 0, b = 1, c;
        for(int i = 3; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        cout << c << endl;
    }
    return 0;
}
