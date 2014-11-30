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
    ListNode* mergeSort(ListNode* l1, ListNode* l2)
    {
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        ListNode* head = new ListNode(0);
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* cur = head;
        while(p1 && p2)
        {
            if(p1->val < p2->val)
            {
                cur->next = p1;
                p1 = p1->next;
            }
            else
            {
                cur->next = p2;
                p2 = p2->next;
            }
            cur = cur->next;
        }
        if(p1)
            cur->next = p1;
        else
            cur->next = p2;
        ListNode* res = head->next;
        delete head;
        head = NULL;
        return res;
        
    }

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.empty())
            return NULL;
        if(lists.size() == 1)
            return lists[0];
        queue<ListNode*> q;
        int i = 0;
        for(;i + 1< lists.size();i += 2)
        {
            ListNode* m = mergeSort(lists[i],lists[i+1]);
            q.push(m);
        }
        if(i == lists.size() - 1)
        {
            q.push(lists[i]);
        }
        while(q.size() > 1)
        {
            ListNode* cur1 = q.front();
            q.pop();
            ListNode* cur2 = q.front();
            q.pop();
            ListNode* nxt = mergeSort(cur1,cur2);
            q.push(nxt);
        }
        return q.front();
    }
};