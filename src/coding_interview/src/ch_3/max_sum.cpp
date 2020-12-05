#include <iostream>

using namespace std;

int maxSum(int *arr, int length)
{
	int maxSum = INT32_MIN;
	int currentSum = 0;
	for (int i = 0; i < length; i++)
	{
		currentSum += arr[i];

		if (currentSum > maxSum)
		{
			maxSum = currentSum;
		}

		if (currentSum < 0)
		{
			currentSum = 0;
		}
	}

	return maxSum;
}
int main()
{
	int arr[] = {-1, -2, 1, 2, 3, -5, 4};
	cout << "Array: " << endl;
	for (int a : arr)
	{
		cout << a << " ";
	}
	cout << endl;

	int length = sizeof(arr) / sizeof(int);
	int sum = maxSum(arr, length);
	cout << "Maximum SUM: " << sum << endl;

	return 0;
}
