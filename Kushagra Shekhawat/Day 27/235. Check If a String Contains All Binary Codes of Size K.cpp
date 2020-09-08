class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> comb;
        string find;
        int i=0;
        // window size of k;
        for(i=0;i<k;i++)
            find += s[i];
        comb.insert(find);
        for(;i<s.length();i++){
            find.erase(find.begin());
            find += s[i];
            comb.insert(find);
        }
        if(comb.size() == (1<<(k)))
            return true;
        return false;
    }
};