/*
* 定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。
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
  if (head == NULL || head->next == NULL) {
    return head;
  }
  ListNode *prev = NULL;
  ListNode *curr = head;
  ListNode *next = NULL;
  while (curr->next) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  curr->next = prev;
  return curr;
}