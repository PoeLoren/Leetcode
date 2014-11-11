class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if(head == NULL)
            return NULL;
        TreeNode* res = convert(head);
    }
    
    TreeNode* convert(ListNode* head){
        if(head == NULL)
            return NULL;
        if(head->next == NULL){
            TreeNode* tHead = new TreeNode(head->val);
            return tHead;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* pre = head;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            pre = slow;
            slow = slow->next;
        }
        pre->next = NULL;
        TreeNode* tHead = new TreeNode(slow->val);
        TreeNode* left = convert(head);
        TreeNode* right = convert(slow->next);
        tHead->left = left;
        tHead->right = right;
        return tHead;
    }
};