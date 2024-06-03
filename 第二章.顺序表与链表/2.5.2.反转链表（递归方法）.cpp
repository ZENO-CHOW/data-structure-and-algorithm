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
        if (head == nullptr || head->next == nullptr) return head;//边界条件：空链表或单节点链表
        ListNode* new_head = reverseList(head->next);//返回下一节点后的链表的反转链表头指针
        ListNode* rear = head->next;//将当前节点插入到反转链表的尾部
        rear->next = head;
        head->next = nullptr;
        return new_head;//返回反转链表头指针
    }
};