/*
* 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，
* 并且它们的每个节点只能存储 一位 数字。
* 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
* 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
*/

ListNode* AddTwoNumbers(ListNode* l1, ListNode* l2)
{
  ListNode *new_head = NULL, *curr;
  int carry = 0;
  while (l1 && l2) {
    int val = l1->val + l2->val + carry;
    carry = val / 10;
    val = val % 10;
    ListNode *node = new ListNode(val);
    if (new_head == NULL) {
      new_head = node;
      curr = node;
    } else {
      curr->next = node;
      curr = curr->next;
    }
    l1 = l1->next;
    l2 = l2->next;
  }

  while (l1) {
    int val = l1->val + carry;
    carry = val / 10;
    val = val % 10;
    ListNode *node = new ListNode(val);
    curr->next = node;
    curr = curr->next;
    l1 = l1->next;
  }

  while (l2) {
    int val = l2->val + carry;
    carry = val / 10;
    val = val % 10;
    ListNode *node = new ListNode(val);
    curr->next = node;
    curr = curr->next;
    l2 = l2->next;
  }

  if (carry == 1) {
    ListNode *node = new ListNode(1);
    curr->next = node;
  }

  return new_head;
}

{
  ListNode head(-1);  // 头结点
  int carry = 0;
  ListNode *prev = &head;
  for (ListNode *p1 = l1, p2 = l2; p1 != NULL || p2 != NULL;
       p1 = p1 == NULL ? NULL : p1->next, p2 = p2 == NULL ? NULL : p2->next, prev = prev->next) {
    int val1 = p1 == NULL ? 0 : p1->val;
    int val2 = p2 == NULL ? 0 : p2->val;
    int val = val1 + val2 + carry;
    carry = val / 10;
    val = val % 10;
    prev->next = new ListNode(val);
  }
  if (carry > 0) {
    prev->next = new ListNode(carry);
  }
  return head.next;
}