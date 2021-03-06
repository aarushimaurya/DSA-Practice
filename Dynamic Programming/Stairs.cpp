// https://www.interviewbit.com/problems/stairs/
// https://leetcode.com/problems/climbing-stairs/

// O(1) space-
class Solution {
public:
    int climbStairs(int n) {
        
        if(n==1)   
            return 1;
        
        int prev1=1;
        int prev2=1;
        
        for(int i=2; i<=n; i++)
        {
            int curr=prev1+prev2;
            prev2=prev1;
            prev1=curr;
        }
        
        return prev1;
        
    }
};

// O(n) space-
int Solution::climbStairs(int A) {

    int dp[A+1];
    dp[0]=1;
    dp[1]=1;

    for(int i=2; i<=A; i++)
        dp[i]=dp[i-1]+dp[i-2];

    return dp[A];   
}


