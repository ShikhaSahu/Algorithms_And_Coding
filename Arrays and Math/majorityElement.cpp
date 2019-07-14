/*
Majority Element
Given an array of size n, find the majority element. The majority element is the element that appears more than floor(n/2) times. You may assume that the array is non-empty and the majority element always exist in the array. Example :
Input : [2, 1, 2]
Return  : 2 which occurs 2 times which is greater than 3/2. 
*/

int Solution::majorityElement(const vector<int> &A) {
    int n=A.size();
    if(n==1)
        return A[0];
    int m=A[0],c=1;
    for(int i=1;i<n;i++)
    {
        if(c==0)
        {
            m=A[i];
            c=1;
        }
        if(A[i]==m)
            c++;
        else if(A[i]!=m)
            c--;
        
    }
    if(c>0)
    {
        return m;
    }

}
