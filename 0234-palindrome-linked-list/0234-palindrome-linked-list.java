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
    public boolean isPalindrome(ListNode head) {
        if(head==null) return true;
        ListNode middle=middle(head);
        ListNode reverse=reverse(middle);
        while(reverse!=null){
            if(head.val!=reverse.val){
                return false;
            }
            head=head.next;
            reverse=reverse.next;
        }
        return true;
    }
    public ListNode middle(ListNode head){
        ListNode slow=head;
        ListNode fast=head;
        while(fast!=null && fast.next!=null){
            slow=slow.next;
            fast=fast.next.next;
        }
        return slow;
    }
    public ListNode reverse(ListNode head){
        ListNode prev=null;
        ListNode current=head;
        ListNode end=null;
        while(current!=null){
            end=current.next;
            current.next=prev;
            prev=current;
            current=end;
        }
        return prev;
    }
}