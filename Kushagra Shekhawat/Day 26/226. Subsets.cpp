class Solution {
public:
    vector<vector<int>> AllSubSets;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> setVector;
        for(int i=1;i<=nums.size();i++)
            createSet(nums, {}, 0, i);
        AllSubSets.push_back({});
        return AllSubSets;
    }
    void createSet(vector<int>& nums,vector<int> Set,int index,
                                                        int posLeft){
        if(posLeft<=0 or index >= nums.size()){
            if(!Set.empty() and posLeft == 0)
                AllSubSets.push_back(Set);
            return;
        }
        Set.push_back(nums[index]);
        createSet(nums, Set,index+1,posLeft-1);
        Set.erase(Set.end()-1);
        createSet(nums, Set,index+1,posLeft);
    }
};