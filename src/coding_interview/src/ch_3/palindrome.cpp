#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string input)
{
    int start = 0;
    int end = input.size() - 1;
    int mid = (end - start) / 2;
    cout << "Mid: " << mid << endl;

    while(start <= mid && end > mid)
    {
        if(input[start++] != input[end--]) return false;
    }


    return true;
}

int main()
{
    string inputs[] = {
        "abcba",
        "abcdedcba",
        "abcdecdba",
        "aaaa"};
    for (string input : inputs)
    {
        cout << "Is Palindrome: " << isPalindrome(input) << endl;
    }
    return 0;
}
