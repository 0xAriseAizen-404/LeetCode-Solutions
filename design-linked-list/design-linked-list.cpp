class MyLinkedList {
private:
    int size;
    ListNode* dummy;

public:
    MyLinkedList() {
        dummy = new ListNode(-1);
        size = 0;
    }

    int get(int index) {
        if (index >= size) {
            return -1;
        }

        ListNode* cur = dummy;
        for (int i = 0; i <= index; i++) {
            cur = cur->next;
        }
        return cur->val;
    }

    void addAtHead(int val) {
        ListNode* node = new ListNode(val);
        node->next = dummy->next;
        dummy->next = node;
        size++;
    }

    void addAtTail(int val) {
        ListNode* node = new ListNode(val);
        ListNode* cur = dummy;
        for (int i = 0; i < size; i++) {
            cur = cur->next;
        }
        cur->next = node;
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index > size) return;

        ListNode* node = new ListNode(val);
        ListNode* cur = dummy;

        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
        node->next = cur->next;
        cur->next = node;
        size++;
    }

    void deleteAtIndex(int index) {
        if (index >= size) return;

        ListNode* cur = dummy;

        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
        cur->next = cur->next->next;
        size--;
    }
};
