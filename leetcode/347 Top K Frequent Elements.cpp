class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i : nums){
          mp[i]++;
        }
        vector<int>ans;
        vector<pair<int,int>>arr;
        for(auto i : mp){
            arr.push_back({i.first,i.second});
        }
        sort(arr.begin(),arr.end(),[](pair<int,int>&a,pair<int,int>&b){
            return a.second>b.second;
        });
        for(auto i : arr){
            if(k--){
                ans.push_back(i.first);
            }
            else{
                break;
            }
        }
        return ans;
    }
};
