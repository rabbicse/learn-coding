#include <iostream>
#include <vector>

using namespace std;

std::vector<int> remove_duplicate(int *arr, int length)
{
    std::vector<int> uniqueNumbers;

    /* if length 0 then return */
    if (length == 0)
        return uniqueNumbers;

    /* append first element */
    uniqueNumbers.push_back(arr[0]);

    /* if there are more elements then */
    if (length > 1)
    {
        for (int i = 1; i < length; i++)
        {
            if (arr[i - 1] != arr[i])
            {
                uniqueNumbers.push_back(arr[i]);
            }
        }
    }

    return uniqueNumbers;
}

int main()
{
    int arr[] = {1, 1, 2, 3, 3};
    int length = sizeof(arr) / sizeof(int);
    auto uniqueNumbers = remove_duplicate(arr, length);

    cout << "Unique: " << endl;
    for (size_t i = 0; i < uniqueNumbers.size(); i++)
    {
        /* code */
        cout << uniqueNumbers[i] << " ";
    }
    cout << endl;
}
