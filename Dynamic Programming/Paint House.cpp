https://www.interviewbit.com/problems/paint-house/

int Solution::solve(vector<vector<int> > &A) {

    vector<vector<int>> B;
    
    for(int i=0; i<A.size(); i++)
    {
        vector<int> v(3);
        B.push_back(v);
    }

    B[0][0]=A[0][0];
    B[0][1]=A[0][1];
    B[0][2]=A[0][2];

    for(int i=1; i<A.size(); i++)
    {
        B[i][0]= A[i][0] + min(B[i-1][1], B[i-1][2]);
        B[i][1]= A[i][1] + min(B[i-1][0], B[i-1][2]);
        B[i][2]= A[i][2] + min(B[i-1][0], B[i-1][1]);
    }

    int ans= min({B[B.size()-1][0], B[B.size()-1][1], B[B.size()-1][2]});
    return ans;
}
