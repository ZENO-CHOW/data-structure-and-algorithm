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
    ListNode* reverse(ListNode* head, int num) {
        ListNode head_node_new, * p = head, * q;
        head_node_new.next = nullptr;
        for (int i = 0; i < num; i++) {
            q = p->next;
            p->next = head_node_new.next;
            head_node_new.next = p;
            p = q;
        }
        q = &head_node_new;
        for (int j = 0; j < num; j++) q = q->next;
        q->next = p;
        return head_node_new.next;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (right == 1) return head;
        int num = right - left + 1;
        ListNode head_node;
        head_node.next = head;
        ListNode* p = &head_node;
        for (int i = 0; i < left - 1; i++) p = p->next;
        p->next = reverse(p->next, num);
        return head_node.next;
    }
};