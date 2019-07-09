/*
Implement the next permutation, which rearranges numbers into the numerically next greater permutation of numbers. 
If such arrangement is not possible, it must be rearranged as the lowest possible order ie, sorted in an ascending order. 
The replacement must be in-place, do not allocate extra memory
*/
void Solution::nextPermutation(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n=A.size(),i,j;
    for(i=n-2;i>=0;i--)
    {
        if(A[i]<A[i+1])
            break;
    }
    if(i==-1)
    {
        reverse(A.begin(),A.end());
        return;
    }
    for(j=n-1;j>i;j--)
    {
        if(A[j]>A[i])
            break;
    }
    swap(A[i],A[j]);
    reverse(A.begin()+i+1,A.end());
    return;
}
