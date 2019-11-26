/*
* 编写一个程序，找到两个单链表相交的起始节点。
* 注意：
* 	如果两个链表没有交点，返回 null.
* 	在返回结果后，两个链表仍须保持原有的结构。
* 	可假定整个链表结构中没有循环。
* 	程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 时间复杂度O(A*B)
ListNode *GetIntersectionNode(ListNode *headA, ListNode *headB)
{
	if (!headA || !headB) {
		return nullptr;
	}

	ListNode *currA = headA, *currB;
	while (currA) {
		currB = headB;
		while (currB) {
			if (currA == currB) {
				return currA;
			} else {
				currB = currB->next;
			}
		}
		currA = currA->next;
	}
	return nullptr;
}

/*
leetcode 双指针法
	创建两个指针 pA 和 pB，分别初始化为链表 A 和 B 的头结点。然后让它们向后逐结点遍历。
	当 pA 到达链表的尾部时，将它重定位到链表 B 的头结点 (你没看错，就是链表 B); 类似的，当 pB 到达链表的尾部时，将它重定位到链表 A 的头结点。
	若在某一时刻 pA 和 pB 相遇，则 pA/pB 为相交结点。
	想弄清楚为什么这样可行, 可以考虑以下两个链表: A={1,3,5,7,9,11} 和 B={2,4,9,11}，相交于结点 9。 由于 B.length (=4) < A.length (=6)，pB 比 pA 少经过 2 个结点，会先到达尾部。将 pB 重定向到 A 的头结点，pA 重定向到 B 的头结点后，pB 要比 pA 多走 2 个结点。因此，它们会同时到达交点。
	如果两个链表存在相交，它们末尾的结点必然相同。因此当 pA/pB 到达链表结尾时，记录下链表 A/B 对应的元素。若最后元素不相同，则两个链表不相交。

作者：LeetCode
链接：https://leetcode-cn.com/problems/intersection-of-two-linked-lists/solution/xiang-jiao-lian-biao-by-leetcode/
*/
ListNode *GetIntersectionNode(ListNode *headA, ListNode *headB)
{
	if (!headA || !headB) {
		return nullptr;
	}

	ListNode *pA = headA, *pB = headB;
	while (pA != pB) {
		pA = pA == nullptr ? headB : pA->next;
		pB = pB == nullptr ? headA : pB->next;
	}
	return pA;
}