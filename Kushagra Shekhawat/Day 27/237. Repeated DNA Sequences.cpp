class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int,int> DNA;
        int i,AGTC[4]={0};
        bitset<16> DNA()
        string temp;
        for(i=0;i<10;i++){
            temp += s[i];
            increaseCount(AGTC,s[i]);
        }
        for(;i<s.length();i++){
            temp.erase(temp.begin());
            temp += s[i];
            DNA[temp]++;
        }
        vector<string> repeatedDna;
        for(auto map: DNA)
            if(map.second > 1)
                repeatedDna.push_back(map.first);
        return repeatedDna;
        
    }
    void increaseCount(int AGTC[],s[i]){
        switch(s[i]){
            case 'A': AGTC[0]++;
                break;
            case 'G': AGTC[1]++;
                break;
            case 'T': AGTC[2]++;
                break;
            case 'C': AGTC[3]++;
        }
    }
};