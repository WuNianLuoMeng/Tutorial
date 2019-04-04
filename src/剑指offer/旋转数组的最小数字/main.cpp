#include <iostream>
#include <algorithm>

int slove(int arr[], int length)
{
    int p1 = 0, p2 = length - 1;
    int mid = p1;
    while(arr[p1] >= arr[p2]) {
        if(p2 - p1 == 1) {
            mid = p2;
            break;
        }

        mid = (p1 + p2) / 2;

        if(arr[mid] == arr[p1] && arr[mid] == arr[p2]) {
            int temp = arr[p1], pos = p1;
            for(int i = p1; i <= p2; i++) {
                if(temp > arr[i]) {
                    temp = arr[i];
                    pos = i;
                }
            }
            return pos;
        }

        if(arr[mid] >= arr[p1])
            p1 = mid;
        else if(arr[mid] <= arr[p2])
            p2 = mid;
    }
    return mid;
}

int main()
{
    int arr[] = {2, 3, 4, 5, 1};
    std::cout << slove(arr, 5) << std::endl;
    return 0;
}
