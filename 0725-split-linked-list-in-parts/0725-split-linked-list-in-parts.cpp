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
    int getListLength(ListNode* temp) {
        int cnt = 0;
        while(temp) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int list_length = getListLength(head);
        vector<ListNode*> ans;
        if(!head) {
            while(k--) ans.push_back(nullptr);
        }
        int values = list_length / int(k);
        int carry = list_length % k;
        if(values == 0) {
            carry = 0;
            values = 1;
        }
        while(head) {
            ListNode* temp = head;
            for(int i=0;i<values-1;++i) temp = temp->next;
            if(carry>0) {
                temp=temp->next;
                carry--;
            }
            ans.push_back(head);
            k--;
            if(temp) {
                head = temp->next;
                temp->next = nullptr;
            } 
            if(!head || !temp) {
                while(k--) ans.push_back(nullptr);
                head = nullptr;
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<ListNode*> splitListToParts(ListNode* head, int k) {
//         int len=0;
//         ListNode*temp=head;
//         while(temp!=NULL){
//             len++;
//             temp=temp->next;
//         }
//         vector<ListNode*>v(k,NULL);
//         int p=len/k;
//         int extra=len%k;
//         temp=head;
//         int j=0;
//         while(temp!=NULL){
//             ListNode*c=temp;
//             ListNode*dummy=new ListNode(-1);
//             ListNode*curr=dummy;
//             for(int i=0;i<p;i++){
//                 curr->next=new ListNode(temp->val);
//                 temp=temp->next;
//                 curr=curr->next;
//             }
//             if(extra>0){
//                 curr->next=new ListNode(temp->val);
//                 temp=temp->next;
//                 curr=curr->next;
//                 extra--;
//             }
//             v[j]=dummy->next;
//             j++;
//         }
//         return v;
//     }
// };