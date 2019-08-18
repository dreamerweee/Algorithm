/*
* 合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
*/

// 合并两个链表
ListNode* MergeTwoLists(ListNode* l1, ListNode* l2) 
{
	if (l1 == NULL) {
		 return l2;
	}
	else if (l2 == NULL) {
		return l1;
	}
	else {
		if (l1->val <= l2->val) {
			l1->next = MergeTwoLists(l1->next, l2);
			return l1;
		}
		else {
			l2->next = MergeTwoLists(l1, l2->next);
			return l2;
		}
	}
}

ListNode* MergeKLists(vector<ListNode*> &lists, size_t left, size_t right)
{
	if (left >= right)
		return lists[left];

	size_t mid = (left + right) / 2;
	ListNode *left_node = MergeKLists(lists, left, mid);
	ListNode *right_node = MergeKLists(lists, mid + 1, right);
	return MergeTwoLists(left_node, right_node);
}

// 利用二分法，两两合并
ListNode* MergeKLists(vector<ListNode*> &lists)
{
	if (lists.size() == 0)
		return nullptr;
	return MergeKLists(lists, 0, lists.size() - 1);
}