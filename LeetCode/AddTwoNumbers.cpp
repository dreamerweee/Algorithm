/* 
* 给出两个 非空 的链表用来表示两个非负的整数。
* 其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
* 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
* 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
*/ 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* AddTwoNumbers(ListNode* l1, ListNode* l2)
{
	ListNode *head1 = l1;
	ListNode *head2 = l2;
	ListNode *last = NULL;
	int carry = 0;
	while (l1 || l2) {
		if (l1 && l2) {
			int res = l1->val + l2->val + carry;
			l1->val = res % 10;
			carry = res / 10;
			last = l1;
			l1 = l1->next;
			l2 = l2->next;
		} else if (l1) {
			l1->val += carry;
			carry = l1->val / 10;
			l1->val %= 10;
			last = l1;
			l1 = l1->next;
		} else {
			l2->val += carry;
			carry = l2->val / 10;
			last->next = new ListNode(l2->val % 10);
			last = last->next;
			l2 = l2->next;
		}
	}

	if (last && carry > 0) {
		last->next = new ListNode(carry);
	}

	return head1;
}