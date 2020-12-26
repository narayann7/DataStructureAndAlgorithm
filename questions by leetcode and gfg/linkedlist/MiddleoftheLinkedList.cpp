//leetcode 876 number.
//its only the logic part 
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
class Solution {
public:
    ListNode *middleNode(ListNode *head)
    {

        ListNode *temp;
        ListNode *temp1;
        int c = 0;
        temp = head;
        while (temp != NULL)
        {
            temp = temp->next;
            c++;
        }
        int x = c;
        c = (c % 2 == 0) ? (c / 2) + 1 : c / 2;

        temp = head;

        while (c != 0)
        {
            temp1 = temp;
            temp = temp->next;
            c--;
        }
        if (x % 2 != 0)
            return temp;
        else
            return temp1;
    }
};
//code contributed by: narayan
//git: narayann7
//email: laxminarayanreddy432@gmail.com
//leetcode: narayann7