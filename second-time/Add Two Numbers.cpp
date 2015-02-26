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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if(l2 == NULL)
            return l1;
        if(l1 == NULL)
            return l2;
        int r = 0;
        ListNode* pre = NULL;
        ListNode* res = l1;
        while(l1 != NULL && l2 != NULL){
            l1->val = l1->val + l2->val + r;
            r = l1->val / 10;
            l1->val %= 10;
            pre = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l2)
            pre->next = l2;
        l1 = pre->next;
        while(l1){
            l1->val += r;
            r = l1->val / 10;
            l1->val %= 10;
            pre = l1;
            l1 = l1->next;
        }
        if(r != 0){
            ListNode* end = new ListNode(r);
            pre->next = end;
        }
        return res;
        
    }
};