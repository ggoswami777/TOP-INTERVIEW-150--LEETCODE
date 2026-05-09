class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0;
        int n=t.size();
        for(int ind=0;ind<n;ind++){
            if(s[i]==t[ind]){
                i++;
            }
        }
     
        if(i==s.size()) return true;
        return false;
    }
};