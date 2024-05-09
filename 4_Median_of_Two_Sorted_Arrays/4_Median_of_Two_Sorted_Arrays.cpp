#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int len = nums1.size() + nums2.size();

        int newArr[len];
        int ind = 0;
        for (int i = 0; i < nums1.size(); i++)
        {
            newArr[ind] = nums1[i];
            ind++;
        }
        for (int j = 0; j < nums2.size(); j++)
        {
            newArr[ind] = nums2[j];
            ind++;
        }
        std::sort(newArr, newArr + len);

        double mid;
        if (len % 2 == 0)
        {
            mid = (double)(newArr[len / 2] + newArr[(len / 2) - 1]) / 2;
        }
        else
        {
            mid = newArr[len / 2];
        }

        return mid;
    }
};

int main()
{
    Solution sol;

    // Test cases
    vector<int> nums1_case1 = {1, 3};
    vector<int> nums2_case1 = {2};
    cout << "Median of case 1: " << sol.findMedianSortedArrays(nums1_case1, nums2_case1) << endl;

    vector<int> nums1_case2 = {1, 2};
    vector<int> nums2_case2 = {3, 4};
    cout << "Median of case 2: " << sol.findMedianSortedArrays(nums1_case2, nums2_case2) << endl;

    vector<int> nums1_case3 = {0, 0};
    vector<int> nums2_case3 = {0, 0};
    cout << "Median of case 3: " << sol.findMedianSortedArrays(nums1_case3, nums2_case3) << endl;

    vector<int> nums1_case4 = {};
    vector<int> nums2_case4 = {1};
    cout << "Median of case 4: " << sol.findMedianSortedArrays(nums1_case4, nums2_case4) << endl;

    vector<int> nums1_case5 = {2};
    vector<int> nums2_case5 = {};
    cout << "Median of case 5: " << sol.findMedianSortedArrays(nums1_case5, nums2_case5) << endl;

    return 0;
}
