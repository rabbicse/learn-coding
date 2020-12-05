#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool hotelBookingPossible(int *arrival, int *departures, int k, int n)
{
	bool success = true;
	int i = 0, j = 0, count = 0;

	sort(arrival, arrival + n);
	sort(departures, departures + n);

	while (i < n && j < n)
	{
		if (arrival[i] < departures[j])
		{
			if (++count > k)
			{
				success = false;
			}
			++i;
		}
		else
		{
			count--;
			++j;
		}
	}
	return success;
}
int main()
{
	int arrival[] = {1, 3, 5};
	int departures[] = {2, 6, 8};
	int k = 1;

	bool success = hotelBookingPossible(arrival, departures, k, 3);
	cout << "Hotel booking possible: " << success << endl;

	return 0;
}
