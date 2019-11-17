/*
* 给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
* 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置
	（索引从 0 *开始）。 如果 pos 是 -1，则在该链表中没有环。
* 说明：不允许修改给定的链表。
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *DetectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while (true) {
        	if (!fast || !fast->next) {
        		return nullptr;
        	}
        	fast = fast->next->next;
        	slow = slow->next;
        	if (fast == slow) {
        		break;
        	}
        }
        fast = head;
        while (fast != slow) {
        	fast = fast->next;
        	slow = slow->next;
        }
        return slow;
    }
};