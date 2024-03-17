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
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return;
        }

        // Step 1: Find the middle of the list
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half of the list
        ListNode *prev = nullptr;
        ListNode *curr = slow->next;
        slow->next = nullptr;

        while (curr) {
            ListNode *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // Step 3: Merge the first half and the reversed second half
        ListNode *first = head;
        ListNode *second = prev;

        while (second) {
            ListNode *nextFirst = first->next;
            ListNode *nextSecond = second->next;
            first->next = second;
            second->next = nextFirst;
            first = nextFirst;
            second = nextSecond;
        }
        // vector<int>v;
        // ListNode *temp=head;
        // while(temp!=NULL){
        //     int y=temp->val;
        //     v.push_back(y);
        //     temp=temp->next;
        // }
        //  int n = v.size();
        // int i=0, j=n-1;
        // temp = head;
        // while (i < j) {
        //     temp->val = v[i];
        //     temp=temp->next;
        //     i++;
        //     temp->val=v[j];
        //     temp=temp->next;
        //     j--;
        // }
        // if (i==j) {
        //     temp->val=v[i];
        // }
    }
};