#include <iostream>
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows <= 1 || s.length() <= 1)
            return s;

        string newstr = "";
        int n = s.length();
        int cycleLen = 2 * numRows - 2;

        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j + i < n; j += cycleLen)
            {
                newstr += s[j + i];
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < n)
                    newstr += s[j + cycleLen - i];
            }
        }

        return newstr;
    }
};

int main()
{
    Solution sol;

    // Test cases
    string test1_input = "PAYPALISHIRING";
    int test1_numRows = 3;
    cout << "Test 1 Output: " << sol.convert(test1_input, test1_numRows) << endl;

    string test2_input = "PAYPALISHIRING";
    int test2_numRows = 4;
    cout << "Test 2 Output: " << sol.convert(test2_input, test2_numRows) << endl;

    string test3_input = "A";
    int test3_numRows = 1;
    cout << "Test 3 Output: " << sol.convert(test3_input, test3_numRows) << endl;

    string test4_input = "ABCDEF";
    int test4_numRows = 2;
    cout << "Test 4 Output: " << sol.convert(test4_input, test4_numRows) << endl;

    return 0;
}