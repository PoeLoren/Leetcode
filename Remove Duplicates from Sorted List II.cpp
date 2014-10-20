  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode next;
      ListNode(int x)  val(x), next(NULL) {}
  };
 
class Solution {
public
    ListNode deleteDuplicates(ListNode head) {
        if(head == NULL  head-next == NULL)
            return head;
        ListNode cur = head;
        ListNode first = new ListNode(0);
        first-next = head;
        ListNode pre = first;
        while(cur != NULL){
            bool isDup = false;
            while(cur-next != NULL && cur-val == cur-next-val){
                isDup = true;
                ListNode tmp = cur;
                cur = cur-next;
                delete tmp;
            }
            if(isDup){
                pre-next = cur-next;
                ListNode tmp = cur;
                cur = cur-next;
                delete tmp;
            }else{
                pre = cur;
                cur = cur-next;
            }
        }
        return first-next;
        
    }
};