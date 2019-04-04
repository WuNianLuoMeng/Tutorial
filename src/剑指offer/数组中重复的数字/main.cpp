#include <set>
#include <iostream>

bool check1(int arr[], int length)
{
    if(arr == nullptr || length == 0) {
        return false;
    }

    for(int i = 0; i < length; i++) {
        if(arr[i] < 0 || arr[i] > length - 1) {
            return false;
        }
    }

    for(int i = 0; i <length; i++) {
        while(arr[i] != i) {
            if(arr[i] == arr[arr[i]]) {
                std::cout << arr[i];
                return true;
            }
            std::swap(arr[i], arr[arr[i]]);
        }
    }
    return false;
}

bool check2(int arr[], int length)
{
    std::set<int> st;

    if(arr == nullptr || length == 0) {
        return false;
    }

    for(int i = 0; i < length; i++) {
        if(st.find(arr[i]) == st.end()) {
            st.insert(arr[i]);
        }
        else {
            return true;
        }
    }

    return false;
}

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;

    int arr[100];
    int n;

    while(cin >> n) {
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        //check1(arr, n);
        check2(arr, n);
    }
    return 0;
}
