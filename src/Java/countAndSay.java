public class Solution {
    public String countAndSay(int n) {
        LinkedList<Integer> queue=new LinkedList<Integer>();
        queue.add(1);
        for(int i=1;i<n;i++){
            queue=newNumber(queue);
        }
        StringBuilder sb=new StringBuilder();
        for(int i : queue){
            sb.append(i);
        }
        return sb.toString();
    }
    
    private LinkedList<Integer> newNumber(LinkedList<Integer> queue){
        LinkedList<Integer> newQueue=new LinkedList<Integer>();
        while(queue.peek()!=null){
           int n=1;
           int value = queue.poll();
           while(queue.peek()!=null && queue.peek()==value) {
               n++;
               queue.remove();
           }
           newQueue.add(n);
           newQueue.add(value);
        }
        return newQueue;
    }
}