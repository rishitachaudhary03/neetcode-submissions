class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh=0;
        int time=0;
        queue <pair<int,int>> q;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==1){
                    fresh++;
                }
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        vector<vector <int>> dir ={{-1,0},{1,0},{0,-1},{0,1}};
        while(fresh !=0 && !q.empty()){
            int length=q.size();
            for(int i=0; i<length; i++){
                int r = q.front().first;
                int c=q.front().second;
                q.pop();
            for(int i =0 ; i<4; i++){
                int row=r +dir[i][0];
                int col=c+dir[i][1];
                if(row>=0 && row<grid.size() && 
                col>=0 && col<grid[0].size() && grid[row][col]==1){
                    grid[row][col]=2;
                    q.push({row,col});
                    fresh--;
                }
            }
            }
            time++;
        }
        return fresh==0 ? time:-1;
    }
};
