class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1){
            return s;
        }
        string ans;
        int n=s.size();
        int charinsection=2*(numRows-1);
        for(int curr=0;curr<numRows;curr++){
            int index=curr;
            while(index<n){
                ans+=s[index];
                if(curr!=0 && curr!=numRows-1){
                    int charinbetween=charinsection-2*(curr);
                    int secondIndex=index+charinbetween;
                    if(secondIndex<n){
                        ans+=s[secondIndex];
                    }
                }
                index+=charinsection;
            }
        }
        return ans;
    }
};