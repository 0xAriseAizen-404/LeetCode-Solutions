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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* current = head->next;
        ListNode* result = new ListNode(0);
        ListNode* resultTail = result;
        
        int sum = 0;
        while (current != nullptr) {
            if (current->val == 0) {
                if (sum != 0) {
                    resultTail->next = new ListNode(sum);
                    resultTail = resultTail->next;
                    sum = 0;
                }
            } else {
                sum += current->val;
            }
            current = current->next;
        }
        
        return result->next;
    }
};
