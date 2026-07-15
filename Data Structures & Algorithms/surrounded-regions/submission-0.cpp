class Solution {
    int row, col;
public:
    void solve(vector<vector<char>>& board) {
        row=board.size();
        col=board[0].size();
        for(int r=0; r<row; r++){
            if(board[r][0]=='O'){
                capture(board,r,0);
            }
            if(board[r][col-1]=='O'){
                capture(board,r,col-1);
            }
        }
        for(int c=0; c<col; c++){
            if(board[0][c]=='O'){
                capture(board,0,c);
            }
            if(board[row-1][c]=='O'){
                capture(board,row-1,c);
            }
        }
        for(int r=0;r<board.size(); r++){
            for(int c=0; c<board[0].size(); c++){
                if(board[r][c]=='O'){
                    board[r][c]='X';
                }
                if(board[r][c]=='T'){
                    board[r][c]='O';
                }
            }
        }
    }
    void capture(vector<vector<char>>& board, int r, int c){
        if(r<0 || r>= row || c<0 || c>=col || board[r][c]!='O' ){
            return;
        }
        board[r][c]='T';
        capture(board,r-1,c);
        capture(board,r+1,c);
        capture(board,r,c-1);
        capture(board,r,c+1);
    }
};
