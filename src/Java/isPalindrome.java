/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
   public boolean isPalindrome(ListNode head) {
    if(head==null || head.next== null){
        return true;
    }
    
    ListNode fast=head;
    ListNode slow=head;
    while(fast.next != null && fast.next.next != null){
        fast=fast.next.next;
        slow=slow.next;
    }
    
    ListNode mid=slow.next;
     ListNode newList = reverse(mid);
    ListNode pointer = head;
    while(newList != null){
        if(pointer.val != newList.val)
            return false;
        pointer = pointer.next;
        newList = newList.next;
    }
    return true;
   }
   
   public ListNode reverse(ListNode head){
    if(head == null || head.next == null)
        return head;
    ListNode pre=head;
    ListNode cur=head.next;
    head.next=null;
    while(cur!=null){
        ListNode temp=cur.next;
        cur.next=pre;
        pre=cur;
        cur=temp;
    }
    
    return pre;
   }
}