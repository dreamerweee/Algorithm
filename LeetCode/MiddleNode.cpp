/*
* 给定一个带有头结点 head 的非空单链表，返回链表的中间结点
* 如果有两个中间结点，则返回第二个中间结点
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
*/

// 快慢指针
ListNode* MiddleNode(ListNode *head)
{
	ListNode *fast_node = head;
	ListNode *slow_node = head;
	while (fast_node->next && slow_node->next) {
		slow_node = slow_node->next;
		fast_node = fast_node->next;
		if (fast_node->next) {
			fast_node = fast_node->next;
		} else {
			break;
		}
	}

	return slow_node;
}