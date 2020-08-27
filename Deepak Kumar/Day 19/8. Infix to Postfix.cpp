#include <bits/stdc++.h>
using namespace std;

int prec(char c){
    if(c=='^'){
        return 3;
    }
    else if(c =='*'||c=='/'){
        return 2;
    }
    else if(c=='+'||c=='-'){
        return 1;
    }
    else{
        return 0;
    }
}

string solution(string str,int N){
    string s="";
    stack<char> st;
    for(int i=0;i<N;i++){
        if((str[i]>='a' && str[i]<='z')||(str[i]>='A' && str[i]<='Z')){
            s+=str[i];
        }
        else if(str[i]=='('){
            st.push('(');
        }
        else if(str[i]==')'){
            while(st.top()!='(' && !st.empty()){
                char ch=st.top();
                s+=ch;
                st.pop();
            }
            if(st.top()=='(' && !st.empty()){
                st.pop();
            }
        }
        else{
            while(!st.empty() && prec(str[i])<=prec(st.top())){
                char ch=st.top();
                s+=ch;
                st.pop();
            }
            st.push(str[i]);
        }
    }
    while(!st.empty()){
        char ch=st.top();
        s+=ch;
        st.pop();
    }
    return s;
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    string str;
	    cin>>str;
	    int N=str.length();
	    cout<<solution(str,N)<<endl;
	}
	return 0;
}
