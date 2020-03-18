/*
* 给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。
* 请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。
* 请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，
* 时间复杂度应为 O(nodes)，nodes 为节点总数。
*/

ListNode* OddEvenList(ListNode* head)
{
  if (head == NULL || head->next == NULL) {
    return head;
  }

  ListNode *odd_head = head;
  ListNode *even_head = head->next, *even_curr = even_head;
  ListNode *curr = even_head->next;
  if (curr == NULL) {
    return head;
  }
  int count = 3;  // 从第3个开始
  while (curr) {
    if (count % 2 == 1) {
      odd_head->next = curr;
      odd_head = curr;
    } else {
      even_curr->next = curr;
      even_curr = curr;
    }
    curr = curr->next;
    ++count;
  }
  even_curr->next = NULL;
  odd_head->next = even_head;

  return head;
}
