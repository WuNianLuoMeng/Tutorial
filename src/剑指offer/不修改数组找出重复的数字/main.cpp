#include <set>
#include <iostream>
#include <algorithm>

void slove(int arr[], int length)
{
    if(arr == nullptr || length <= 0) {
        return;
    }

    std::set<int> st;
    for(int i = 0; i < length; i++) {
        if(st.find(arr[i]) == st.end()) {
            st.insert(arr[i]);
        }
        else {
            std::cout << arr[i] << std::endl;
        }
    }

}

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;

    int n;
    int arr[100];
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    slove(arr, n);


    return 0;
}
