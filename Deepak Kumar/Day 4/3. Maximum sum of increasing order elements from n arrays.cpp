#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int no_of_row=0,no_of_column=0;
	    cin>>no_of_row>>no_of_column;
	    int A[no_of_row][no_of_column];
	    for(int i=0;i<no_of_row;i++){
	        for(int j=0;j<no_of_column;j++){
	            cin>>A[i][j];
	        }
	    }
	    for(int i=0;i<no_of_row;i++){
            sort(A[i],A[i]+no_of_column);
        }
        int i=0,j=0;
        int flag=1;
        int pre_maximum=A[no_of_row-1][no_of_column-1];
        int sum=A[no_of_row-1][no_of_column-1];
        for(i=no_of_row-2;i>=0;i--){
            for(j=no_of_column-1;j>=0;j--){
                if(A[i][j]<pre_maximum){
                    sum=sum+A[i][j];
                    pre_maximum=A[i][j];
                    break;
                }
            }
            if(j<0){
                flag=0;
                break;
            }
        }
        if(flag==0){
            cout<<"0"<<endl;
        }
        else{
            cout<<sum<<endl;
        }
	}
	return 0;
}
