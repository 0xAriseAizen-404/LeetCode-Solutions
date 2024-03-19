class Solution {
    private ListNode reverseList(ListNode head) {
        if (head == null) {
            return null;
        }
        ListNode prev = null;
        ListNode current = head;
        while (current != null) {
            ListNode follow = current.next;
            current.next = prev;
            prev = current;
            current = follow;
        }
        return prev;
    }

    private static ListNode getTail(ListNode temp, int k) {
        for (int i = 0; temp!=null & i<k-1; ++i)
            temp = temp.next;
        return temp;
    }

    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode prevLast = dummy;

        while (head != null) {
            ListNode tail = getTail(head, k);
            if (tail == null) {
                break;
            }
            ListNode nextGroup = tail.next;
            tail.next = null;
            prevLast.next = reverseList(head);
            prevLast = head;
            head.next = nextGroup;
            head = nextGroup;
        }

        return dummy.next;
    }
}
