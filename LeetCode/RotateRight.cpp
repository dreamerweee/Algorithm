/*
* 给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* RotateRight(ListNode* head, int k)
{
	if (k == 0 || !head) {
		return head;
	}

	int len = 0;
	ListNode *p = head;
	while (p) {
		++len;
		p = p->next;
	}
	int move = k % len;
	if (move == 0) {
		return head;
	}
	move = len - move; // 遍历的长度

	p = head;
	ListNode *new_head = nullptr, *new_tail = nullptr;
	while (p->next) {
		if (!new_head) {
			--move;
			if (move == 0) {
				new_tail = p;
				new_head = p->next;
			}
		}
		p = p->next;
	}

	p->next = head;
	head = new_head;
	new_tail->next = nullptr;
	return head;
}