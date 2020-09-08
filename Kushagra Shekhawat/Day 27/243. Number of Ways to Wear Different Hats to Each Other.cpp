class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        vector<uint32_t> BitWords = binaryRepresentation(words);
        vector<uint32_t> BitPuzzles = binaryRepresentation(puzzles);
        unordered_map<int,int> map;
        vector<int> validWords(puzzles.size(),0);
        uint32_t subs,count=0, index = 0,first;
        
        for(auto BitWord: BitWords){
            map[BitWord]++;
        }
        
        for(auto BitPuzzle: BitPuzzles){
            subs = BitPuzzle;
            count = 0;
            first = 1<<(puzzles[index][0] - 'a');
            while(subs){
                if((first & subs) and map.find(subs) != map.end())
                    count += map[subs];
                subs = (subs-1) & BitPuzzle;   // This line of code is use to find all the substring of the string.
                // Very tricky do a dry run test if you cant understand this
            }
            validWords[index++] = count;
        }
        return validWords;
    }
    
    vector<uint32_t> binaryRepresentation(vector<string> Strings){
        uint32_t bitRep,index = 0;
        vector<uint32_t> bitRepVector(Strings.size());
        for(auto word: Strings){
            bitRep = 0;
            for(auto c: word){
                bitRep |= 1<<(c-'a');
            }
            bitRepVector[index++] = bitRep;
        }
        return bitRepVector;
    }
};