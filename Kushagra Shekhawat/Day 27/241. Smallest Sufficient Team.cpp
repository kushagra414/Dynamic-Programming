class Solution {
public:
    unordered_map<string,int> AllSkills;
    
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        // Think of skills as a bit Vector
        vector<bitset<16>> peopleSkills = createBitVectorOfPeople(people);
        bitset<16> reqSkills = createBitVectorOfReqSkills(req_skills);
        vector<pair<bitset<16>, pair<int,vector<int>>>> DP;
        unordered_map<bitset<16>, int> peopleWithSkill;
        int index = 0;
        for(auto BitSkills: peopleSkills){
            int sizeDP = DP.size();
            for(int i = 0;i< sizeDP; i++){
                bitset<16> CombinedBitSkills = BitSkills | DP[i].first;
                int totalPeople = DP[i].second.first+1;
                if(peopleWithSkill.find(CombinedBitSkills) == peopleWithSkill.end() or peopleWithSkill[CombinedBitSkills] > totalPeople){
                    vector<int> indices = DP[i].second.second;
                    indices.push_back(index);
                    DP.push_back(make_pair(CombinedBitSkills,make_pair(totalPeople,indices)));
                    peopleWithSkill[CombinedBitSkills] = totalPeople;
                }
            }
            vector<int> indexVec = {index++};
            if(peopleWithSkill.find(BitSkills) == peopleWithSkill.end() or peopleWithSkill[BitSkills] > 1){
                DP.push_back(make_pair(BitSkills,make_pair(1,indexVec)));
                peopleWithSkill[BitSkills] = 1;
            }
        }
        int minPeople = INT_MAX;
        vector<int> smallestSuffTeam;
        for(auto DP_i: DP){
            if(DP_i.first == reqSkills and minPeople > DP_i.second.first){
                minPeople = DP_i.second.first;
                smallestSuffTeam = DP_i.second.second;
            }
        }
        return smallestSuffTeam;
    }
    
    vector<bitset<16>> createBitVectorOfPeople(vector<vector<string>>& people){
        createSkillIndex(people);
        vector<bitset<16>> bitSkillVector;
        for(auto skills: people){
            bitset<16> bitSkill(0);
            for(auto skill: skills){
                bitSkill[AllSkills[skill]] = 1;
            }
            bitSkillVector.push_back(bitSkill);
        }
        return bitSkillVector;
    }
    
    void createSkillIndex(vector<vector<string>>& people){
        int skillNo=0;
        for(auto skills: people){
            for(auto skill: skills){
                if(AllSkills.find(skill) == AllSkills.end()){
                    AllSkills[skill] = skillNo++;
                }
            }
        }
    }
    
    bitset<16> createBitVectorOfReqSkills(vector<string> &req_skills){
        bitset<16> bitReqSkill(0);
        for(auto req_skill: req_skills)
            bitReqSkill[AllSkills[req_skill]] = 1;
        return bitReqSkill;
    }
    
};