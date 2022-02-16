class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        if(nums.size()==1)
            return nums[0];
        
        int ma = nums[0];
        int mi = nums[0];
        int ans = nums[0];
        
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i]<0)
                swap(ma, mi);
            if(nums[i]==0)
            {
                ma=1;
                mi=1;
            }
            ma = max(nums[i], ma*nums[i]);
            mi = min(nums[i], mi*nums[i]);
            ans = max(ans, ma);
        }
        
        return ans;
    }
};