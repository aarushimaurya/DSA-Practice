https://www.interviewbit.com/problems/subset-sum-problem/

int Solution::solve(vector<int> &A, int B) {

    bool dp[A.size()+1][B+1];

    dp[0][0]=1;

    for(int j=1; j<=B; j++)
        dp[0][j]=0;
    
    for(int i=1; i<=A.size(); i++)
        dp[i][0]=1;

    for(int i=1; i<=A.size(); i++)
    {
        for(int j=1; j<=B; j++)
        {
            if(A[i-1]>j)
                dp[i][j]= dp[i-1][j];

            else if(dp[i-1][j] || dp[i-1][j-A[i-1]])
                dp[i][j]=1;

            else
                dp[i][j]=0;
        }
    }

    return dp[A.size()][B];
}
