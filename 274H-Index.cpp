class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        vector<int>ans(n+1,0);
        for(auto c:citations){
            if(c>n){
                ans[n]++;
            }else{
                ans[c]++;
            }
        }
        int count=0;
        for(int i=n;i>=0;i--){
            count=count+ans[i];
            if(count>=i){
                return i;
            }
        }
        return 0;

    }
};