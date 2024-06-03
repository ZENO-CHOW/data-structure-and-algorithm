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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;//�߽�������������򵥽ڵ�����
        ListNode* new_head = reverseList(head->next);//������һ�ڵ�������ķ�ת����ͷָ��
        ListNode* rear = head->next;//����ǰ�ڵ���뵽��ת�����β��
        rear->next = head;
        head->next = nullptr;
        return new_head;//���ط�ת����ͷָ��
    }
};