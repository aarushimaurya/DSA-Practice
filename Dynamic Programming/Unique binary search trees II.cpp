https://www.interviewbit.com/problems/unique-binary-search-trees-ii/

int Solution::numTrees(int A) {

    int dp[A+1];

    dp[0]=1;
    dp[1]=1;
    dp[2]=2;

    for(int i=3; i<=A; i++)
    {
        int j=0, k=i-1;
        dp[i]=0;
        while(j<=i-1 && k>=0)
        {
            dp[i]= dp[i]+dp[j]*dp[k];
            j++;
            k--;
        }
    }

    return dp[A];
}
