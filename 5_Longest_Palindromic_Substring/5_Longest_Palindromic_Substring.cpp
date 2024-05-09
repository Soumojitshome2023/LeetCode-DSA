#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        bool isPalindrome = true;
        int strlen = s.length();
        int i = 0, j = strlen - 1;
        while (i != j && i < j)
        {
            if (s[i] != s[j])
            {
                isPalindrome = false;
            }
            i++;
            j--;
        }
        return isPalindrome;
    }

    string longestPalindrome(string s)
    {
        int longsubstr = 0;
        string longstr = s;
        for (int i = s.length(); i > 0; i--)
        {
            for (int j = 0; j < s.length() - i + 1; j++)
            {
                if (longsubstr < i && isPalindrome(s.substr(j, i)))
                {
                    longsubstr = i;
                    longstr = s.substr(j, i);
                    return longstr;
                }
            }
        }
        return longstr;
    }
};

int main()
{
    Solution sol;

    // Test cases
    string test1 = "babad";
    string test2 = "cbbd";
    string test3 = "a";
    string test4 = "ac";

    cout << "Longest palindrome of test1: " << sol.longestPalindrome(test1) << endl;
    cout << "Longest palindrome of test2: " << sol.longestPalindrome(test2) << endl;
    cout << "Longest palindrome of test3: " << sol.longestPalindrome(test3) << endl;
    cout << "Longest palindrome of test4: " << sol.longestPalindrome(test4) << endl;

    return 0;
}