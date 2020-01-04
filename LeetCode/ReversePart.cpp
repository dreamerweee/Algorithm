/*
* 给定一个单向链表的头结点head，以及两个整数from和to，
* 在单向链表上把第from个节点到第to个节点这一部分进行反转
*/

Node* ReversePart(Node *head, int from, int to)
{
  int len = 0;
  Node *curr = head;
  Node *from_prev = nullptr;
  Node *to_node = nullptr;
  while (curr) {
    ++len;
    from_prev = len == from - 1 ? curr : from_prev;
    to_node = len == to + 1 ? curr : to_node;
    curr = curr->next;
  }
  if (from > to || from < 1 || to > len) {
    return head;
  }

  curr = from_prev == nullptr ? head : from_prev->next;
  Node *new_next = to_node;
  Node *next = nullptr;
  while (curr != to_node) {
    next = curr->next;
    curr->next = new_next;
    new_next = curr;
    curr = next;
  }
  if (from_prev) {
    from_prev.next = new_next;
  } else {
    head = new_next;
  }
  return head;
}