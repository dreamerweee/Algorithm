/*
* 给定链表的头结点head，实现删除链表的中间节点
* 进阶：给定链表的头结点head、整数a和b，实现删除位于a/b处的节点
*/

// 单链表
typedef struct Node {
  int value;
  Node *next;
  Node(int val) : value(val)
  { }
} Node;

Node* RemoveMidNode(Node *head)
{
  if (!head || !head->next) {
    return head;
  }
  if (head->next->next == nullptr) {
    return head->next;
  }
  Node *prev = head;
  Node *curr = head->next->next;
  while (curr->next && curr->next->next) {
    prev = prev->next;
    curr = curr->next->next;
  }
  prev->next = prev->next->next;

  return head;
}