class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0;
        int r=n-1;
        int maxWater=INT_MIN;
        while(l<r){
            int idxbw=r-l;
            int water=idxbw*min(height[l],height[r]);
            maxWater=max(maxWater,water);
            if(height[l]<height[r])l++;
            else r--;
        }
        return maxWater;
    }
};