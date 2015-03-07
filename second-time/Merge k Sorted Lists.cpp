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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.empty())
            return NULL;
        if(lists.size() == 1)
            return lists[0];
        queue<ListNode*> q;
        for(int i = 0; i < lists.size(); ++i)
            q.push(lists[i]);
        while(q.size() != 1){
            ListNode* l1 = q.front();
            q.pop();
            ListNode* l2 = q.front();
            q.pop();
            ListNode* nxt = merge(l1, l2);
            q.push(nxt);
        }
        ListNode* res = q.front();
        return res;
    }
    
    ListNode* merge(ListNode* list1, ListNode* list2){
        ListNode* p = new ListNode(0);
        ListNode* pre = p;
        while(list1 != NULL && list2 != NULL){
            if(list1->val < list2->val){
                pre->next = list1;
                pre = list1;
                list1 = list1->next;
            }else{
                pre->next = list2;
                pre = list2;
                list2 = list2->next;
            }
        }
        if(list1)
            pre->next = list1;
        if(list2)
            pre->next = list2;
        ListNode* ret = p->next;
        free(p);
        return ret;
    }
};