/*
* 在 O(nlogn) 时间复杂度和常数级空间复杂度下，对链表进行排序
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* SortList(ListNode* head)
{
	if (head == nullptr || head->next == nullptr) {
		return head;
	}

	ListNode *fast = head->next, *slow = head;
	while (fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;
	}

	ListNode *cut_node = slow->next;
	slow->next = nullptr;

	ListNode *left = SortList(head);
	ListNode *right = SortList(cut_node);
	ListNode temp(0);
	ListNode *p = &temp;
	while (left && right) {
		if (left->val < right->val) {
			p->next = left;
			left = left->next;
		} else {
			p->next = right;
			right = right->next;
		}
		p = p->next;
	}
	p->next = left ? left : right;
	return temp.next;
}