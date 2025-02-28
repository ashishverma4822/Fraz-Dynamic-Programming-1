private:
    int hiAyu(vector<int>&nums){
        vector<int>dp(nums.size(),0);
        int uttar = 0;
        for(int i=2;i<nums.size();i++){
            if(nums[i]-nums[i-1] == nums[i-1]-nums[i-2]) dp[i] = dp[i-1]+1;
            uttar+=dp[i];
        }
        return uttar;
    }
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        return hiAyu(nums);
    }
};
