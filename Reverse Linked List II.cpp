class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode* mptr = head;
        ListNode* nptr = head;
        ListNode* newHead = new ListNode(0);
        newHead->next = head;
        ListNode* pre = newHead;
        int i = 1;
        while(i != m){
            i++;
            pre = mptr;
            mptr = mptr->next;
        }
        i = 1;
        while(i != n){
            i++;
            nptr = nptr->next;
        }
        ListNode* next = nptr->next;
        nptr->next = NULL;
        pre->next = reverseList(mptr);
        mptr->next = next;
        return newHead->next;
    }
    
    ListNode* reverseList(ListNode* head){
        if(head->next == NULL)
            return head;
        ListNode* tmpHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return tmpHead;
    }
};