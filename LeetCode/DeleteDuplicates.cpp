/*
* 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* DeleteDuplicates(ListNode* head)
{
	if (!head) {
		return head;
	}

	int cur_val = head->val;
	ListNode *cur_node = head, *next_node = head->next;
	while (next_node) {
		if (cur_val == next_node->val) {
			cur_node->next = next_node->next;
			delete next_node;
			next_node = cur_node->next;
		} else {
			cur_node = next_node;
			next_node = cur_node->next;
			cur_val = cur_node->val;
		}
	}
	return head;
}
