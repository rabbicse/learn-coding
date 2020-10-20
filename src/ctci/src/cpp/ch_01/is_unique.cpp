#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isUnique(string &text)
{
    int length = text.length();
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (text[i] == text[j])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    vector<string> words = {"abcde", "hello", "apple", "kite", "padle"};

    for (auto word : words)
    {
        cout << "Word [" << word << "}: " << isUnique(word) << endl;
    }
    return 0;
}