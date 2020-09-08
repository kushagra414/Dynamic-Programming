class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        // We can easily reduce the space used here to O(1), by using arr for storing Xor
        // instead of Map
        unordered_map<int,int> storeXor;
        vector<int> queried(queries.size());
        int Xor = 0,L,R,index=0;
        for(auto ele:arr){
            Xor ^= ele;
            storeXor[index++] = Xor;
        }
        index=0;
        for(auto arr: queries){
            L = arr[0]-1,R = arr[1];
            Xor = storeXor[R];
            if(storeXor.find(L) != storeXor.end())
                Xor ^= storeXor[L];
            queried[index++] = Xor;
        }
        return queried;
    }
};