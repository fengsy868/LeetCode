public class Solution {
    public int lengthOfLastWord(String s) {
        int n=0;
        boolean espace=false;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)==' '){
                if(!espace)
                    espace=true;
                continue;
            }
            if(espace){
                n=0;
                espace=false;
            }
            n++;
        }
        return n;
    }
}