class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>freq(255,0);
        for(auto&it:magazine){
            freq[it]++;
        }
        for(auto&s:ransomNote){
            if(freq[s]==0) return false;
            freq[s]--;
        }
        return true;

    }
};