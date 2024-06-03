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
        ListNode head_node, * p = head, * q;//����һ��������
        head_node.next = nullptr;//��ʼ��������ͷ�ڵ�
        while (p) {//����ԭ����ÿ����һ���ڵ�ͽ��ýڵ�嵽�������ͷ��
            q = p->next;
            p->next = head_node.next;
            head_node.next = p;
            p = q;
        }
        return head_node.next;
    }
};