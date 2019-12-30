/*
* 在单链表和双链表中删除倒数第k个节点
*/

// 单链表
typedef struct SingleNode {
  int value;
  SingleNode *next;
  SingleNode(int val) : value(val)
  { }
} SingleNode;

SingleNod* RemoveLastKthNode(SingleNode *head, int k)
{
  if (!head || k < 1) {
    return head;
  }

  SingleNode *curr = head;
  while (curr) {
    curr = curr->next;
    k -= 1;
  }
  if (k == 0) {
    head = head->next;
  } else if (k < 0) {
    curr = head;
    while (++k != 0) {
      curr = curr->next;
    }
    curr->next = curr->next->next;
  }
  return head;
}

// 双向链表
typedef struct DoubleNode {
  int value;
  DoubleNode *prev;
  DoubleNode *next;
  DoubleNode(int val) : value(val)
  { }
} DoubleNode;

DoubleNode* RemoveLastKthNode(DoubleNode *head, int k)
{
  if (!head || k < 1) {
    return head;
  }

  DoubleNode *curr;
  while (curr) {
    curr = curr->next;
    k -= 1;
  }
  if (k == 0) {
    head = head->next;
    head->prev = nullptr;
  } else if (k < 0) {
    curr = head;
    while (++k != 0) {
      curr = curr->next;
    }
    DoubleNode *new_next = curr->next->next;
    curr->next = new_next;
    if (new_next) {
      new_next->prev = curr;
    }
  }

  return head;
}