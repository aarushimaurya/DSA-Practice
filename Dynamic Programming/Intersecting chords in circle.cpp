https://www.interviewbit.com/problems/intersecting-chords-in-a-circle/

int Solution::chordCnt(int A) {

    long long int dp[A+1];
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;

    for(int i=3; i<=A; i++)
    {
        dp[i]=0;
        int j=0, k=i-1;
        while(j<=i && k>=0)
        {
            dp[i]=(dp[i]+ dp[j]*dp[k])%1000000007;
            j++;
            k--;
        }
    }
    return dp[A]%1000000007;
}
