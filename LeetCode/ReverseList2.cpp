/*
* 反正单向链表和反正双向链表
*/

// 单向链表
Node* ReverseList(Node *head)
{
  if (!head || !head->next) {
    return head;
  }
  Node *prev = nullptr;
  Node *curr = head;
  Node *next;
  while (curr) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  return prev;
}

// 双向链表
DoubleNode* ReverseList(DoubleNode *head)
{
  if (!head || !head->next) {
    return head;
  }

  DoubleNode *prev = nullptr;
  DoubleNode *next = nullptr;
  while (head) {
    next = head->next;
    head->next = prev;
    head->prev = next;
    prev = head;
    head = next;
  }
  return prev;
}