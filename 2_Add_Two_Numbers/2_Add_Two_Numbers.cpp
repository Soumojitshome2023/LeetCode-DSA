/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // cout<<l1->val;
        ListNode *h1 = l1;
        ListNode *h2 = l2;
        ListNode *l3 = nullptr;
        ListNode *h3 = nullptr;
        int carry = 0;
        while (h1 != nullptr || h2 != nullptr || carry != 0)
        {
            int temval;
            if (h1 == nullptr && h2 != nullptr)
            {
                temval = (h2->val + carry) % 10;
                carry = (h2->val + carry) / 10;
                h2 = h2->next;
            }
            else if (h2 == nullptr && h1 != nullptr)
            {
                temval = (h1->val + carry) % 10;
                carry = (h1->val + carry) / 10;
                h1 = h1->next;
            }
            else if (h2 == nullptr && h2 == nullptr && carry != 0)
            {
                temval = carry;
                carry = 0;
            }
            else
            {
                temval = (h1->val + h2->val + carry) % 10;
                carry = (h1->val + h2->val + carry) / 10;
                h1 = h1->next;
                h2 = h2->next;
            }

            ListNode *n1 = new ListNode();
            if (l3 == nullptr)
            {
                l3 = n1;
            }
            n1->val = temval;
            if (h3 != nullptr)
            {
                h3->next = n1;
            }
            h3 = n1;
        }
        return l3;
    }
};