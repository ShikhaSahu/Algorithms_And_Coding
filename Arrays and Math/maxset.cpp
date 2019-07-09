/*
Find out the maximum sub-array of non negative numbers from an array. The sub-array should be continuous. That is, a sub-array created by choosing the second and fourth element and skipping the third element is invalid. Maximum sub-array is defined in terms of the sum of the elements in the sub-array. Sub-array A is greater than sub-array B if sum(A) > sum(B). Example:
A : [1, 2, 5, -7, 2, 3]
The two sub-arrays are [1, 2, 5] [2, 3].
The answer is [1, 2, 5] as its sum is larger than [2, 3]
*/

vector<int> Solution::maxset(vector<int> &A) {
    vector<int> ans;
    int flagneg=0,flagpos=0;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]<0){
            flagneg=1;
        }
        if(A[i]>=0)
            flagpos=1;
    }
    if(flagneg==1 && flagpos==0)
        return ans;
    else if(flagneg==0 && flagpos==1)
        return A;
    else
    {
        long long int sum=0,maxsum=INT_MIN;
        int minst=0,s=0;
        int len=0,maxlen=0;
        for(int i=0;i<A.size();i++)
        {
           // sum+=A[i];
            if(A[i]<0)
            {
                sum=0;
                s=i+1;
                len=0;
            }
            else
            {
                sum+=A[i];
                len++;
                if(sum>maxsum)
                {
                    maxsum=sum;
                    minst=s;
                    maxlen=len;
                }
                else if(sum==maxsum && len>maxlen)
                {
                    maxlen=len;
                    minst=s;
                }
            }
        }
        for(int i=minst;i<minst+maxlen;i++)
            ans.push_back(A[i]);
        return ans;
    }
}
