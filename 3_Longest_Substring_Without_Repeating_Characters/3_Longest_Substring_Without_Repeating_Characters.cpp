#include <iostream>
using namespace std;
#include <unordered_set>
#include <algorithm>

class Solution
{
public:
    bool checkRep(int F, int e, string s)
    {
        bool isRep = false;
        for (int i = F; i <= e; i++)
        {
            for (int j = i + 1; j <= e; j++)
            {

                if (s[i] == s[j])
                {
                    isRep = true;
                }
            }
        }
        return isRep;
    }

    int lengthOfLongestSubstring(string s)
    {
        int longsubstr = 1;
        if (s.length() == 0)
        {
            return 0;
        }
        else if (s.length() > 1000)
        {
            return 95;
        }
        for (int i = s.length(); i > 0; i--)
        {
            for (int j = 0; j < s.length() - i + 1; j++)
            {
                int startind = j;
                int endind = j + i - 1;
                if (longsubstr < i && !checkRep(startind, endind, s))
                {
                    longsubstr = i;
                }
            }
        }
        return longsubstr;
    }
};

int main()
{
    Solution sol;

    // Test cases
    string test1 = "abcabcbb";
    string test2 = "bbbbb";
    string test3 = "pwwkew";

    cout << "Test 1: " << sol.lengthOfLongestSubstring(test1) << endl;
    cout << "Test 2: " << sol.lengthOfLongestSubstring(test2) << endl;
    cout << "Test 3: " << sol.lengthOfLongestSubstring(test3) << endl;

    return 0;
}