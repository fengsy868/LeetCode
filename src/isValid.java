public class Solution {
    public boolean isValid(String s) {
        Stack stack=new Stack();
        for(int i=0;i<s.length();i++){
            if(stack.empty()){
                stack.push(s.charAt(i));
                continue;
            }
            char first= (char)stack.peek();
            char current=s.charAt(i);
            if( (current=='('&& first==')' ) ||  (current==')'&& first=='(') ||
                 (current=='['&& first==']' )||  (current==']'&& first=='[') ||
                  (current=='{'&& first=='}') ||  (current=='}'&& first=='{' ) )
                    stack.pop();
            else
                stack.push(current);
        }
        return stack.empty();
    }
}
