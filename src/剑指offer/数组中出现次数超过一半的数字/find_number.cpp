#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

int 
partition(int *arr, int begin, int end)
{
    if(arr == nullptr)
        return -1;
    
    int first = begin, last = end;

    int key = arr[begin];

    while(first < last) {
        while(first < last && arr[last] >= key) last--;
        arr[first] = arr[last];

        while(first < last && arr[first] <= key) first++;
        arr[last] = arr[first];
    }

    arr[first] = key;

    return first;
}

bool
check(int *arr, int length, int num) 
{
    if(arr == nullptr || length <= 0)
        return false;
    
    int count = 0;
    for(int i = 0; i < length; ++i)
        if(arr[i] == num)
            ++count;
    
    return count >= (length / 2);
}

void
find(int *arr, int length)
{
    if(arr == nullptr || length == 0) {
        cout << "array can't be null or array length must greater than 0.\n";
        return;
    }
    
    int mid = length >> 1;
    int index =partition(arr, 0, length - 1);
    int begin = 0, end = length - 1;

    while(index != mid) {
        if(index <= mid) {
            begin = index + 1;
            index = partition(arr, begin, end);        
        }
        else {
            end = index - 1;
            index = partition(arr, begin, end);
        }
    }

    int result = arr[mid];
    if(check(arr, length, result) == false) {
        cout << "can't find it..." << endl;
    }
    else {
        cout << "find it!" << endl;
    }

}

void 
find2(int *arr, int length)
{
    if(arr == nullptr || length == 0) {
        cout << "array can't be null or array length must greater than 0.\n";
        return;
    }

    int result = arr[0];
    int times = 1;
    for(int i = 1; i < length; ++i) {
        if(times == 0) {
            result = arr[i];
            times = 1;
        }
        if(result == arr[i]) 
            ++times;
        else {
            --times;
        }
    }

    if(check(arr, length, result) == false) {
        cout << "can't find it..." << endl;
    }
    else {
        cout << "find it!" << endl;
    }
}

int
main(int argc, char *argv[])
{
    int arr[] = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    find2(arr, 9);
    return 0;
}