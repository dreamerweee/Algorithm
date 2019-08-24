/*
* 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的
*/

/*
 * Definition for singly-linked list.
 * struct ListNode {
 *		int val;
 * 		ListNode *next;
 * 		ListNode(int x) : val(x), next(null) {}	
 * };
*/

ListNode* MergeTwoLists(ListNode *l1, ListNode *l2)
{
	ListNode *head = NULL;
	ListNode *curr = NULL;
	if (!l1 && !l2)
		return head;
	else if (!l1)
		return l2;
	else if (!l2)
		return l1;
	else {
		if (l1->val < l2->val) {
			head = l1;
			l1 = l1->next;
		}
		else {
			head = l2;
			l2 = l2->next;
		}
		curr = head;
	}

	while (l1 && l2) {
		if (l1->val < l2->val) {
			curr->next = l1;
			l1 = l1->next;
		} else {
			curr->next = l2;
			l2 = l2->next;
		}
		curr = curr->next;
	}

	if (l1) {
		curr->next = l1;
	}
	if (l2) {
		curr->next = l2;
	}

	return head;
}

// leetcode最高效解法
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
{
	if (l1 == NULL) {
		 return l2;
	}
	else if (l2 == NULL) {
		return l1;
	}
	else {
		if (l1->val <= l2->val) {
			l1->next = mergeTwoLists(l1->next, l2);
			return l1;
		}
		else {
			l2->next = mergeTwoLists(l1, l2->next);
			return l2;
		}
	}
}
