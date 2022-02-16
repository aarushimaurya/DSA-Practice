// https://leetcode.com/problems/house-robber/

class Solution {
public:
    int rob(vector<int>& nums) {
        
        int prev1 = nums[0];
        int prev2 = 0;
        
        for(int i=1; i<nums.size(); i++)
        {
            int curr;   
        
            if(i==1)
                curr = max(nums[0], nums[1]);
            else
                curr = max(nums[i]+prev2, prev1);
            
            prev2=prev1;
            prev1=curr;
        }
        
        return prev1;
        
    }
};