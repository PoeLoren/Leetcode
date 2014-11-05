class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if(head == NULL)
            return head;
        ListNode* fast = head;
        ListNode* slow = head;
        int len = 0;
        while(fast){
            fast = fast->next;
            len++;
        }
        fast = head;
        k = k % len;
        for(int i = 0;i < k && fast;i++)
            fast = fast->next;
        if(fast == NULL)
            return head;
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        fast->next = head;
        head = slow->next;
        slow->next = NULL;
        return head;
    }
};