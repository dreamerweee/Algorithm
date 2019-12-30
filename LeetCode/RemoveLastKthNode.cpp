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

SingleNode *RemoveLastKthNode(SingleNode *head, int k)
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