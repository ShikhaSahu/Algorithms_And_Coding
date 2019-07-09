/*
Set Matrix Zeros
Given an m x n matrix of 0s and 1s, if an element is 0, set its entire row and column to 0.  Do it in place. Example Given array A as
1 0 1
1 1 1 
1 1 1
On returning, the array A should be :
0 0 0
1 0 1
1 0 1
*/

void Solution::setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int rflag=0,cflag=0;
    for(int i=0;i<A.size();i++)
    {
        if(A[i][0]==0)
        {
            cflag=1;
            break;
        }
    }
    for(int i=0;i<A[0].size();i++)
    {
        if(A[0][i]==0)
        {
            rflag=1;
            break;
        }
    }
    for(int i=1;i<A.size();i++)
    {
        for(int j=1;j<A[0].size();j++)
        {
            if(A[i][j]==0)
            {
               A[0][j]=0;
               A[i][0]=0;
            }
        }
    }
    for(int i=1;i<A.size();i++)
    {
        for(int j=1;j<A[0].size();j++)
        {
            if(A[0][j]==0 || A[i][0]==0)
                A[i][j]=0;
        }
    }
    if(rflag)
    {
        for(int i=0;i<A[0].size();i++)
            A[0][i]=0;
    }
    if(cflag)
    {
        for(int i=0;i<A.size();i++)
            A[i][0]=0;
    }
}
