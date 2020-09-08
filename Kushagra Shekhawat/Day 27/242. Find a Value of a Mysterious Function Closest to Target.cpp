class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        unordered_set<int> unqis,prev;
        int minVal = INT_MAX;
        for(auto x: arr){
            unordered_set<int>curr;
            prev.insert(0x7FFFFFFF);
            for(auto y: prev){
                unqis.insert(x & y);
                curr.insert(x & y);
            }
            prev = curr;
        }
        for(auto num: unqis){
            minVal = min(abs(num - target),minVal);
        }
        return minVal;
    }
};