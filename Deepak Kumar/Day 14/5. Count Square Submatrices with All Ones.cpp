class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ans=0;
        int row=matrix.size();
        int col=matrix[0].size();
        if(row==0 || col==0){
            return 0;
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]>0 && i>0 && j>0){
                    matrix[i][j]=min(matrix[i-1][j-1],min(matrix[i][j-1],matrix[i-1][j]))+1;
                }
                ans+=matrix[i][j];
            }
        }
        return ans;
    }
};
