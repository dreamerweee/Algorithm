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

// 递归解法
ListNode* deleteDuplicates(ListNode *head)
{
	if (head == nullptr || head->next == nullptr) {
		retturn head;
	}
	head->next = recursionDelete(head->next, head->val);
	return head;
}

ListNode* recursionDelete(ListNode *node, int val)
{
	if (node == nullptr) {
		return node;
	}
	if (node->val != val) {
		node->next = recursionDelete(node->next, node->val);
		return node;
	}
	ListNode *tmp = node;
	node = node->next;
	delete tmp;
	return recursionDelete(node, val);
}

// 递归优化
ListNode* deleteDuplicates(ListNode *head)
{
	if (head == nullptr || head->next == nullptr) {
		return head;
	}
	recursionDelete(head, head->next);
	return head;
}

void recursionDelete(ListNode *prev, ListNode *curr)
{
	if (curr == nullptr) {
		return;
	}
	if (prev->val == curr->val) {
		prev->next = curr->next;
		delete curr;
		recursionDelete(prev, prev->next);
	} else {
		recursionDelete(prev->next, curr->next);
	}
}

// 循环解法
ListNode* deleteDuplicates(ListNode *head)
{
	if (head == nullptr || head->next == nullptr) {
		return head;
	}
	ListNode *prev = head;
	ListNode *curr = head->next;
	while (curr != nullptr) {
		if (prev->val == curr->val) {
			prev->next = curr->next;
			delete curr;
		} else {
			prev = curr;
		}
		curr = prev->next;
	}

	return head;
}