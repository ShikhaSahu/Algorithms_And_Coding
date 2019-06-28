/*
Given a binary matrix, Your task is to complete the function maxArea which the maximum size rectangle area in a binary-sub-matrix with all 1’s. 
The function takes 3 arguments the first argument is the Matrix M[ ] [ ] and the next two are two  integers n and m which denotes the size of 
the matrix M. Your function should return an integer denoting the area of the maximum rectangle .

Constraints:
1<=T<=50
1<=n,m<=50
0<=M[][]<=1

Example:
Input
1
4 4 
0 1 1 0 1 1 1 1 1 1 1 1 1 1 0 0

Output
8

*/

int histogram(int arr[],int m)
{
    stack<int> s;
    int i=0,top,maxarea=0,area=0;
    while(i<m)
    {
        if(s.empty() || arr[s.top()]<=arr[i])
            s.push(i++);
        else
        {
            top=s.top();
            s.pop();
            if(s.empty())
                area=arr[top]*i;
            else
                area=arr[top]*(i-1-s.top());
            if(area>maxarea)
                maxarea=area;
        }
    }
    while(!s.empty())
    {
        top=s.top();
        s.pop();
        if(s.empty())
            area=arr[top]*i;
        else
            area=arr[top]*(i-1-s.top());
        if(area>maxarea)
                maxarea=area;
    }
    return maxarea;
}
int maxArea(int M[MAX][MAX],int n,int m)
{
    //Your code here
    //n=rows ,m=cols
   int  maxarea=histogram(M[0],m);
    for(int row=1;row<n;row++)
    {
        for(int col=0;col<m;col++)
        {
                if(M[row][col])
                    M[row][col]+=M[row-1][col];
        }
        maxarea=max(maxarea,histogram(M[row],m));
    }
    return maxarea;
}


