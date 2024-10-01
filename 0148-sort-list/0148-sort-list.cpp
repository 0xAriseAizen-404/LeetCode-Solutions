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
    ListNode* getMidOfTheList(ListNode* head) {
        ListNode* prev = nullptr;
        while (head && head->next) {
            prev = (prev == nullptr) ? head : prev->next;
            head = head->next->next;
        }
        ListNode* mid = prev->next;
        prev->next = nullptr;
        return mid;
    }
    
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while (left && right) {
            if (left->val < right->val) {
                curr->next = left;
                left = left->next;
            } else {
                curr->next = right;
                right = right->next;
            }
            curr = curr->next;
        }
        curr->next = left ? left : right;
        return dummy->next;
    }

public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* mid = getMidOfTheList(head);
        ListNode* leftList = sortList(head);
        ListNode* rightList = sortList(mid);
        return merge(leftList, rightList);
    }
};
