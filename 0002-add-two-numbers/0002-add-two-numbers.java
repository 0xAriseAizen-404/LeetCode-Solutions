/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode head = new ListNode(0);
        ListNode temp = head;
        int summ = 0;
        int carry = 0;
        while(l1!=null && l2!=null) {
            summ = l1.val + l2.val;
            if(carry != 0) {
                summ += carry;
                carry = 0;
            }
            if(summ >= 10) {
                carry = summ / 10;
                summ = summ % 10;
            }
            temp.next = new ListNode(summ);
            temp = temp.next;
            l1 = l1.next;
            l2 = l2.next;
        }
        while(l1 != null) {
            summ = l1.val;
            if(carry != 0) {
                summ += carry;
                carry = 0;
            }
            if(summ >= 10) {
                carry = summ / 10;
                summ = summ % 10;
            }
            temp.next = new ListNode(summ);
            temp = temp.next;
            l1 = l1.next;
        }
        while(l2 != null) {
            summ = l2.val;
            if(carry != 0) {
                summ += carry;
                carry = 0;
            }
            if(summ >= 10) {
                carry = summ / 10;
                summ = summ % 10;
            }
            temp.next = new ListNode(summ);
            temp = temp.next;
            l2 = l2.next;
        }
        if(carry != 0) {
            temp.next = new ListNode(carry);
        }
        return head.next;
    }
}