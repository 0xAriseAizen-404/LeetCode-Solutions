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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0); // Create a dummy node
        ListNode* curr = dummy; // Current pointer to traverse
        // Merge the two lists
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        // Append the remaining nodes from the non-empty list
        if (list1 != nullptr) {
            curr->next = list1;
        } else {
            curr->next = list2;
        }
        return dummy->next; // Return the head of the merged list
    }
};