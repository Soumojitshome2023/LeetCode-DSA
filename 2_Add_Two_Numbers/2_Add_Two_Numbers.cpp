#include <iostream>

using namespace std;

// Definition for singly-linked list
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *h1 = l1;
        ListNode *h2 = l2;
        ListNode *l3 = nullptr;
        ListNode *h3 = nullptr;
        int carry = 0;
        while (h1 != nullptr || h2 != nullptr || carry != 0)
        {
            int tempVal;
            if (h1 == nullptr && h2 != nullptr)
            {
                tempVal = (h2->val + carry) % 10;
                carry = (h2->val + carry) / 10;
                h2 = h2->next;
            }
            else if (h2 == nullptr && h1 != nullptr)
            {
                tempVal = (h1->val + carry) % 10;
                carry = (h1->val + carry) / 10;
                h1 = h1->next;
            }
            else if (h2 == nullptr && h1 == nullptr && carry != 0)
            {
                tempVal = carry;
                carry = 0;
            }
            else
            {
                tempVal = (h1->val + h2->val + carry) % 10;
                carry = (h1->val + h2->val + carry) / 10;
                h1 = h1->next;
                h2 = h2->next;
            }

            ListNode *n1 = new ListNode();
            if (l3 == nullptr)
            {
                l3 = n1;
            }
            n1->val = tempVal;
            if (h3 != nullptr)
            {
                h3->next = n1;
            }
            h3 = n1;
        }
        return l3;
    }
};

int main()
{
    // Test cases
    ListNode *l1_case1 = new ListNode(2);
    l1_case1->next = new ListNode(4);
    l1_case1->next->next = new ListNode(3);

    ListNode *l2_case1 = new ListNode(5);
    l2_case1->next = new ListNode(6);
    l2_case1->next->next = new ListNode(4);

    Solution sol;
    ListNode *result_case1 = sol.addTwoNumbers(l1_case1, l2_case1);

    // Output the result
    ListNode *temp_case1 = result_case1;
    cout << "Case 1: ";
    while (temp_case1 != nullptr)
    {
        cout << temp_case1->val;
        if (temp_case1->next != nullptr)
            cout << " -> ";
        temp_case1 = temp_case1->next;
    }
    cout << endl;

    // Clean up memory
    delete l1_case1;
    delete l2_case1;
    delete result_case1;

    // Test case 2
    ListNode *l1_case2 = new ListNode(0);
    ListNode *l2_case2 = new ListNode(0);

    ListNode *result_case2 = sol.addTwoNumbers(l1_case2, l2_case2);

    ListNode *temp_case2 = result_case2;
    cout << "Case 2: ";
    while (temp_case2 != nullptr)
    {
        cout << temp_case2->val;
        if (temp_case2->next != nullptr)
            cout << " -> ";
        temp_case2 = temp_case2->next;
    }
    cout << endl;

    // Clean up memory
    delete l1_case2;
    delete l2_case2;
    delete result_case2;

    return 0;
}
