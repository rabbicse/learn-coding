#include <iostream>
#include<string>

using namespace std;

bool isRotation(string str, string sub)
{
	if(str.size() != sub.size()) return false;
	string mergedString = str + sub;
	size_t found = mergedString.find(sub);
	return found != string::npos;
}

int main()
{
	string str = "abcde";
	string sub = "bcdea";

	bool success = isRotation(str, sub);

	cout << "Success: " << success << endl;
	return 0;
}
