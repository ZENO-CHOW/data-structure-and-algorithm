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
        ListNode head_node, * p, * q;//��������ͷ�ڵ�
        head_node.next = head;
        p = &head_node;
        q = &head_node;
        for (int i = 0; i <= n; i++) p = p->next;//�ÿ�ָ������n+1��
        while (p) {
            p = p->next;
            q = q->next;
        }
        p = q->next;//��ʱpָ��ָ������n+1���ڵ�
        q->next = q->next->next;
        delete p;
        return head_node.next;
    }
};