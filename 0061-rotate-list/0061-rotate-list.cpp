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
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || !head || !head->next) return head;
        int len = 1;
        ListNode* curr = head;
        while (curr->next) {
            len += 1;
            curr = curr->next;
        }
        k = len - (k % len);
        curr->next = head;
        while (k-- > 0) curr = curr->next;
        head = curr->next;
        curr->next = nullptr;
        return head;
    }
};