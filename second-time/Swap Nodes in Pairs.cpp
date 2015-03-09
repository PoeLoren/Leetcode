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
    ListNode *swapPairs(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* nHead = new ListNode(0);
        nHead->next = head;
        ListNode* cur = head;
        ListNode* pre = nHead;
        while(cur != NULL && cur->next != NULL){
            swap(pre, cur, cur->next);
            pre = cur;
            cur = cur->next;
        }
        return nHead->next;
    }
    
    void swap(ListNode* pre, ListNode* p1, ListNode* p2){
        p1->next = p2->next;
        p2->next = p1;
        pre->next = p2;
    }
};