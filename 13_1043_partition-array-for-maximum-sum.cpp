class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size(),0);
        dp[0] = arr[0];
        int max_ele = arr[0];
        for(int i=1;i<arr.size();i++){
            max_ele = arr[i];
            int cnt = 0, j = i;
            while(j>=0 and cnt<k){
                max_ele = max(max_ele,arr[j]);
                cnt++;
                dp[i] = max(dp[i], cnt*max_ele + (j-1>=0?dp[j-1]:0));
                j--;
            }
        }
        return dp[arr.size()-1];
    }
};
