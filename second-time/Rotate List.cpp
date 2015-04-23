/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL|| head->next == NULL || k == 0)
            return head;
        int len = 0;
        ListNode* p = head;
        while(p != NULL)
        {
            p = p->next;
            len++;
        }
        k %= len;
        if(k == 0)
            return head;
        ListNode* fast = head;
        ListNode* slow = head;
        for(int i = 0; i < k; ++i)
        {
            fast = fast->next;
        }
        while(fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* ret = slow->next;
        slow->next = NULL;
        fast->next = head;
        return ret;
    }
};