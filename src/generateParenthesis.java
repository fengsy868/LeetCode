public class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> res = new ArrayList<String>();
        if(n==0){
          res.add("");
        }
          else {
              for(int i=n-1;i>=0;i--){
                  List<String> insert=generateParenthesis(i);
                  List<String> tail=generateParenthesis(n-1-i);
                  for(String s : insert){
                      for(String t: tail){
                          res.add("("+s+")"+t);
                      }
                  }
              }
          }
      return res;
    }
}
