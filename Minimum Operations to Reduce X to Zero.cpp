class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalSum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            totalSum+=nums[i];
        }
        int target=totalSum-x;
        if(target==0) return n;
        if(target<0) return -1;
        int l=0;
        int r=0;
        int currentSum=0;
        int maxLen=-1;
        while(r<n){
            currentSum+=nums[r];
          
            while(currentSum>target && l<=r){
                currentSum=currentSum-nums[l];
                l++;
            }
             if(currentSum==target) {
            maxLen=max(maxLen,r-l+1);
            
           };
            r++;
        }
        return (maxLen==-1)?-1:n-maxLen;
    }
};