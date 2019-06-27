/*

Given a stack with push(), pop(), empty() operations, delete middle of it without using any additional data structure.

Input Format:
The first line contains an integer T, the number of test cases. For each test case, the first line contains an integer sizeOfStack denoting the stack size. Next line contains space separated integers that will be pushed into the stack.

Output Format:
For each test case, in a new line, print the stack elements. If stack size if 1 then just print the top element.

Your Task:
This is a function problem. The input is already taken by the driver code. You only need to complete the function deleteMid() that returns the modified stack.

Constraints:
1 <= T <= 100
1 <= sizeOfStack <= 100

Example:
Input:
2
5
1 2 3 4 5
7
1 2 3 4 5 6 7

Output:
5 4 2 1
7 6 5 3 2 1

*/

void rec_delete(stack<int> &s,int index,int n)
{
    if(index<0)
        return;
    if(index!=(n/2))
    {
        int temp=s.top();
        s.pop();
        rec_delete(s,index-1,n);
        s.push(temp);
    }
    else
    {
        s.pop();
        rec_delete(s,index-1,n);
    }
}
stack<int> deleteMid(stack<int>s,int sizeOfStack,int current)
{
    //Your code here
    rec_delete(s,sizeOfStack-1,sizeOfStack-1);
    return s;
    
}
