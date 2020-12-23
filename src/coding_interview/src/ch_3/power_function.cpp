#include <iostream>
using namespace std;

int power(int a, int n)
{
	if (n <= 1)
	{
		return a;
	}

	if (n % 2 == 1)
	{
		return a * power(a, n - 1);
	}
	else
	{
		n = n / 2;
		return power(a, n) * power(a, n);
	}
}

int main()
{
	int a = 3;
	int n = 5;
	int result = power(a, n);

	cout << "Result: " << result << endl;
	return 0;
}
