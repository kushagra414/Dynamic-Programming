class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        vector<int> uniq;
        int left = 0,right= 0;
        for(auto x: A){
            right = uniq.size();
            uniq.push_back(x);
            for(int i = left;i < right;i++){
                if(uniq.back() != (x | uniq[i]))
                    uniq.push_back(x | uniq[i]);
            }
            left = right;
        }
        return unordered_set(uniq.begin(),uniq.end()).size();
    }
};