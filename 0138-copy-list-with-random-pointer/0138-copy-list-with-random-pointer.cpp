/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// class Solution {
// public:
//     Node* copyRandomList(Node* head) {
//         Node *deepCopy = new Node(0);
//         Node *ptr1 = deepCopy;
//         Node *ptr = head;
//         map<int,Node*> Map;
//         map<int,Node*> copyMap;
//         // int i = 0;
//         while(ptr!=NULL){
//             Node *ptrr = new Node(ptr->val);
//             ptr1->next=ptrr;
//             ptr1=ptrr;
//             Map[ptrr->val] = ptr->random;
//             copyMap[ptrr->val] = ptrr;
//             ptr=ptr->next;
//         }
//         deepCopy = deepCopy->next;
//         ptr1 = deepCopy;
//         while(ptr1!=NULL){
//             auto x = Map[ptr1->val];
//             if (x!=NULL) ptr1->random=copyMap[x->val];
//             else ptr1->random=x;
//             ptr1 = ptr1->next;
//         }
//         return deepCopy;
//     }
// };

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> m;
        int i=0;
        Node* ptr = head;
        while (ptr) {
            m[ptr] =new Node(ptr->val);
            ptr = ptr->next;
        }
        ptr = head;
        while (ptr) {
            m[ptr]->next = m[ptr->next];
            m[ptr]->random = m[ptr->random];
            ptr = ptr->next;
        }
        return m[head];
    }
};