#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int n;
    cin >> n;

    int cnt = 0;
    for(int i = 0; i < 32; i++) {
        if((n & (1 << i)))
            cnt++;
    }

    cout << cnt <<endl;
    return 0;
}
