// https://leetcode.com/problems/jump-game-ii/
// https://www.interviewbit.com/problems/min-jumps-array/

// Leetcode-
class Solution {
public:
    int jump(vector<int>& nums) {
        
        if(nums.size()==1)
            return 0;
        
        int i=0, j=0, jump=0, max_val=0;
        
        while(i<nums.size())
        {
            max_val = max(max_val, i+nums[i]);
            
            if(i==j)
            {
                j=max_val;
                jump++;
                max_val=0;
            }
            
            if(j>=nums.size()-1)
                return jump;
            
            i++;
        }
        
        return jump;
    }
};


//InterviewBit-
int Solution::jump(vector<int> &A) {

    if(A.size()==1)
        return 0;

    int i=0, j=0, jump=0;
    int max_val=0;

    while(i<A.size())
    {
        max_val=max(max_val, i+A[i]);

        if(i==j)
        {
            j=max_val;
            jump++;
            max_val=0;
        }

        if(i>j)
            return -1;
        if(j>=A.size()-1)
            return jump; 

        i++; 
    }
}
