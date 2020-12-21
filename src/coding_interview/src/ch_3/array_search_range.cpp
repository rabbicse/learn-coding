#include <iostream>
#include <tuple>
using namespace std;

int leftMostBinarySearh(int *array, int key, int left, int right)
{
	int position = -1;

	while (left < right)
	{
		if (key == array[left])
		{
			position = left;
			break;
		}

		int mid = (left + right) / 2;

		if (key == array[mid])
		{
			if (key != array[mid - 1] || mid == left)
			{
				position = mid;
				break;
			}
			right = mid;
		}
		else if (key < array[mid])
		{
			right = mid - 1;
		}
		else if (key > array[mid])
		{
			left = mid + 1;
		}
	}

	return position;
}

int rightMostBinarySearh(int *array, int key, int left, int right)
{
	int position = -1;

	while (left < right)
	{
		if (key == array[right])
		{
			position = right;
			break;
		}

		int mid = (left + right) / 2;

		if (key == array[mid])
		{
			if (key != array[mid + 1] || mid == right)
			{
				position = mid;
				break;
			}
			right = mid;
		}
		else if (key < array[mid])
		{
			right = mid - 1;
		}
		else if (key > array[mid])
		{
			left = mid + 1;
		}
	}

	return position;
}

tuple<int, int> binarySearch(int *array, int length, int key)
{
	int left = 0;
	int right = length - 1;
	int start = leftMostBinarySearh(array, key, left, right);

	if (start == -1)
	{
		return { -1, -1 };
	}

	int end = rightMostBinarySearh(array, key, start, right);

	return {start, end};
}

int main()
{
	int array[] = {1, 2, 4, 4, 4, 4, 4, 5, 7, 7};
	int len = sizeof(array) / sizeof(array[0]);

	int k = 4;

	tuple<int, int> result = binarySearch(array, len, k);
	cout << "Start = " << get<0>(result) << " End = " << get<1>(result) << endl;

	return 0;
}
