class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int maxHeight=height[0];
        int index=0;
        int lmax=0;
        int rmax=0;
        int water=0;
        for(int i=1;i<n;i++){
            if(height[i]>maxHeight){
                maxHeight=height[i];
                index=i;
            }
        }
        for(int i=0;i<index;i++){
            if(lmax>=height[i]){
                water+=lmax-height[i];
            }else{
                lmax=height[i];
            }
        }
        for(int j=n-1;j>index;j--){
            if(rmax>=height[j]){
                water+=rmax-height[j];
            }else{
                rmax=height[j];
            }
        }
        return water;
    }
};