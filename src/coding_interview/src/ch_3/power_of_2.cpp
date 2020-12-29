#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool powerOfTwo(string number)
{
	int length = number.size();

	vector<int> numbers;
	for (int i = 0; i < length; i++)
	{
		int n = (int)(number[i] - '0');
		numbers.push_back(n);
	}

	bool result = false;

	int i = 0;
	while (true)
	{
		int carry = 0;
		int nonzero = 0;
		vector<int> ans;

		for (int i = 0; i < numbers.size(); i++)
		{
			int n = numbers[i];
			int d = (n + (carry * 10)) / 2;
			if (d)
			{
				nonzero = 1;
			}
			if (nonzero)
			{
				ans.push_back(d);
			}

			carry = (n + (carry * 10)) % 2;
		}

		if (carry == 1 && ans.size() == 0)
		{
			result = true;
			break;
		}
		else if (carry == 1)
		{
			result = false;
			break;
		}

		numbers = ans;

		// if(++i == 10) break;
	}
	return result;
}

int main()
{
	string num = "2049";

	cout << powerOfTwo(num) << endl;
	return 0;
}
