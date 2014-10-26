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
    ListNode *partition(ListNode *head, int x) {
        if(head == NULL)
            return head;
        ListNode leftNode(0);
        ListNode rightNode(0);
        auto left = &leftNode;
        auto right = &rightNode;
        while(head != NULL){
            if(head->val < x){
                left->next = head;
                left = head;
                head = head->next;
            }else{
                right->next = head;
                right = head;
                head = head->next;
            }
        }
        left->next = rightNode.next;
        right->next = NULL;
        return leftNode.next;
    }
};