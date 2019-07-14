/*
Repeat and Missing Number Array
You are given a read only array of n integers from 1 to n.  Each integer appears exactly once except A which appears twice and B which is missing. Return A and B.  Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? Note that in your output A should precede B.  Example:
Input:[3 1 2 5 3] 

Output:[3, 4] 

A = 3, B = 4
*/

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long int sum=0, sqsum=0,asum=0,asqsum=0;
    for(long long int  i=0;i<A.size();i++)
    {
        sum+=(long long int)A[i];
        sqsum+=((long long int)A[i]*(long long int)A[i]);
    }
    long long int n=A.size();
    asum=(n*(n+1))/2;
    asqsum=(n*(n+1)*(2*n+1))/6;
    long long int diff=asum-sum;
    long long int diff1=asqsum-sqsum;
    long long int s=diff1/diff;
    int m=(s+diff)/2;
    int r=(s-diff)/2;
    vector<int> res;
    res.push_back(r);
    res.push_back(m);
    return res;
}
