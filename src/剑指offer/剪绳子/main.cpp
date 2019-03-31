#include <cstring>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int powerMod(int x, int y)
{
    int ans = 1, base = x;
    while(y) {
        if(y & 1 != 0) ans *= base;
        base *= base;
        y >>= 1;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    if(n < 2)
        cout << 0 <<endl;
    else if(n == 2)
        cout << 1 << endl;
    else if(n == 3)
        cout << 2 <<endl;
    else {
        int p3 = n / 3;
        if(n - 3 * p3 == 1)
            p3--;
        int p2 = (n - 3 * p3) / 2;
        cout << powerMod(3, p3) * powerMod(2, p2) << endl;
    }
    return 0;
}
