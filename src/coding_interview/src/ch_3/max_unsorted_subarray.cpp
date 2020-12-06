#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int *maxUnsortedSubarray(int *arr, int length)
{
    int start = -1;
    for (int i = 0; i < length - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            start = i;
            break;
        }
    }

    int end = -1;
    for (int i = length - 1; i > start; i--)
    {
        if (arr[i] < arr[start] || arr[i] < arr[i - 1])
        {
            end = i;
            break;
        }
    }

    int min = arr[start];
    int max = arr[end];

    for (int i = 0; i < start; i++)
    {
        if (arr[i] < min)
        {
            start = i;
            break;
        }
    }

    for (int i = length - 1; i > end; i--)
    {
        if (arr[i] < max)
        {
            end = i;
            break;
        }
    }

    static int result[] = {start, end};
    return result;
}

int main()
{
    // int arr[] = {1, 3, 2, 4, 5};
    // int arr[] = {1, 4, 2, 3, 5};
    // int arr[] = {3, 2, 1};
    int arr[] = {5, 6, 1, 2, 4, 7};
    int length = sizeof(arr) / sizeof(int);
    int *ret = maxUnsortedSubarray(arr, length);
    cout << ret[0] << " - " << ret[1] << endl;
    return 0;
}