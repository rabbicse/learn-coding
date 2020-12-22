#include <iostream>

using namespace std;

int rotatedArraySearch(int *array, int length, int key)
{
	int position = -1;
	int left = 0, right = length - 1;

	while (left < right)
	{
		if (key == array[left])
		{
			position = left;
			break;
		}

		if (key == array[right])
		{
			position = right;
			break;
		}

		int mid = (left + right) / 2;

		if (key == array[mid])
		{
			position = mid;
			break;
		}

		/* if left < key < mid*/
		if (key < array[mid] && key > array[left] && array[left] < array[mid])
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
		
	}

	return position;
}

int main()
{
	int array[] = {4, 6, 7, 8, 1, 2, 3};
	int len = sizeof(array) / sizeof(array[0]);
	int key = 8;
	int position = rotatedArraySearch(array, len, key);
	cout << "Position: " << position << endl;
	return 0;
}
