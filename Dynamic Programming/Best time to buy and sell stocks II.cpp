https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-ii/

int Solution::maxProfit(const vector<int> &A) {

    int profit=0;
    //int var=A[0];

    for(int i=1; i<A.size(); i++)
    {
        if(A[i]<=A[i-1])
            continue;
        else
            profit=profit+ A[i]-A[i-1];
    }

    return profit;
}
