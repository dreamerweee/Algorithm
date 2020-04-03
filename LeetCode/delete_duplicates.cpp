/* 
 给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。
*/

ListNode* deleteDuplicates(ListNode* head)
{
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode tmp(-1);
    ListNode *tmp_curr;
    ListNode *prev = head;
    ListNode *curr = head->next;
    int count = 1;
    while (curr) {
        if (curr->val == prev->val) {
            ++count;
            delete prev;
        } else {
            if (count == 1) {
                if (tmp.next == nullptr) {
                    tmp.next = prev;
                    tmp_curr = prev;
                } else {
                    tmp_curr->next = prev;
                    tmp_curr = tmp_curr->next;
                }
            } else {
                count = 1;
                delete prev;
            }
        }
        prev = curr;
        curr = curr->next;
    }
    if (count == 1) {
        if (tmp.next == nullptr) {
            tmp.next = prev;
            tmp_curr = prev;
        } else {
            tmp_curr->next = prev;
            tmp_curr = tmp_curr->next;
        }
    }
    tmp_curr->next = nullptr;
    return tmp.next;
}
