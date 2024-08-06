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
        if(head==NULL)
            return head;
        ListNode* curr = head;
        ListNode* follow = NULL;
        ListNode* prev = NULL;
        while(curr != NULL) {
            follow = curr->next;
            curr->next = prev;
            prev = curr;
            curr = follow;
        }
        return prev;
    }
    ListNode* getMiddle(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* head1 = head;
        ListNode* head2 = getMiddle(head);
        head2 = reverseList(head2);
        while (head1 && head2) {
            if (head1->val != head2->val) return false;
            head1 = head1->next;
            head2 = head2->next;
        }
        return true;
    }
};