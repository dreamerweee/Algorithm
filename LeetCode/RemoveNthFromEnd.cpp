/*
* 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
* 给定一个链表: 1->2->3->4->5, 和 n = 2.
* 当删除了倒数第二个节点后，链表变为 1->2->3->5.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* RemoveNthFromEnd(ListNode* head, int n)
{
	ListNode *front = head;
	ListNode *later = head;
	ListNode *prev= nullptr;
	int cur = 1;
	while (front->next) {
		if (cur >= n) {
			prev = later;
			later = later->next;
		}
		front = front->next;
		++cur;
	}

	if (prev) {
		prev->next = later->next;
	} else {  // 删除的是头结点
		head = later->next;
	}
	delete later;
	return head;
}