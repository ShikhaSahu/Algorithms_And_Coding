/*
Given an infix expression in the form of a string str. Conver this infix expression to postfix expression.
Input:
The first line of input contains an integer T denoting the number of test cases. The next T lines contains an infix expression.The expression contains all characters and ^,*,/,+,-.

Output:
For each testcase, in a new line, output the infix expression to postfix expression.

Constraints:
1 <= T <= 100
1 <= length of str <= 103

Example:
Input:
2
a+b*(c^d-e)^(f+g*h)-i
A*(B+C)/D

Output:
abcd^e-fgh*+^*+i-
ABC+*D/

*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string infix_to_postfix(string str)
{
    string res;
    stack<char> s;
    unordered_map<char,int> mp;  //map to keep track of priorities of operators, unordered_map for O(1) time complexity and we don't need any ordering
    mp.insert(make_pair('^',3));
    mp.insert(make_pair('/',2));
    mp.insert(make_pair('*',2));
    mp.insert(make_pair('+',1));
    mp.insert(make_pair('-',1));
    for(int i=0;i<str.size();i++)
    {
        if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')) //if alphabets occur simply insert into res
            res+=str[i];
        else if(str[i]==')') //if ')' the pop and append into result until '(' occur do not add '(' into result
        {
            while(s.top()!='(')
            {
                if(s.top()!='(')
                    res+=s.top();
                s.pop();
            }
            s.pop();
        }
        else if(str[i]=='(')  //if'(' occur push into stack
            s.push(str[i]);
          //pop and append into res until lower priority operator occur or '(' or stack becomes empty and push the current operator into stack
        else 
        {
            while(!s.empty() && s.top()!='(' && mp[str[i]]<=mp[s.top()])
            {
                res+=s.top();
                s.pop();
            }
            s.push(str[i]);
        }
    }
    //if any operator left append it into res
    while(!s.empty())
    {
        res+=s.top();
        s.pop();
    }
    return res;
}
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    string res=infix_to_postfix(str);
	    cout<<res<<endl;
	}
	return 0;
}
