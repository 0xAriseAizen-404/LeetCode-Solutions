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
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* prev = nullptr;
        ListNode* current = head;
        while (current != nullptr) {
            ListNode* follow = current->next;
            current->next = prev;
            prev = current;
            current = follow;
        }
        return prev;
    }

    static ListNode* getTail(ListNode* temp, int k) {
        for (int i = 0; temp != nullptr && i < k - 1; ++i) {
            temp = temp->next;
        }
        return temp;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prevLast = dummy;

        while (head != nullptr) {
            ListNode* tail = getTail(head, k);
            if (tail == nullptr) {
                break;
            }
            ListNode* nextGroup = tail->next;
            tail->next = nullptr;
            prevLast->next = reverseList(head);
            prevLast = head;
            head->next = nextGroup;
            head = nextGroup;
        }

        return dummy->next;
    }
};
