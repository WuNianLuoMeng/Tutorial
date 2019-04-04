#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::swap;

void
array_partition(int *arr, int length, bool (*func)(int *))
{
    if(arr == NULL)
        return;

    int first = 0, last = length - 1;

    while(first < last) {
        while(first < last && !func(&arr[first])) first++;
        while(first < last && func(&arr[last])) last--;
        swap(arr[first], arr[last]);
    }
}

bool check(int *a)
{
    return *a % 2 == 0;
}

int
main(int argc, char *argv[])
{
    int n;
    int arr[100];
    cin >> n;
    for(int i = 0; i < n; i++) cin >>arr[i];
    array_partition(arr, n, check);

    for(int i = 0; i < n; i++)
        cout << arr[i] << (i == n - 1 ? '\n' : ' ');
    return 0;
}
