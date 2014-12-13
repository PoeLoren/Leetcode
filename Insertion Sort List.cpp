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
    ListNode *insertionSortList(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* n = new ListNode(0);
        n->next = head;
        ListNode* cur = head->next;
        head->next = NULL;
        ListNode* pre;
        while(cur)
        {
            pre = n;
            ListNode* nxt = cur->next;
            while(pre->next != NULL && cur->val > pre->next->val)
                pre = pre->next;
            cur->next = pre->next;
            pre->next = cur;
            cur = nxt;
        }
        ListNode* res = n->next;
        delete n;
        return res;
    }
};