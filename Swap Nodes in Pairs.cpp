/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /**
  * Definition for points
  * pre->first->cur
  * 
  * 
  */
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if(head == NULL || head->next == NULL)//no element or only one Node
            return head;
        ListNode* newHead = head->next;
        ListNode* cur = head->next;
        ListNode* first = head;
		ListNode* pre = first;
        cur = cur->next;
        first->next->next = first;
        first->next = cur;

        if(cur == NULL||(cur !=NULL &&cur->next == NULL)){//two or three nodes
            return newHead;
        }
		first = cur;
		cur = cur->next;
        while(cur != NULL||(cur !=NULL &&cur->next != NULL)){
			pre->next = cur;
			cur = cur->next;
            pre = first;
            first->next->next = first;
            first->next = cur;
            first = cur;
            if(cur != NULL)
                cur = cur->next;
        }
        return newHead;
        
    }
};