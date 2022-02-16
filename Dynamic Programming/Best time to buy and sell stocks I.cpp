https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-i/

int Solution::maxProfit(const vector<int> &A) {

    int profit=0;
    int price=INT_MAX;

    for(int i=0; i<A.size(); i++)
    {
        price=min(price,A[i]);
        profit=max(profit, A[i]-price);
    }

    return profit;
}
