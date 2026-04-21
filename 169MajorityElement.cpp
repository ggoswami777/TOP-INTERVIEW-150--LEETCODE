class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int count=1;
        int candidate=nums[0];
        for(int i=1;i<n;i++){
            if(candidate==nums[i]) count++;
            else count--;
            if(count==0){
                count=1;
                candidate=nums[i];
            }
        }
        count=0;
        for(int i=0;i<n;i++){
            if(candidate==nums[i]) count++;
        }
        if(count>=n/2) return candidate;
        return -1;

    }
};
