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
private:
    ListNode* findMiddle(ListNode* head) {
        ListNode* prev = nullptr;
        while (head && head->next) {
            prev = (prev == nullptr) ? head->next : prev->next;
            head = head->next->next;
        }
        return prev;
    }
    
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        ListNode* mid = findMiddle(head);
        ListNode* second = reverse(mid->next);
        ListNode* first = head;
        mid->next = nullptr;
        while (second) {
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;
            first->next = second;
            second->next = tmp1;
            first = tmp1;
            second = tmp2;
        }
    }
};