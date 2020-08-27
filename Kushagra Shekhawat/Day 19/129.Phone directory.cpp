#include <bits/stdc++.h>
#define ALPHABET 26
using namespace std;

unordered_set<string>s;

struct Trie{
    struct Trie *character[ALPHABET];
    bool endOfString;
    
    Trie(){
        for(int i=0;i<ALPHABET;i++)
            character[i] = NULL;
        endOfString = false;
    }
};

struct Trie *getNode(){
    struct Trie *node = new Trie;
    return node;
}

void insert(struct Trie *node,string key){
    struct Trie *root = node;
    
    int lenKey = key.length();
    for(int i=0;i<lenKey;i++){
        int index = key[i]-'a';
        if(!root->character[index])
            root->character[index]=getNode();   
        root = root->character[index];
    }
    root->endOfString=true; 
}

void searchAndPrint(struct Trie *root, string findStr,bool &found){
    if(!root)
        return;
    else if(root->endOfString){
        found = true;
        cout<<findStr<<" ";
    }
    for(int i=0;i<ALPHABET;i++)
        if(root->character[i])
            searchAndPrint(root->character[i],findStr+(char)(i+'a'),found);
}

bool search(struct Trie *root, string findStr){
    int lenStr = findStr.length();
    Trie *temp=root;
    for(int i=0;i<lenStr;i++){
        int index = findStr[i]-'a';
        if(!temp->character[index])
            return false;
        temp=temp->character[index];
    }
    bool found=false;
    searchAndPrint(temp,findStr,found);
    return found;
}

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    string names[n],find,temp="";
	    for(int i=0;i<n;i++)
	        cin>>names[i];
	    cin>>find;
	    
	    Trie *root = getNode();
	    for(int i=0;i<n;i++){
	        insert(root,names[i]);
	    }
	    bool found;
	    for(int i=0;i<find.length();i++){
	        temp+=find[i];
	        found = search(root,temp);
	        if(!found)
	            cout<<"0";
	        cout<<endl;
	        s.clear();
	    }
	}
	return 0;
}