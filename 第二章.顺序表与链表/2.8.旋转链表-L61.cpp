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
    int Get_Len(ListNode* p) {
        int len = 0;
        while (p) {
            p = p->next;
            len++;
        }
        return len;
    }

    int Getnum(int k, int len) {
        k %= len;

        return k;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return head;
        ListNode* p = head, * q;
        int len, j;
        len = Get_Len(p);
        k %= len;
        if (k == 0) return head;
        for (int i = 1; i < (len - k); i++) p = p->next;
        q = p->next;
        for (int m = 1; m < k; m++) q = q->next;
        q->next = head;
        head = p->next;
        p->next = nullptr;

        return head;
    }
};