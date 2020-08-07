#include<iostream>
using namespace std;
int main()
 {
	int T;
	cin>>T;
	while(T--){
	    string brackets;
	    int countLeft=0,countRight=0,imbalance=0,swaps=0,N;
	    cin>>N>>brackets;
	    for(int i=0;i<brackets.length();i++){
	        if(brackets[i] == '['){
	            countRight++;
	            if(imbalance>0){
	                swaps+=imbalance;
	                imbalance--;
	            }
	        }else{
	            countLeft++;
	            imbalance = (countLeft-countRight);
	        }
	    }
	    cout<<swaps<<endl;
	}
	return 0;
}