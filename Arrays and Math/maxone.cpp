/*
Length of longest consecutive ones
Given a binary string A. It is allowed to do at most one swap between any 0 and 1.
Find and return the length of the longest consecutive 1’s that can be achieved.
Input 1:
    A = "111000"
Output 1:
    3

Input 2:
    A = "111011101"
Output 2:
    7
 */
 
 int Solution::solve(string A) {
    int n=A.size(),countone=0;
    vector<int> l(n,0);
    vector<int> r(n,0);
    if(A[0]=='1')
    {
        l[0]=1;
        countone++;
    }
    else
        l[0]=0;
    if(A[n-1]=='0')
        r[n-1]=0;
    else
    {
        r[n-1]=1;
       // countone++;
    }
    for(int i=1;i<n;i++)
    {
        if(A[i]=='0')
            l[i]=0;
        else{
            l[i]=l[i-1]+1;
            countone++;
        }
    }
    for(int i=n-2;i>=0;i--)
    {
        if(A[i]=='0')
            r[i]=0;
        else
            r[i]=r[i+1]+1;
    }
    int maxval=0;
    if(countone==n)
        return n;
    for(int i=0;i<n;i++)
    {
        if(A[i]=='0')
        {
            int leftval=0,rightval=0,curr=0;
            if(i>0)
                leftval=l[i-1];
            if(i<n-1)
                rightval=r[i+1];
            if(leftval+rightval<countone)
                curr=leftval+rightval+1;
            else
                curr=leftval+rightval;
            if(curr>maxval)
                maxval=curr;
        }
    }
    return maxval;
}

