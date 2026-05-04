class Solution {
public:
    int lengthOfLastWord(string s) {
        int count=0;
        int last=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==' ') count=0;
            else {
                count++;
                last=count;
            }
        }
        if(count==0) return last;
        return count;
    }
};