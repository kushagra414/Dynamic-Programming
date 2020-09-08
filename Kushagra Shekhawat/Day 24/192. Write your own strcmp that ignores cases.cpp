#include<bits/stdc++.h>
using namespace std;

int strcmp(string b1, string b2);

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    string b1,b2;
	    cin>>b1>>b2;
	    cout<<strcmp(b1,b2)<<endl;
	}
	return 0;
}

int strcmp(string str1, string str2){
    int i=0;
    for(i=0; str1[i] and str2[i];i++){
        if(str1[i]==str2[i] or (str1[i]^32) == str2[i])
            continue;
        else
            break;
    }
    if(str1[i]==str2[i])
        return 0;
    //below line of code is used to covert both the characters to lower case character and check which is bigger
    //eg:- converts A -> a
    if((str1[i] | 32) < (str2[i] | 32))
        return -1;
    return 1;
}