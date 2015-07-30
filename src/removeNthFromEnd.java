/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode start=new ListNode(0);
        ListNode first=start,last=start;
        last.next=head;
        for(int i=0;i<=n;i++){
            last=last.next;
        }
        while(last!=null){
            first=first.next;
            last=last.next;
        }
        first.next=first.next.next;
        return start.next;
    }
}
