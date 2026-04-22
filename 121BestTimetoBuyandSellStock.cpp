class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int buy=prices[0];
        int n=prices.size();
        for(int i=1;i<n;i++){
            int sell=prices[i];
            profit=max(profit,sell-buy);
            buy=min(buy,prices[i]);

        }
        return profit;
    }
};