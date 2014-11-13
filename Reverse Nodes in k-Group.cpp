class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(head == NULL)
            return head;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* nHead = new ListNode(0);
        ListNode* pre = nHead;
        pre->next = head;
        
        while(fast != NULL){
            int len = 0;
            while(len < k-1 && fast!= NULL){
                fast = fast->next;
                len++;
            }
            if(len == k-1 && fast != NULL){
                ListNode* nexthead = fast->next;
                fast->next = NULL;
                pre->next = reverseList(slow);
                pre = slow;
                pre->next = nexthead;
                fast = slow = nexthead;
            }
        }
        return nHead->next;
    }
    
    ListNode* reverseList(ListNode* head){
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* tmpHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return tmpHead;
    }
};