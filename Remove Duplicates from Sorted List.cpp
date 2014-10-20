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
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* cur = head;
        ListNode* nxt = cur->next;
        while(nxt != NULL){
            while(nxt && cur->val == nxt->val){
                ListNode* tmp = nxt;
                nxt = nxt->next;
                free(tmp);
            }
            cur->next = nxt;
            cur = nxt;
            if(nxt !=NULL)
                nxt = nxt->next;
        }
        
        return head;
        
    }
};