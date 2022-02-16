https://www.interviewbit.com/problems/unique-paths-in-a-grid/

int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {

    if(A[0][0]==1)
        return 0;
    else
        A[0][0]=1;

    if(A.size()==1 && A[0].size()==1)
        return A[0][0];

    for(int i=0; i<A.size(); i++)
    {
        for(int j=0; j<A[i].size(); j++)
        {
            if(A[i][j]==1)
                A[i][j]=-1;
        }
    }

    for(int j=1; j<A[0].size(); j++)
    {
        if(A[0][j]!=-1)
            A[0][j]=1;
        else 
            break;
    }
        
    for(int i=1; i<A.size(); i++)
    {
        if(A[i][0]!=-1)
            A[i][0]=1;
        else
            break;
    }

    for(int i=1; i<A.size(); i++)
    {
        for(int j=1; j<A[i].size(); j++)
        {
            if(A[i][j]!=-1 && A[i-1][j]!=-1)
                A[i][j]= A[i][j]+A[i-1][j];

            if(A[i][j]!=-1 && A[i][j-1]!=-1)
                A[i][j]= A[i][j]+A[i][j-1];
        }
    }

    if(A[A.size()-1][A[0].size()-1]!=-1)
        return A[A.size()-1][A[0].size()-1];
    else
        return 0;
        
}
