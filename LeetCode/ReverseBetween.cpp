/*
* 反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
* 说明:
	1 ≤ m ≤ n ≤ 链表长度。
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* ReverseBetween(ListNode* head, int m, int n)
{
	if (!head || m == n) {
		return head;
	}

	int position = 1;
	ListNode *prev = nullptr, *next = nullptr;  // 需要反转区间的前一个结点和后一个结点
	ListNode *h, *t;  // 反转的链表的头和尾结点
	ListNode *p = nullptr;
	ListNode *c = head;
	ListNode *nt = head->next;
	while (c) {
		if (position < m) {
			p = c;
			c = c->next;
		} else {
			if (position == m) {
				prev = p;
				t = c;
				p = nullptr;
			}
			if (position == n) {
				next = c->next;
				c->next = p;
				h = c;

				if (prev) {
					prev->next = h;
				} else {
					 head = h;
				}
				t->next = next;
				break;
			}
			nt = c->next;
			c->next = p;
			p = c;
			c = nt;
		}
		++position;
	}
	return head;
}