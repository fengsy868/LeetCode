public class Solution {
    public boolean isValidSudoku(char[][] board) {
        for(int i=0;i<9;i++){
            if(!partValid(board,i,0,i,8)) return false;
            if(!partValid(board,0,i,8,i)) return false;
        }
        for (int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if (!partValid(board,i*3,j*3,i*3+2,j*3+2)) return false;
            }
        }
        return true;
    }
    
    private boolean partValid(char[][] board,int x1,int y1,int x2,int y2){
        Set valid=new HashSet();
        for(int i=x1;i<=x2;i++){
             for(int j=y1;j<=y2;j++){
                 if(board[i][j]!='.'){
                     if(!valid.add(board[i][j]))
                        return false;
                 }
             }
        }
        return true;
    }
}