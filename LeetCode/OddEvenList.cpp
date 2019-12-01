/*
* 给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。
	请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。
* 请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* OddEvenList(ListNode* head)
{
	if (!head || !head->next) {
		return head;
	}

	ListNode *even_head = nullptr;
	ListNode *odd = nullptr;
	ListNode *even = nullptr;
	ListNode *curr = head;
	bool odd_flag = true;
	while (curr) {
		if (odd_flag) {
			odd_flag = false;
			if (odd) {
				odd->next = curr;
			}
			odd = curr;
		} else {
			odd_flag = true;
			if (!even_head) {
				even_head = curr;
			}
			if (even) {
				even->next = curr;
			}
			even = curr;
		}
		curr = curr->next;
	}
	odd->next = even_head;
	even->next = nullptr;

	return head;
}