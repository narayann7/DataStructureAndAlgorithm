//leetcode no. :25
//only the logic part

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
    ListNode *reverseKGroup(ListNode *head, int k)
    {

        ListNode *h = head;
        int l = 0;
        while (h != NULL)
        {
            l++;
            h = h->next;
        }

        if (l < k)
        {
            return head;
        }

        if (head == NULL || head->next == NULL)
            return head;

        ListNode *temp = head;
        ListNode *p;
        ListNode *q = NULL;
        ListNode *p1 = temp;
        int k1 = 0;
        while (k1 != k && temp != NULL)

        {
            p = temp;

            temp = temp->next;
            p->next = q;
            q = p;
            k1++;
        }
        head = p;

        p1->next = reverseKGroup(temp, k);
        return head;
    }
};