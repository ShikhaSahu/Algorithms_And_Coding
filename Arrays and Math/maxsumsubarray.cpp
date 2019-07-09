/*
Max Sum Contiguous Subarray
Find the contiguous subarray within an array (containing at least one number) which has the largest sum. 
For example: Given the array [-2,1,-3,4,-1,2,1,-5,4], the contiguous subarray [4,-1,2,1] has the largest sum = 6.
For this problem, return the maximum sum.

*/

int Solution::maxSubArray(const vector<int> &A) {
    int sum=0,max_sum=INT_MIN;
    for(int i=0;i<A.size();i++)
    {
        sum+=A[i];
        
        if(sum>max_sum)
        {
            max_sum=sum;
        }
        if(sum<0)
        {
            sum=0;
        }
    }
    return max_sum;
}
