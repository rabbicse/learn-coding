#include <iostream>
#include <regex>
using namespace std;

bool isValid(string input)
{
	regex pattern1("^\\s*?[-+]?\\d+\\s*?$");
	regex pattern2("^\\s*?[-+]?(\\d+)[.]?\\d+\\s*?$");
	regex pattern3("^\\s*?[-+]?(\\d+)([.]?\\d+)?e[-+]?\\d+\\s*?$");

	if(regex_match(input, pattern1) || regex_match(input, pattern2) || regex_match(input, pattern3))
	{
		return true;
	}

	return false;
}

int main()
{
	string str[] =
		{
			"123",
			" 123",
			"03",
			"1.56",
			"5e2",
			"0.1e10",
			"-5.69"};
	for (string s : str)
	{
		cout << s << " : " << isValid(s) << endl;
	}
	return 0;
}
