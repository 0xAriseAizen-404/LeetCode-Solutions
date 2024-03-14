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
    ListNode* addNode(ListNode* &x,int ele){
        ListNode* neww = new ListNode(ele);
        if (x==NULL) x = neww;
        else{
            ListNode *t=x;
            while(t->next!=NULL) t = t->next;
            t->next = neww;
        }
        return x;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int left=0,sum;
        ListNode *t,*head=NULL,*neww;
        while(l1!=NULL && l2!=NULL){
            sum = l1->val+l2->val+left;
            left = sum/10;
            head = addNode(head,sum%10);
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1!=NULL){
            sum = l1->val + left;
            left = sum/10;
            head = addNode(head,sum%10);
            l1 = l1->next;
        }
        while(l2!=NULL){
            sum = l2->val + left;
            left = sum/10;
            head = addNode(head,sum%10);
            l2 = l2->next;
        }
        if(left>0) head = addNode(head,left);
        return head;
    }
};