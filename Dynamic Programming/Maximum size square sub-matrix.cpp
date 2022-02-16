https://www.interviewbit.com/problems/maximum-size-square-sub-matrix/

int Solution::solve(vector<vector<int> > &A) {

    int n=A.size();
    int m=A[0].size();
    int ans=0;

    int dp[n][m];

    for(int j=0; j<A[0].size(); j++)
    {
        dp[0][j]= A[0][j];
        
        if(A[0][j]==1)
            ans=1;
    }
    
    for(int i=0; i<A.size(); i++)
    {
        dp[i][0]= A[i][0];

        if(A[i][0]==1)
            ans=1;
    }

    for(int i=1; i<A.size(); i++)
    {
        for(int j=1; j<A[0].size(); j++)
        {
            if(A[i][j]==0)
            {
                dp[i][j]=0;
                ans= max(ans, dp[i][j]);
            }
            
            else
            {
                dp[i][j]=min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]})+1;
                ans= max(ans, dp[i][j]);
            }
        }
    }

    return ans*ans;
}
