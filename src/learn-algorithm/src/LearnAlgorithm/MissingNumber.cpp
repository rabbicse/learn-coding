/*
https://www.geeksforgeeks.org/find-the-missing-number/
Find the Missing Number
You are given a list of n-1 integers and these integers are in the range of 1 to n. There are no duplicates in the list. One of the integers is missing in the list. Write an efficient code to find the missing integer.

Example :

Input: arr[] = {1, 2, 4,, 6, 3, 7, 8}
Output: 5

Input: arr[] = {1, 2, 3, 5}
Output: 4
*/

#include <iostream>

using namespace std;

int getMissingNo(int arr[], int n)
{
	int x1 = arr[0];
	/* XOR all array elements with x1 */
	for (int i = 1; i < n; i++)
	{
		/* XOR x1 with all array elements */
		x1 = x1 ^ arr[i];
	}


	int x2 = 1;
	/* XOR all elements from 1 - n+1*/
	for (int i = 2; i <= n + 1; i++)
	{
		/* code */
		x2 = x2 ^ i;
	}

	return x1 ^ x2;

}

int main()
{
	int arr[] = { 1, 2, 3, 5 };
	int missingNo = getMissingNo(arr, sizeof(arr) / sizeof(arr[0]));
	cout << "Missing No: " << missingNo << endl;
	return 0;
}