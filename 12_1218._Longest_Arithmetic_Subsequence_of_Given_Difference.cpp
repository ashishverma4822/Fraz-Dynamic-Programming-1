class Solution {
private:
    int hiAyu(vector<int>&arr, int t, int i, int prev){
        if(i>=arr.size()) return 0;
        int take = 0;
        if(prev+t==arr[i]){
            take = 1+hiAyu(arr,t,i+1,arr[i]);
        }
        int not_take = hiAyu(arr,t,i+1,prev);
        return max(take,not_take);
    }                                                  
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        // int uttar = 0;
        // for(int i=0;i<arr.size();i++){
        //     uttar = max(uttar,hiAyu(arr,difference,i,arr[i]-difference));
        // }     
        // return uttar;
        unordered_map<int,int>mp;
        int uttar = 0;
        for(int i=0;i<arr.size();i++){
            int prev = arr[i] - difference;
            if(mp.find(prev)!=mp.end()){
                mp[arr[i]] = mp[prev]+1;
            }
            else{
                mp[arr[i]] = 1;
            }
            uttar = max(uttar,mp[arr[i]]);
        }
        return uttar;
        
    }
};
