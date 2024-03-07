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
        vector<int>v;
        ListNode *temp=head;
        while(temp!=NULL){
            int y=temp->val;
            v.push_back(y);
            temp=temp->next;
        }
         int n = v.size();
        int i=0, j=n-1;
        temp = head;
        while (i < j) {
            temp->val = v[i];
            temp=temp->next;
            i++;
            temp->val=v[j];
            temp=temp->next;
            j--;
        }
        if (i==j) {
            temp->val=v[i];
        }
    }
};