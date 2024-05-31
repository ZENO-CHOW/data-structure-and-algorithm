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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (right == 1) return head;
        right -= 1;
        if (left == 1) {
            ListNode* head_new = reverseBetween(head->next, left, right), * rear;
            rear = head->next;
            head->next = rear->next;
            rear->next = head;
            return head_new;
        }
        head->next = reverseBetween(head->next, left - 1, right);
        return head;
    }
};