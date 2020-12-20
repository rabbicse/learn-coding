#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// Driver function to sort the 2D vector
// on basis of a particular column
bool sortcol(const vector<int> &v1,
			 const vector<int> &v2)
{
	return v1[1] < v2[1];
}

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> arr, int rows)
{
	vector<vector<int>> intervals;
	int start = arr[0][0];
	int end = arr[0][1];

	intervals.push_back(vector<int>{start, end});
	for (int i = 1; i < rows; i++)
	{
		if (arr[i][0] > end)
		{
			intervals.push_back({arr[i][0], arr[i][1]});
		}
		else if (arr[i][1] > end)
		{
			end = arr[i][1];
			// int n = intervals.size();
			intervals.back() = {start, end};
			// auto lval = intervals.back();

			// intervals[0] = {start, arr[i][1]};
		}
	}

	return intervals;
}

int main()
{

	vector<vector<int>> arr;

	arr.push_back({8, 10});
	arr.push_back({1, 3});
	arr.push_back({2, 6});
	arr.push_back({15, 18});

	cout << "Original array:" << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << arr[i][0] << ", " << arr[i][1] << endl;
	}

	sort(arr.begin(), arr.end(), sortcol);

	cout << "Sorted array:" << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << arr[i][0] << ", " << arr[i][1] << endl;
	}

	auto result = mergeOverlappingIntervals(arr, 4);
	cout << "Merged array:" << endl;
	for (auto it = result.begin(); it != result.end(); ++it)
	{
		vector<int> val = *it;
		cout << val[0] << " " << val[1] << endl;
	}

	return 0;
}
