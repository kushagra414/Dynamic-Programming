#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int T;
	cin>>T;
	while(T--){
	    string num;
	    cin>>num;
	    int numInt = stoul(num,0,2);
	    int numLen = num.length(),ten = 10;
	    bitset<10> complement2s(-numInt);
	    for(int i=numLen-1;i>=0;i--)   
	        cout<<complement2s[i];
	    cout<<endl;
	}
	return 0;
}