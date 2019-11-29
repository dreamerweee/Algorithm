/*
* 请判断一个链表是否为回文链表。
* 用 O(n) 时间复杂度和 O(1) 空间复杂度解决
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// prev为head的前一个节点，将以node为头节点的链表反转
void ReverseList(ListNode *prev, ListNode *node)
{
	ListNode *p = nullptr;
	ListNode *c = node;
	ListNode *n, *new_head;
	while (c) {
		n = c->next;
		c->next = p;
		p = c;
		if (!n) {
			new_head = c;
		}
		c = n;
	}
	prev->next = new_head;
}

bool IsPalindrome(ListNode* head)
{
	if (!head || !head->next) {
		return true;
	}

	ListNode *slow = head, *fast = head;
	ListNode *prev;
	while (fast && fast->next) {
		prev = slow;
		slow = slow->next;
		fast = fast->next;
		if (fast)
			fast = fast->next;
	}
	ReverseList(prev, slow);
	ListNode *mid = slow;
	fast = head;
	while (fast != mid) {
		if (fast->val != slow->val) {
			return false;
		}
		fast = fast->next;
		slow = slow->next;
	}
	return true;
}
