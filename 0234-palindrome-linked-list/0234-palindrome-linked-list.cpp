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
    public boolean isPalindrome(ListNode head) 
    {
        if (head == null || head.next == null) {
            return true; 
        }
        ListNode slow = head, fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode secondHalf = reverse(slow);
        
        ListNode firstHalf = head;
        while (secondHalf != null) {
            if (firstHalf.val != secondHalf.val) {
                return false; 
            }
            firstHalf = firstHalf.next;
            secondHalf = secondHalf.next;
        }
        
        return true; 
    }
    private ListNode reverse(ListNode head) {
        ListNode prev = null, current = head, nextNode;
        while (current != null) {
            nextNode = current.next;
            current.next = prev;
            prev = current;
            current = nextNode;
        }
        return prev;
    }
    // public boolean isPalindrome(ListNode head) {
    //     if(head==null || head.next==null) return true;
    //     ListNode r_head = null;
    //     ListNode ptr = head;
    //     while(ptr!=null) {
    //         ListNode temp = new ListNode(ptr.val);
    //         temp.next = r_head;
    //         r_head = temp;
    //         ptr = ptr.next;
    //     }
    //     while(head!=null && r_head!=null) {
    //         if(head.val != r_head.val) return false;
    //         head = head.next;
    //         r_head = r_head.next;
    //     }
    //     return true;
    // }
}