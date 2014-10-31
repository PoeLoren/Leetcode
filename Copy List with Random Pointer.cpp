/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode* random,*newHead;
        RandomListNode* rpt;
        RandomListNode* cur = head;
        if(head == NULL)
            return head;
        while(cur != NULL){
            RandomListNode* newNode = new RandomListNode(cur->label);
            newNode->next = cur->next;
            cur->next = newNode;
            cur = newNode->next;
        }
        cur = head;
        while(cur != NULL){
            RandomListNode* random = cur->random;
            if(random){
                cur->next->random = random->next;
            }
            cur = cur->next->next;
        }
        rpt = newHead = head->next;
        cur = head;
        while(cur->next->next != NULL){
            cur->next = cur->next->next;
            rpt->next = rpt->next->next;
            cur = cur->next;
            rpt = rpt->next;
        }
        cur->next = NULL;
        rpt->next = NULL;
        return newHead;
    }
};