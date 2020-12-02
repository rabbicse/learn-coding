#include <iostream>
#include <vector>

using namespace std;

/* Regular solution */
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

/* Optimized solution */
int remove_duplicates(int *arr, int length)
{
    /* if length 0 then return */
    if (length == 0)
        return 0;

    int lastIndex = 0;
    /* if there are more elements then */
    if (length > 1)
    {
        for (int i = 1; i < length; i++)
        {
            if (arr[i - 1] != arr[i])
            {                           
                lastIndex++;     
                arr[lastIndex] = arr[i];                
            }            
        }
    }

    return lastIndex;
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


    int lastIndex = remove_duplicates(arr, length);

    cout << endl << "Unique: " << endl;
    for (int i = 0; i <= lastIndex; i++)
    {
        /* code */
        cout << arr[i] << " ";
    }
    cout << endl;
}
