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