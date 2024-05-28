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
        ListNode head_node, * p = head, * q;//创建一个新链表
        head_node.next = nullptr;//初始化该链表头节点
        while (p) {//遍历原链表，每遍历一个节点就将该节点插到新链表的头部
            q = p->next;
            p->next = head_node.next;
            head_node.next = p;
            p = q;
        }
        return head_node.next;
    }
};