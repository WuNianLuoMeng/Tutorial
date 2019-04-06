#include <queue>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int 
partition(int *arr, int begin, int end)
{
    if(arr == nullptr) 
        return -1;
    
    int first = begin, last = end;

    int key = arr[first];
    while(first < last)  {
        while(first < last && arr[last] >= key) --last;
        arr[first] = arr[last];
        while(first < last && arr[first] <= key) ++ first;
        arr[last] = arr[first];
    }
    arr[first] = key;
    return first;
}

void
find(int *arr, int length, int k)
{
    if(arr == nullptr || length == 0 || k > length) {
        cout << "I catch an exception!!!" << endl;
        return;
    }

    int begin = 0, end = length - 1;
    int index = partition(arr, begin, end);

    while(index != k - 1) {
        if(index <= k - 1) {
            begin = index + 1;
            index = partition(arr, begin, end);
        }
        else {
            end = index - 1;
            index = partition(arr, begin, end);
        }
    }

    for(int i = 0; i < k; ++i)
        cout << arr[i] << (i == k - 1 ? '\n' : ' ');
}

void
find2(int *arr, int length, int k)
{
    if(arr == nullptr || length == 0 || k > length) {
        cout << "I catch an exception!!!" << endl;
        return;
    }

    std::priority_queue<int> Q;

    for(int i = 0; i < k; ++i)
        Q.push(arr[i]);
    
    for(int i = k; i < length; ++i) {
        if(arr[i] < Q.top()) {
            Q.pop();
            Q.push(arr[i]);
        }
    }

    while(!Q.empty()) {
        cout << Q.top() << ' ';
        Q.pop();
    }
    cout << endl;
}

int
main(int argc, char *argv[])
{
    int arr[] = {5, 6, 7, 3, 4, 9, 10, 2, 1, 8};
    find2(arr, 10, 8);
    return 0;
}