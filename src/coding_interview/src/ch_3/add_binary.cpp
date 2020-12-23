#include <iostream>

using namespace std;

string addBinary(string binary1, string binary2)
{
	string result = ""; // Initialize result
	int s = 0;			// Initialize digit sum

	// Traverse both strings starting from last
	// characters
	int i = binary1.size() - 1;
	int j = binary2.size() - 1;

	while (i >= 0 || j >= 0 || s == 1)
	{
		// Comput sum of last digits and carry
		s += ((i >= 0) ? binary1[i] - '0' : 0);
		s += ((j >= 0) ? binary2[j] - '0' : 0);

		// If current digit sum is 1 or 3, add 1 to result
		result = char(s % 2 + '0') + result;

		// Compute carry
		s /= 2;

		// Move to next digits
		i--;
		j--;
	}
	return result;
}

int main()
{
	string a = "1101", b = "100";
	cout << addBinary(a, b) << endl;

	return 0;
}
