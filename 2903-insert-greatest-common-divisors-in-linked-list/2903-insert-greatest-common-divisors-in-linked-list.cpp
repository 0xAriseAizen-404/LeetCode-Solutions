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
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a%b);
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* slow = head;
        ListNode *fast = head->next;
        while (fast != nullptr) {
            ListNode* newNode = new ListNode(gcd(slow->val, fast->val));
            newNode->next = fast;
            slow->next = newNode;

            slow = fast;
            fast = fast->next;
        }
        return head;
    }
};