// https://leetcode.com/problems/jump-game/
// https://www.interviewbit.com/problems/jump-game-array/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        if(nums.size()==1)
            return true;
        
        int j=0;
        
        for(int i=0; i<nums.size(); i++)
        {
            j = max(j, i+nums[i]);
            
            if(j<=i)
                return false;
            
            if(j>=nums.size()-1)
                return true;
        }
        
        return true;
    }
};
