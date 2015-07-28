public class Solution {
	// used linkedList
    public List<String> letterCombinations(String digits) {
        LinkedList<String> result=new LinkedList<String>();
        String[] pNumber= new String[]{"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        if(digits.equals("")){
            return result;
        }
        result.add("");
        for(int i=0;i<digits.length();i++){
            int x = Character.getNumericValue(digits.charAt(i));
            while(result.peek().length()==i){
                String s=result.remove();
                for(char c:pNumber[x].toCharArray()){
                    result.add(s+c);
                }
            }
        }
        return result;
    }
}