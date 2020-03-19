/*
* 反转从位置 m 到 n 的链表。请使用一趟扫描完成反转
*/

ListNode* reverseBetween(ListNode* head, int m, int n)
{
  ListNode tmp(-1);
  tmp.next = head;

  ListNode *prev = &tmp;
  for (int i = 1; i < m; ++i) {
    prev = prev->next;
  }

  ListNode *r_head = prev;
  prev = prev->next;
  ListNode *curr = prev->next;
  for (int i = m; i < n; ++i) {
    prev->next = curr->next;
    curr->next = r_head->next;
    r_head->next = curr;
    curr = prev->next;
  }

  return tmp.next;
}