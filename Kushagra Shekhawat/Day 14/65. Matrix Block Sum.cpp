class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int rowStart,colStart,rowEnd,colEnd;
        for(int i=0;i<mat.size();i++){
            for(int j=1;j<mat[i].size();j++){
                mat[i][j]+=mat[i][j-1];
            }
        }
        for(int i=1;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                mat[i][j]+=mat[i-1][j];
            }
        }
        vector<vector<int>> answer = mat;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                rowStart = i-K<0?0:i-K;
                colStart = j-K<0?0:j-K;
                rowEnd = i+K>mat.size()-1?mat.size()-1:i+K;
                colEnd = j+K>mat[i].size()-1?mat[i].size()-1:j+K;
                answer[i][j] = mat[rowEnd][colEnd];
                if(colStart>0)
                    answer[i][j] -= mat[rowEnd][colStart-1];
                if(rowStart>0)
                    answer[i][j] -= mat[rowStart-1][colEnd];
                if(rowStart>0 and colStart>0)
                    answer[i][j] += mat[rowStart-1][colStart-1];
            }
        }
        return answer;
    }
};