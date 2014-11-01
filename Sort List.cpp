class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return head;
        return mergeSort(head);
    }
    
    ListNode* mergeSort(ListNode* head){
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* fast = head;//fast set to head
        ListNode* slow = head,*pre = NULL;//notice set the next value of first list's last node to NULL
        while(fast && fast->next){
            fast = fast->next->next;
            pre = slow;
            slow = slow->next;
        }
        
        pre->next = NULL;
        ListNode* l = mergeSort(head);
        ListNode* r = mergeSort(slow);
        return merge(l,r);
    }
    
    ListNode* merge(ListNode* l,ListNode* r){
        ListNode* head = new ListNode(0);
        ListNode* p = head;
        while(l && r){
            if(l->val > r->val){
                p->next = r;
                r = r->next;
            }else{
                p->next = l;
                l = l->next;
            }
            p = p->next;
        }
        if(l)
            p->next = l;
        if(r)
            p->next = r;
        p = head->next;
        delete head;
        return p;
    }
};