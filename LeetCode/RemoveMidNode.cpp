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

// 进阶，找到需要删除的节点位置
// 假设链表长度为n，则要删除的节点为a*n/b，结果向上取整
Node* RemoveMidNode(Node *head, int a, int b)
{
  if (a < 1 || a > b) {
    return head;
  }
  int len = 0;
  Node *curr = head;
  while (curr) {
    ++len;
    curr = curr->next;
  }
  int pos = ceil((double)(a * n) / b);
  if (pos == 1) {
    return head->next;
  } else if (pos > 1) {
    curr = head;
    while (--pos != 1) {
      curr = curr->next;
    }
    curr->next = curr->next->next;
  }
  return head;
}