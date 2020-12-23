#include <iostream>
#include <string>

using namespace std;

string compress(string str)
{
	if (str.size() <= 1)
		return str;

	int length = str.size();
	char temp = str[0];
	int count = 0;
	string result = "";
	for (int i = 1; i < length; i++)
	{
		if (str[i] == temp)
		{
			count++;
		}				
		else if (count > 0)
		{
			/* set count to next */
			result += temp + to_string(count + 1);			
			count = 0;
		}	

		temp = str[i];	
	}

	result += temp + to_string(count + 1);

	return result;
}

int main()
{
	string str = "aabbbccccddd";
	string result = compress(str);
	cout << "Result: " << result << endl;
	return 0;
}
