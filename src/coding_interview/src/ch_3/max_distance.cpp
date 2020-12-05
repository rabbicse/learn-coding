#include <iostream>
#include <vector>
#include <tuple>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int maxDistance(int *arr, int length)
{
    int maxDistance = 0;

    std::vector<tuple<int, int>> numbers;
    for (int i = 0; i < length; i++)
    {
        numbers.push_back(tuple<int, int>(arr[i], i));
    }

    sort(numbers.begin(), numbers.end());

    tuple<int, int> minNum(numbers[0]);
    for (tuple<int, int> n : numbers)
    {
        if (get<1>(n) <= get<1>(minNum))
        {
            minNum = n;
        }
        else
        {
            maxDistance = max(maxDistance, get<1>(n) - get<1>(minNum));
        }
    }

    return maxDistance;
}

int main()
{
    int arr[] = {3, 5, 4, 2};
    cout << "Array: ";
    for (int a : arr)
    {
        cout << a << " ";
    }
    cout << endl;
    int length = sizeof(arr) / sizeof(int);

    int md = maxDistance(arr, length);
    cout << "Maximum distance: " << md << endl;
    return 0;
}
