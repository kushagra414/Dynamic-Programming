#include <iostream>
using namespace std;
int mat[9][9];

bool is_safe(int mat[9][9],int row,int col,int num,int N){
    for(int i=0;i<N;i++){
        if(mat[row][i]==num){
            return false;
        }
    }
    
    for(int i=0;i<N;i++){
        if(mat[i][col]==num){
            return false;
        }
    }
    
    int row_start=row-row%3;
    int col_start=col-col%3;
    for(int i=row_start;i<row_start+3;i++){
        for(int j=col_start;j<col_start+3;j++){
            if(mat[i][j]==num){
                return false;
            }
        }
    }
    
    return true;
}

bool solution(int mat[9][9],int N){
    int row=-1,col=-1;
    bool is_empty=true;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(mat[i][j]==0){
                row=i;
                col=j;
                is_empty=false;
                break;
            }
        }
        if(is_empty==false){
            break;
        }
    }
    
    if(is_empty==true){
        return true;
    }
    
    for(int num=1;num<=N;num++){
        if(is_safe(mat,row,col,num,N)){
            mat[row][col]=num;
            if(solution(mat,N)){
                return true;
            }
            else{
                mat[row][col]=0;
            }
        }
    }
    return false;
}

void print_sudoku(int mat[9][9]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<mat[i][j]<<" ";
        }
    }
    cout<<endl;
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    for(int i=0;i<9;i++){
	        for(int j=0;j<9;j++){
	            cin>>mat[i][j];
	        }
	    }
	    solution(mat,9);
        print_sudoku(mat);
	}
	return 0;
}
