#include <iostream>
using namespace std;

int binary_search(int *array, int len, int key)
{
    int left = 0;
    int right = len - 1;
    int mid;
    int position = -1;

    while (left < right)
    {
        /* code */
        if (key == array[left])
        {
            position = left;
            break;
        }

        if (key > array[right])
        {
            position = right + 1;
        }

        mid = left + (right - left) / 2;

        if (key == array[mid])
        {
            if (mid == left || array[mid - 1] != key)
            {
                position = mid;
            }
            right = mid;
        }
        else if (key < array[mid])
        {
            /* if key is missing then key should be at mid position */
            if (mid > left && key > array[mid - 1])
            {
                position = mid;
                break;
            }
            right = mid - 1;
        }
        else if (key > array[mid])
        {
            if (mid < right && key < array[mid + 1])
            {
                position = mid + 1;
                break;
            }
            left = mid + 1;
        }
    }

    return position;
}

int main()
{
    int array[] = {1, 2, 4, 4, 4, 5, 7, 7};
    int len = sizeof(array) / sizeof(array[0]);
    int key = 4;

    int position = binary_search(array, len, key);
    cout << "Position: " << position << endl;
    return 0;
}
