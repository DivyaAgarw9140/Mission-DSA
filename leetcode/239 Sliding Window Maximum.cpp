class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;//stores indices
        vector<int> ans; 
        int maxx=INT_MIN;
        for(int i=0;i<nums.size();i++){
            //remove out of bound indices
            if(!dq.empty() && dq.front()==i-k){
                dq.pop_front();
            }
            //remove smaller element from the back
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            //Skip the first k-1 elements (as they are shorter than window size)
            if(i>=k-1)
            {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};
