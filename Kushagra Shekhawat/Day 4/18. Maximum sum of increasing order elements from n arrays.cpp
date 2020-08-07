#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int rows,columns,sum=0,MaxElement;
	    bool elementNotFound;
	    cin>>rows>>columns;
	    int matrix[rows][columns],previousMaxElement = INT_MAX;
	    for(int i=0;i<rows;i++)
	        for(int j=0;j<columns;j++){
	            cin>>matrix[i][j];
	        }
	    for(int i=rows-1;i>=0;i--){
	        MaxElement = INT_MIN;
	        elementNotFound = true;
	        for(int j=0;j<columns;j++)
	            if(matrix[i][j]<previousMaxElement and MaxElement<matrix[i][j]){
	                MaxElement = matrix[i][j];
	                elementNotFound = false;
	            }
	        if(elementNotFound){
	            sum = 0;
	            break;
	        }
	        previousMaxElement = MaxElement;
	        sum += MaxElement;
	        }
	            
	    cout<<sum<<endl;
	}
	return 0;
}