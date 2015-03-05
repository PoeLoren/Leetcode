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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(head == NULL)
            return head;
        ListNode* h = new ListNode(0);
        h->next = head;
        ListNode* pre = h;
        ListNode* fast = head;
        ListNode* slow = head;
        while(--n){
            fast = fast->next;
        }
        while(fast->next){
            pre = slow;
            slow = slow->next;
            fast = fast->next;
        }
        pre->next = pre->next->next;
        free(slow);
        ListNode* res = h->next;
        free(h);
        return res;
    }
};