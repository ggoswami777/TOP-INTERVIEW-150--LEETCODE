class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int l=0;
        int r=0;
        int len=0;
        vector<int>mpp(255,-1);
        while(r<n){
            if(mpp[s[r]]!=-1){
                if(mpp[s[r]]>=l){
                    l=mpp[s[r]]+1;
                }
            }
            len=max(len,r-l+1);
            mpp[s[r]]=r;
            r++;
        }
        return len;
    }
};