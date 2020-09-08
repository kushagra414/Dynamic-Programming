class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> AllCases;
        findAllLetterCases(S,"",AllCases,0);
        return AllCases;
    }
    void findAllLetterCases(string S,string temp,vector<string> 
                                                    &AllCases,int i){
        if(i == S.length()){
            AllCases.push_back(temp);
            return;
        }
        if(S[i]-'0'>9)
            findAllLetterCases(S,temp+(char)(S[i]^32),
                                                    AllCases,i+1);
        findAllLetterCases(S,temp+S[i],AllCases,i+1);
    }
};