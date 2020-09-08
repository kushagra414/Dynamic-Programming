#include<bits/stdc++.h>
using namespace std;

string findBitSum(char b1,char b2,char carry);
string add(string b1, string b2);

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    string b1,b2;
	    cin>>b1>>b2;
	    cout<<add(b1,b2)<<endl;
	}
	return 0;
}

string add(string b1, string b2){
    reverse(b1.begin(),b1.end());
    reverse(b2.begin(),b2.end());
    int n1=b1.length(),n2=b2.length();
    string sum,res="";
    char carry = '0';
    if(n2>n1){
        swap(b1,b2);
        swap(n1,n2);
    }
    for(int i=0,j=0;i<n1;i++,j++){
        if(j<n2){
            sum = findBitSum(b1[i],b2[j],carry);
            res+=sum[1];
            carry = sum[0];
        }else{
            sum = findBitSum(b1[i],carry,'0');
            res+=sum[1];
            carry = sum[0];
        }
    }
    if(carry=='1')
        res+='1';
    reverse(res.begin(),res.end());
    return res;
}

string findBitSum(char b1,char b2,char carry){
    int zero = '0';
    int sum = b1+b2+carry-3*zero;
    if(sum==0)
        return "00";
    else if(sum==1)
        return "01";
    else if(sum==2)
        return "10";
    else if(sum==3)
        return "11";
    
}