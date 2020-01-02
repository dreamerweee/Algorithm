/*
* 反正单向链表和反正双向链表
*/

Node* ReverseList(Node *head)
{
  if (!head || !head->next) {
    return head;
  }
  Node *prev = head;
  Node *curr = head->next;
  Node *next;
  while (curr) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  return prev;
}