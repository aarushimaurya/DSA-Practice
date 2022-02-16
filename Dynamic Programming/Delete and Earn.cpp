// https://leetcode.com/problems/delete-and-earn/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        if(nums.size()==1)
            return nums[0];
        
        sort(nums.begin(), nums.end());
        
        map<int,int> mp;
        
        for(int i=0; i<nums.size(); i++)
            mp[nums[i]]++;
        
        int k=1;
        while(k<nums.size())
        {
            if(nums[k]==nums[k-1])
               nums.erase(nums.begin()+k);
            
            else
                k++;     
        }
        
        int dp[nums.size()];
        
        int prev2 = nums[0]*mp[nums[0]];
        int prev1;
        
        if(nums[0]==nums[1]-1)
            prev1 = max(prev2, nums[1]*mp[nums[1]]);
        else
            prev1 = prev2 + nums[1]*mp[nums[1]];
        
        if(nums.size()==2)
            return prev1;
        
        for(int i=2; i<nums.size(); i++)
        {
            if(nums[i-1]==nums[i]-1)
            {
                int curr = max(prev1, (prev2 + (nums[i] * mp[nums[i]])));
                prev2 = prev1;
                prev1 = curr;
            }
                
            else
            {
                int curr = max(prev1, prev2) + (nums[i] * mp[nums[i]]);
                prev2 = prev1;
                prev1 = curr;
            }
        }
       
        return max(prev2, prev1);
        
    }
};