/*
Given an expression exp of length n consisting of some brackets. The task is to print the bracket numbers when the expression is being parsed.

Input:
The first line contains an integer T, the number of test cases. For each test case, there is a string exp containing the expression.

Output:
For each test case, the output is the bracket numbers of the expression.

Constraints:
1<=T<=100
1<=S<=100

Example:
Input:
3
(a+(b*c))+(d/e)
((())(()))
((((()
Output:
1 2 2 1 3 3
1 2 3 3 2 4 5 5 4 1
1 2 3 4 5 5
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void print_bracket_number(string str)
{
    int count=1;
    stack<pair<char,int>> s;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='(')
        {
            s.push(make_pair('(',count));
            cout<<count<<" ";
            count++;
        }
        else if(str[i]==')' && !s.empty() && s.top().first=='(')
        {
            cout<<s.top().second<<" ";
            s.pop();
        }
    }
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    print_bracket_number(str);
	    cout<<endl;
	}
	return 0;
}
