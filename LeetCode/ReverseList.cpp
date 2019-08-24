/*
* 可以迭代或递归地反转链表
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
*/

ListNode* ReverseList(ListNode* head)
{
	ListNode *prev = NULL;
	ListNode *curr = head;
	ListNode *next = NULL;
	while (curr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}