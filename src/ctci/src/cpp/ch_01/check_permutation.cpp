#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

bool arePermutation(string word1, string word2)
{
    if(word1.length() != word2.length()) return false;

    sort(word1.begin(), word1.end());
    sort(word2.begin(), word2.end());

    for(int i = 0; i < word1.length(); i++)
    {
        if(word1[i] != word2[i]) return false;
    }
    return true;
}

int main()
{
    string word1 = "abcde";
    string word2 = "edcbg";

    bool per = arePermutation(word1, word2);
    cout << "Result: " << per << endl;
    return 0;
}