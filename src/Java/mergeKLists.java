/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists==null||lists.length==0) return null;
        
        PriorityQueue<ListNode> pq=new PriorityQueue<ListNode>(lists.length,new Comparator<ListNode>(){
    @Override
    public int compare(ListNode a, ListNode b) {
        if(a.val<b.val)
            return -1;
        else if(a.val==b.val)
            return 0;
        else return 1;
    }
});
        for(ListNode l:lists){
            if(l!=null)
                pq.add(l);
        }
        ListNode start=new ListNode(0);
        ListNode current=start;
        while(!pq.isEmpty()){
            current.next=pq.poll();
            current=current.next;
            if(current.next!=null)
                pq.add(current.next);
        }
        
        return start.next;
    }
}