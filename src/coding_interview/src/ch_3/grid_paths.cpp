#include<iostream>

using namespace std;

unsigned int factorial(unsigned int n)
{
	if(n <= 1) return 1;

	return n * factorial(n - 1);
}

unsigned int uniquePaths(int a, int b)
{
	/* unique paths fact(a-1+b-1) / fact(a-1) * fact(b -1) */
	--a;
	--b;

	double result = (double)factorial(a + b) / (double)(factorial(a) * factorial(b));

	return (unsigned int) result;
}

int main()
{
	int a = 3, b = 3;

	cout << uniquePaths(a, b) << endl;
	return 0;
}
