/*
Given a postfix expression, the task is to evaluate the expression and print the final value. 
Operators will only include the basic arithmetic operators like *,/,+ and - .

nput:
The first line of input will contains an integer T denoting the no of test cases . Then T test cases follow. 
Each test case contains an postfix expression.

Output:
For each test case, in a new line, evaluate the postfix expression and print the value.

Constraints:
1 <= T <= 100
1 <= length of expression <= 100

Example:
Input:
2
231*+9-
123+*8-
Output:
-4
-3

*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int postfix_evaluation(string input)
{
    int res=0;
    stack<int> s;
    for(int i=0;i<input.size();i++)
    {
        if(input[i]=='+') //if operator is '+' the pop 2 elements from stack operand1 will be the 2nd poped element  
        {                 //and operand2 will be the 1st poped element the apply operand1 + operand2
            int v2=s.top();
            s.pop();
            int v1=s.top();
            s.pop();
            s.push(v1+v2);
        }
        else if(input[i]=='-')
        {
            int v2=s.top();
            s.pop();
            int v1=s.top();
            s.pop();
            s.push(v1-v2);
        }
        else if(input[i]=='*')
        {
            int v2=s.top();
            s.pop();
            int v1=s.top();
            s.pop();
            s.push(v1*v2);
        }
        else if(input[i]=='/')
        {
            int v2=s.top();
            s.pop();
            int v1=s.top();
            s.pop();
            s.push(v1/v2);
        }
        else
            s.push(input[i]-'0');   //i am storing int in stack so to get int val subtract char val of'0' from it
    }
    res=s.top();  //result will be present on top of stack
    return res;
}
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    string input;
	    cin>>input;
	    int result=postfix_evaluation(input);
	    cout<<result<<endl;
	}
	return 0;
}
