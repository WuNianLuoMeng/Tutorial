#include <cstdlib>
#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

const double eps = 1e-6;

/**
 *         |= a ^ (n / 2) * a ^ (n / 2)                   n % 2 == 0
 * a ^ n = |
 *         |= a ^ ((n - 1) / 2) * a ^ ((n - 1) / 2) * a   n % 2 != 0
 */

double
Power2(double base, int exponent)
{
    double ans = 1.0;

    while(exponent) {
        if(exponent & 1 != 0)
            ans *= base;
        base *= base;
        exponent >>= 1;
    }
    return ans;
}

double
Power(double x, int y)
{
    if(fabs(x - 0.0) < eps && y < 0)
        return 0.0;
    double base = x;
    int exponent = y;
    if(y < 0)
        exponent = -y;
    int i;
    double ans = Power2(base, exponent);
    if(y < 0)
        ans = 1.0 / ans;
    return ans;
}

int
main(int argc, char *argv[])
{
    cout << Power(2, 5) << endl;
    exit(EXIT_SUCCESS);
}
