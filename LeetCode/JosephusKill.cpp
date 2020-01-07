/*
* 环形单链表的约瑟夫问题
* 输入：一个环形单向链表的头结点head和报数的值m
* 返回：最后一个生存下来的节点，且这个节点自己组成环形单向链表，其他节点都删掉
* 进阶问题：如果链表节点数为N，在时间复杂度为O(N)时完成原问题的要求
*/

// 时间复杂度O(n*m)
Node* JosephusKill(Node *head, int m)
{
  if (!head || head->next == head || m < 1) {
    return head;
  }

  Node *last = head;
  while (last->next != head) {
    last = last->next;
  }

  Node *curr = head;
  int cnt = 0;
  Node *prev = last;
  while (curr->next != curr) {
    ++cnt;
    if (cnt == m) {
      prev->next = curr->next;
      cnt = 0;
    } else {
      prev = curr;
    }
    curr = curr->next;
  }
  return curr;
}

// 进阶解法：直接计算出最终存活的节点
int GetLive(int len, int m)
{
  if (len == 1) {
    return 1;
  }
  return (GetLive(len - 1, m) + m - 1) % len + 1;
}

Node* JosephusKill(Node *head, int m)
{
  if (!head || head->next = head || m < 1) {
    return head;
  }

  Node *curr = head;
  int len = 1;
  while (curr->next != head) {
    ++len;
    curr = curr->next;
  }

  int live_pos = GetLive(len, m);
  while (--live_pos != 0) {
    head = head->next;
  }
  head->next = head;
  return head;
}