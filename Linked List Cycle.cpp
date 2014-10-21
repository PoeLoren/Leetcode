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
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next ==NULL)
            return false;
        ListNode * first = head;
        ListNode * second = head->next;
        while(second != NULL){
            if(first == second)
                return true;
            first = first->next;
            if(second->next)
                second = second->next->next;
            else
                second = second->next;
        }
        return false;
    }
};