#include <iostream>
#include <cstdlib>

using namespace std;

double squareRoot(double n)
{
	double left = 0;
	double right = (n / 2) + 1;
	double delta = 0.00000001;

	while (left < right)
	{
		double mid = (left + right) / 2.0;
		double m = mid * mid;
		double diff = abs(m - n);

		if (diff < delta)
		{
			return mid;
		}

		if (m > n)
		{
			right = mid;
		}
		else
		{
			left = mid;
		}
	}

	return -1;
}

int main()
{
	double n = 11;

	double result = squareRoot(n);

	cout << "Square root: " << result << endl;

	return 0;
}
