//tabulation
class Solution {
public:
    unordered_map<int,int>mp;
    vector<int>dp;
    int deleteAndEarn(vector<int>& nums) {
        mp.clear();
        for(auto num: nums) mp[num]++;
        vector<int>arr;
        for(auto it = mp.begin();it!=mp.end();it++){
            it->second = it->second*it->first;
            arr.push_back(it->first);
        }
        dp.resize(arr.size(),0);
        sort(arr.begin(),arr.end());
        if(arr.size()==0) return 0;
        if(arr.size()==1) return mp[arr[0]];
        dp[0] = mp[arr[0]];
        if(arr[1]==arr[0]+1) dp[1] = max(mp[arr[1]],mp[arr[0]]);
        else dp[1] = mp[arr[1]]+mp[arr[0]];
        for(int i=2;i<arr.size();i++){
            if(arr[i]==arr[i-1]+1){
                dp[i] = max(dp[i-2]+mp[arr[i]],dp[i-1]);
            }
            else{
                dp[i] = dp[i-1]+mp[arr[i]];
            }
            cout<<dp[i]<<" ";
        }
        return dp[arr.size()-1];
    }
};

// Recursive + memo
class Solution {
private:
    int hiAyu(vector<int>&nums, int i){
        if(i>=nums.size()) return 0;
        if(v[i]!=-1) return v[i];
        int take = 0,not_take = 0;
        if(i+1<nums.size() and nums[i+1]==nums[i]+1){
            take = mp[nums[i]] + hiAyu(nums,i+2);
        }
        else{
            take = mp[nums[i]]+hiAyu(nums,i+1);
        }
        not_take = hiAyu(nums,i+1);
        return v[i] = max(take,not_take);
    }
public:
    unordered_map<int,int>mp;
    vector<int>v;
    int deleteAndEarn(vector<int>& nums) {
        mp.clear();
        for(auto num: nums){
            mp[num]++;
        }
        vector<int>arr;
        for(auto it = mp.begin();it!=mp.end();it++){
            it->second = it->second*it->first;
            arr.push_back(it->first);
        }
        v.resize(arr.size(),-1);
        sort(arr.begin(),arr.end());
        return hiAyu(arr,0);
    }
};
