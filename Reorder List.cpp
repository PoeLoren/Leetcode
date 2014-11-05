class Solution {
public:
    void reorderList(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return;
        
        ListNode* fast = head;
        ListNode* slow = head;
        while(NULL != fast && NULL != fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* nHead = slow->next;
        slow->next = NULL;
        nHead = reverseList(nHead);
        ListNode* p1 = head;
        ListNode* p2 = nHead;
        ListNode* cur = p1;
        while(p1 && p2){
            p1 = p1->next;
            cur->next = p2;
            p2 = p2->next;
            cur->next->next = p1;
            cur = p1;
        }
        
    }
    
    ListNode* reverseList(ListNode* head){
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* curHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return curHead;
    }
};