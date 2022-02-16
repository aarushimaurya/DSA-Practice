// https://leetcode.com/problems/house-robber-ii/

class Solution {
public:
    int rob(vector<int>& nums) {
        
        if(nums.size()==1)
            return nums[0];
        
        int prev1 = nums[0];
        int prev2 = 0;
        
        for(int i=1; i<nums.size()-1; i++)
        {
            int curr;   
        
            if(i==1)
                curr = max(nums[0], nums[1]);
            else
                curr = max(nums[i]+prev2, prev1);
            
            prev2=prev1;
            prev1=curr;
        }
        
        int ans = prev1;
        
        prev1 = nums[1];
        prev2 = 0;
        
        for(int i=2; i<nums.size(); i++)
        {
            int curr;   
        
            curr = max(nums[i]+prev2, prev1);
            
            prev2=prev1;
            prev1=curr;
        }

        ans = max(ans, prev1);
        
        return ans;
        
    }
};