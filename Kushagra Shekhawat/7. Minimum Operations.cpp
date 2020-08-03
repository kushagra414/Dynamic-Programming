#include<iostream>
using namespace std;
int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N,num,steps = 0;
	    cin>>N;
	    num=N;
	    while(num>0){
	        if(num%2 == 0){
	            steps++;
	            num/=2;
	        }
	        else{
	            steps++;
	            num--;
	        }
	    }
	    cout<<steps<<endl;
	}
	return 0;
}