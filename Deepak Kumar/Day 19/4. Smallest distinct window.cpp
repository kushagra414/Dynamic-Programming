#include <bits/stdc++.h>
using namespace std;

long long solution(string str,long long N){
    unordered_map<char,long long> mp;
    for(long long i=0;i<N;i++){
        mp[str[i]]++;
    }
    long long dis_count=mp.size();
    long long count=0,start=0,min_len=INT_MAX;
    unordered_map<char,long long> temp;
    for(long long i=0;i<N;i++){
        temp[str[i]]++;
        if(temp[str[i]]==1){
            count++;
        }
        if(count==dis_count){
            while(temp[str[start]]>1){
                if(temp[str[start]]>1){
                    temp[str[start]]--;
                }
                start++;
            }
            min_len=min(min_len,i-start+1);
        }
    }
    return min_len;
}

int main() {
    int T;
    cin>>T;
    while(T--){
        string str;
        cin>>str;
        long long N=str.length();
        cout<<solution(str,N)<<endl;
    }
	return 0;
}
