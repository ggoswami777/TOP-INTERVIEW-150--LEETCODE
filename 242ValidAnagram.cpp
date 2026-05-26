class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        vector<int>ans(26,0);
        for(auto&ch:s){
            ans[ch-'a']++;
        }
        for(auto&ch:t){
            ans[ch-'a']--;
        }
        for(int i=0;i<26;i++){
            if(ans[i]!=0) return false;
        }
        return true;
    }
};