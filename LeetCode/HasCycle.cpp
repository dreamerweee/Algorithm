/*
* 给定一个链表，判断链表中是否有环
* 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 
* 如果 pos 是 -1，则在该链表中没有环
*
* 用 O(1)内存解决此问题
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
*/

bool HasCycle(ListNode *head)
{
	if (!head)
		return false;

	ListNode *fast_node = head;
	ListNode *slow_node = head;
	while (fast_node->next && slow_node->next) {
		slow_node = slow_node->next;
		fast_node = fast_node->next->next;
		if (!fast_node) {
			return false;
		} else if (fast_node == slow_node) {
			return true;
		}
	}

	return false;
}

// leetcode 最优解
bool hasCycle(ListNode *head) {
	if(head == nullptr)
		return false;
	
	ListNode * a = head;
	ListNode * b = head->next;
	while(a->next != nullptr && b->next && b->next->next != nullptr){
		a = a->next;
		b = b->next->next;
		if (a == b)
			return true;
	}
	return false;
}