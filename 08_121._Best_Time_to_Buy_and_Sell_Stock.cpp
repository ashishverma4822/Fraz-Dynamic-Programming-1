class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int uttar = 0;
        int dp = prices[0];
        for(int i=1;i<prices.size();i++){
            uttar = max(uttar,prices[i]-dp);
            dp = min(dp,prices[i]);
        }
        return uttar;
    }
};
