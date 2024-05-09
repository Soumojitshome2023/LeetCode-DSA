#include <iostream>
#include <climits> // for INT_MAX and INT_MIN
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        int newint = 0;
        while (x != 0)
        {
            int rem = x % 10;
            // Check for overflow before updating newint
            if (newint > INT_MAX / 10 || (newint == INT_MAX / 10 && rem > 7))
                return 0;
            if (newint < INT_MIN / 10 || (newint == INT_MIN / 10 && rem < -8))
                return 0;
            newint = rem + (newint * 10);
            x = x / 10;
        }
        return newint;
    }
};

int main()
{
    Solution sol;

    // Test case
    int test_input = 123;
    int expected_output = 321;
    int result = sol.reverse(test_input);

    cout << "Test input: " << test_input << endl;
    cout << "Expected output: " << expected_output << endl;
    cout << "Result: " << result << endl;

    return 0;
}
