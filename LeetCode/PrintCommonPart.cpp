/*
* 打印两个有序链表的公共部分
*/
/*
  struct Node {
    int value;
    Node *next;
    Node(int val) : value(val)
    { }
  };
*/

void PrintCommonPart(Node *head1, Node *head2)
{
  Node *curr1 = head1;
  Node *curr2 = head2;
  while (curr1 && curr2) {
    if (curr1->value < curr2->value) {
      curr1 = curr1->next;
    } else if (curr1->value > curr2->value) {
      curr2 = curr2->next;
    } else {
      std::cout << curr1->value << " ";
      curr1 = curr1->next;
      curr2 = curr2->next;
    }
  }
}