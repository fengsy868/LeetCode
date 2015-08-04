public class Solution {
    public boolean containsDuplicate(int[] nums) {
        if(nums.length == 0)
            return false;
        Set<Integer> number=new HashSet<Integer>();
        for(int n : nums){
            if(!number.add(n))
                return true;
        }
        return false;
    }
}