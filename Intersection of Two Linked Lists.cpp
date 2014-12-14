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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 0;
        int len2 = 0;
        ListNode* p = headA;
        while(p)
        {
            p = p->next;
            len1++;
        }
        p = headB;
        while(p)
        {
            p = p->next;
            len2++;
        }
        if(len1 > len2)
        {
            int diff = len1 - len2;
            return findIntersection(headA, headB, diff);
        }
        else
        {
            int diff = len2 - len1;
            return findIntersection(headB, headA, diff);
        }
    }
    
    ListNode* findIntersection(ListNode* a, ListNode* b, int diff)
    {
        while(diff--)
            a = a->next;
        while(a && a != b)
        {
            a = a->next;
            b = b->next;
        }
        if(a != NULL)
            return a;
        else
            return NULL;
    }
};