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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp = list2;
        while (temp != nullptr && temp->next != nullptr) {
            temp = temp->next;
        }
        ListNode* tailL = temp;
        ListNode* deletePrev = list1;
        for (int i = 0; deletePrev != nullptr && i < a - 1; ++i) {
            deletePrev = deletePrev->next;
        }
        if (deletePrev == nullptr || deletePrev->next == nullptr) {
            return list1;
        }
        ListNode* deleteNext = deletePrev->next;
        for (int i = 0; deleteNext != nullptr && i < (b - a) + 1; ++i) {
            deleteNext = deleteNext->next;
        }
        if (deleteNext == nullptr) {
            return list1;
        }
        deletePrev->next = list2;
        tailL->next = deleteNext;
        return list1;
    }
};
