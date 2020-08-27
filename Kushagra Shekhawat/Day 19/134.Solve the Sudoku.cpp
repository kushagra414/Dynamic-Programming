#include<bits/stdc++.h>
using namespace std;
#define size 9

bool solveSudoku(int sudoku[size][size]);
bool findEmptyCell(int sudoku[size][size],int &row,int &col);
bool isCorrect(int sudoku[size][size],int row,int col,int val);
bool isCorrectRow(int sudoku[size][size],int row,int val);
bool isCorrectCol(int sudoku[size][size],int col,int val);
bool isCorrectBox(int sudoku[size][size],int row,int col,int val);

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int sudoku[size][size];
	    for(int i=0;i<size;i++)
	        for(int j=0;j<size;j++)
	            cin>>sudoku[i][j];
	    
	    solveSudoku(sudoku);
	    for(int i=0;i<size;i++)
	        for(int j=0;j<size;j++)
	            cout<<sudoku[i][j]<<" ";
	    cout<<endl;
	}
	return 0;
}

bool solveSudoku(int sudoku[size][size]){
    int row,col;
    
    if(!findEmptyCell(sudoku,row,col))
        return true;
    for(int i=1;i<=size;i++){
        if(isCorrect(sudoku,row,col,i)){
            sudoku[row][col] = i;
            
        if(solveSudoku(sudoku))
            return true;
            
        sudoku[row][col] = 0;
        }
    }
    return false;
}

bool findEmptyCell(int sudoku[size][size],int &row,int &col){
    
    for(row=0;row<size;row++)
        for(col=0;col<size;col++)
            if(sudoku[row][col]==0)
                return true;
    return false;
}

bool isCorrect(int sudoku[size][size],int row,int col,int val){
    return isCorrectRow(sudoku,row,val) and 
    isCorrectCol(sudoku,col,val) and 
    isCorrectBox(sudoku,row-row%3,col-col%3,val);
}

bool isCorrectRow(int sudoku[size][size],int row,int val){
    for(int col=0;col<size;col++)
        if(sudoku[row][col]==val)
            return false;
    return true;
}
bool isCorrectCol(int sudoku[size][size],int col,int val){
    for(int row=0;row<size;row++)
        if(sudoku[row][col]==val)
            return false;
    return true;
}
bool isCorrectBox(int sudoku[size][size],int row,int col,int val){
    for(int i=row;i<3+row;i++)
        for(int j=col;j<3+col;j++)
            if(sudoku[i][j]==val)
                return false;
    return true;
}
