#include<iostream>
using namespace std;
int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int sumOfDigits,totalDigits,j=0;
	    string num = "";
	    bool notFound;
	    cin>>sumOfDigits;
	    cin>>totalDigits;
	    for(int i=0;i<totalDigits;i++){
	        notFound = true;
	        if(i==0)
	            j=1;
	        else
	            j=0;
	        for(;j<10;j++){
	            if(j+9*(totalDigits-i-1)>=sumOfDigits){
	                sumOfDigits-=j;
	                num+=to_string(j);
	                notFound = false;
	                break;
	            }
	        }
	        if(notFound){
	                break;
	            }
	    }
	    if(notFound)
	        cout<<-1<<endl;
	    else
	        cout<<num<<endl;
	}
	return 0;
}