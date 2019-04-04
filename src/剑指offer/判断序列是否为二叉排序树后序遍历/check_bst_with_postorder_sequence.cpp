/**
 * 
 * 判断一个序列是否为二叉树的后序遍历
 */

#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

bool
check_bst_with_postorder_sequence(int *arr, int length)
{
    if(arr == nullptr || length <= 0)
        return false;
    int i, j;
    int root = arr[length - 1];
    for(i = 0; i < length - 1; ++i)
        if(root < arr[i])
            break;
    
    for(j = i; j < length - 1; ++j)
        if(root > arr[j])
            return false;
    
    bool left_son  = true;
    bool right_son = true;
    if(i > 0)
        left_son = check_bst_with_postorder_sequence(arr, i);
    
    if(i < length - 1)
        right_son = check_bst_with_postorder_sequence(arr + i, length - 1 - i);
    
    return left_son && right_son;
}

int
main(int argc, char *argv[])
{
    int sequence[] = {7, 5, 9, 6, 11, 10, 8};

    cout << "It's " 
         << (check_bst_with_postorder_sequence(sequence, 7) ? "a" : "not a")
         <<" Binary Search Tree." << endl;
    return 0;
}