class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxIndex=0;
        for(int i=0;i<n;i++){
            if(i>maxIndex) return false;
            if(maxIndex<n){
                maxIndex=max(maxIndex,i+nums[i]);
                if(maxIndex==n-1) return true;
            }
        }
        return maxIndex>=n-1;
    }
};