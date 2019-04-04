#include <cstdio>
#include <cstdlib>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int
power(int base, int exponent)
{
    int ans = 1;
    while(exponent) {
        if((exponent & 1) != 0)
            ans *= base;
        base *= base;
        exponent >>= 1;
    }
    return ans;
}

void
solve(int n)
{
    int ub = power(10, n) - 1;
    int i;
    for(i = 1; i <= ub; ++i)
        cout << i << (i == ub ? '\n' : ' ');
}

void
solve1(int *bit, int n)
{

    int i;
    for(i = 0; i < n + 1; ++i) bit[i] = 0;
    bit[n] = -1;
    int temp;
    while(1) {
        bit[0] += 1;

        for(i = 1; i <= n; i++) {
            if(bit[i - 1] > 9) {
                bit[i] += bit[i - 1] / 10;
                bit[i - 1] = bit[i - 1] % 10;
            }
            else break;
        }

       if(bit[n] != -1)
            return;


        temp = 0;
        for(i = n - 1; i >= 0; i--) {
            if(bit[i] != 0)
                temp = 1;
            if(temp) {
                cout << bit[i];
                if(i == 0)
                    cout << endl;
            }
        } // for


    }//while

} //solve2

int
main(int argc, char *argv[])
{
    int n;

    while(cin >> n) {
        int *bit = (int *)malloc(sizeof(int) * (n + 1));
        solve1(bit, n);
        free(bit);
    }
    exit(EXIT_SUCCESS);
}
