/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode head_node, * p, * q;//创建虚拟头节点
        head_node.next = head;
        p = &head_node;
        q = &head_node;
        for (int i = 0; i <= n; i++) p = p->next;//让快指针先走n+1步
        while (p) {
            p = p->next;
            q = q->next;
        }
        p = q->next;//此时p指针指向倒数第n+1个节点
        q->next = q->next->next;
        delete p;
        return head_node.next;
    }
};