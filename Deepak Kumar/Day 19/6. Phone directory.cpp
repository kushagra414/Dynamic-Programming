#include <bits/stdc++.h>
using namespace std;

struct trie{
    struct trie* child[26];
    bool end;
    
    trie(){
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
        end=false;
    }
};

void insert(trie* root,string key){
    trie* temp=root;
    for(int i=0;i<key.length();i++){
        int index=key[i]-'a';
        if(temp->child[index]==NULL){
            temp->child[index]=new trie;
        }
        temp=temp->child[index];
    }
    temp->end=true;
}

void print(trie *root,string val,int &count){
    if(root==NULL){
        return;
    }
    else if(root->end){
        count++;
        cout<<val<<" ";
    }
    for(int i=0;i<26;i++){
        print(root->child[i],val+(char)('a'+i),count);
    }
}

void display(trie* root,string val,int &count){
    trie *temp=root;
    for(int i=0;i<val.length();i++){
        int index=val[i]-'a';
        if(temp->child[index]==NULL){
            return;
        }
        temp=temp->child[index];
    }
    print(temp,val,count);
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    string A[N];
	    for(int i=0;i<N;i++){
	        cin>>A[i];
	    }
	    trie* root=new trie();
	    for(int i=0;i<N;i++){
	        insert(root,A[i]);
	    }
	    string query;
	    cin>>query;
	    int len=query.length();
	    for(int i=0;i<len;i++){
	        string val=query.substr(0,i+1);
	        int count=0;
	        display(root,val,count);
	        if(count==0){
	            cout<<"0";
	        }
	        cout << endl;
	    }
	}
	return 0;
}
