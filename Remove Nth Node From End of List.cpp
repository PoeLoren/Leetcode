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
        ListNode *first = head,*second = head;
        if(head->next == NULL){//only one element
            free(head);
            return NULL;
        }
        for(int i = 0;i < n;i++)
            first = first->next;
        if(first == NULL){//delete the first element
            ListNode* cur = head->next;
            free(head);
            return cur;
        }
        while(first->next != NULL){
            first = first->next;
            second = second->next;
        }
        ListNode *cur = second->next;
        second->next = second->next->next;//delete Nth node
        free(cur);
        return head;
    }
};