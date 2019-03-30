#include <iostream>
#include <algorithm>

int main()
{

    int arr[4][4] = {
                        {1, 2, 8, 9  },
                        {2, 4, 9, 12 },
                        {4, 7, 10, 13},
                        {6, 8, 11, 15}
                    };

    int i = 0, j = 3, target = 17;
    while(i <= 3 && j >= 0) {
        if(arr[i][j] == target) {
            std::cout << "Find it in " << i << "row, " << j << "column" << std::endl;
            //break;
            goto lable;
        }
        if(arr[i][j] > target)
            j--;
        else
            i++;

    }

    std::cout << "can't find it" << std::endl;

    lable:
        ;
    return 0;
}
