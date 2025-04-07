class Solution {
public:
    using ll = long long;
    long long maximumTotalDamage(vector<int>& power) {
        map<ll,ll>mp,dp;
        for(auto x:power){
            mp[x]++;
        }
        ll uttar = 0;
        for(auto [x,y]: mp){
            dp[x] = x*y;
            auto itr = dp.upper_bound(x-3);
            if(itr != dp.begin()){
                dp[x] = max(dp[x],prev(itr)->second + x*y);
            }
            itr = dp.find(x);
            if(itr!=dp.begin()){
                dp[x] = max(dp[x],prev(itr)->second);
            }
            uttar = max(uttar,dp[x]);
        }
        return uttar;
    }
};
