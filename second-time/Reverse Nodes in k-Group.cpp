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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(head == NULL)
            return head;
        ListNode* nHead = new ListNode(0);
        nHead->next = head;
        ListNode* cur = head;
        ListNode* pre = nHead;
        ListNode* last = cur;
        while(last){
            int i = 0;
            for(; i < k - 1 && last != NULL; ++i)
                last = last->next;
            if(i == k - 1 && last != NULL){
                ListNode* tmp = last->next;
                last->next = NULL;
                pre->next = reverse(cur);
                pre = cur;
                cur->next = tmp;
                cur = tmp;
                last = cur;
            }
        }
        return nHead->next;
    }
    
    ListNode* reverse(ListNode* cur){
        if(cur->next == NULL)
            return cur;
        ListNode* head = reverse(cur->next);
        cur->next->next = cur;
        cur->next = NULL;
        return head;
    }
};