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
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        while (head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    ListNode* getKthNode(ListNode* temp, int k) {
        for (int i=0; temp != nullptr && i < k - 1; ++i) {
            temp = temp->next;
        }
        return temp;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* curr = dummy;
        while (head) {
            ListNode* kthNode = getKthNode(head, k);
            if (!kthNode) break;
            ListNode* nextGroup = kthNode->next;
            kthNode->next = nullptr;
            curr->next = reverseList(head);
            curr = head; // head is the tail after reverse for any group cause we using head even below look
            curr->next = nextGroup;
            head = nextGroup; // head is gonna be tail for reverse of this group
        }
        return dummy->next;
    }
};