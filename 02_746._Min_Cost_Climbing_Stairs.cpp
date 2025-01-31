class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1);
        dp[0] = cost[0];
        dp[1] = cost[1];
        if(n<=2) return cost[n-1];
        for(int i=2;i<=n;i++){
            dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
        }
        return min(dp[i],d[i-2]);
    }
};
