#include <iostream>

using namespace std;

int main()
{
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(NULL) {}
    };
	class Solution {
	public:
		ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
			ListNode *p = l1,*q = l2;
			int s,t = 0;
			ListNode *plast = p;
			while(p  && q )
			{
				s = (p->val + q->val + t) % 10;
				t = (p->val + q->val + t) / 10;
				p->val = s;
				plast = p;
				p = p->next;
				q = q->next;
			}
			if(q)
				plast->next = q;
			ListNode *last = plast;
			p = plast->next;
			while(p)
			{
				s = p->val + t;
				p->val = s % 10;
				t = s /10;
				last = p;
				p = p->next;
			}
			if(t != 0)
			{
				ListNode *end = new ListNode(t);
				last->next = end;
			}
			return l1;
		}
	};

	ListNode *l1 = new ListNode(3),*l2 = new ListNode(7);
	ListNode *p1 = new ListNode(2);
	l1->next = p1;
	ListNode *p2 = new ListNode(9);
	p1->next = p2;

	ListNode *q1 = new ListNode(8);
	l2->next = q1;
	ListNode *q2 = new ListNode(4);
	q1->next = q2;
	ListNode *q3 = new ListNode(9);
	q2->next = q3;
	Solution s;
	s.addTwoNumbers(l1,l2);
	return 0;
}