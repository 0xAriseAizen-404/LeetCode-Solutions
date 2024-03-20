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
    public ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2) {
        ListNode temp = list2;
        while(temp!=null && temp.next != null)
            temp = temp.next;
        ListNode tailL = temp;
        
        
        ListNode deletePrev = list1;
        for(int i=0; deletePrev!=null && i<a-1; ++i)
            deletePrev = deletePrev.next;
        ListNode deleteNext = deletePrev.next;
        for(int i=0; deleteNext!=null && i<(b-a)+1; ++i)
            deleteNext = deleteNext.next;
        if(list2 == null) {
            deletePrev.next = deleteNext;
            return list1;
        }
        deletePrev.next = list2;
        tailL.next = deleteNext;
        return list1;
    }
    
}