/*
* 给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
* 你应当保留两个分区中每个节点的初始相对位置。
*/

ListNode* partition(ListNode* head, int x)
{
    ListNode left_tmp(-1);
    ListNode right_tmp(-1);

    ListNode *l_curr = &left_tmp;
    ListNode *r_curr = &right_tmp;
    for (ListNode *curr = head; curr != nullptr; curr = curr->next) {
        if (curr->val < x) {
            l_curr->next = curr;
            l_curr = curr;
        } else {
            r_curr->next = curr;
            r_curr = curr;
        }
    }
    l_curr->next = right_tmp.next;
    r_curr->next = nullptr;

    return left_tmp.next;
}