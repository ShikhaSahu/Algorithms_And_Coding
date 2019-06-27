/*
An encoded string (s) is given, the task is to decode it. The pattern in which the strings were encoded were as follows
original string: abbbababbbababbbab 
encoded string : "3[a3[b]1[ab]]".

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains a string s.

Output:
For each test case in a new line print the required decoded string.

Constraints:
1<=T<=10
1<=length of the string <=30

Example:
Input:
2
1[b]
3[b2[ca]]

Output:
b
bcacabcacabcaca
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string converttostring(stack<char> s)
{
    string res="";
    while(!s.empty())
    {
        char c=s.top();
        s.pop();
        res+=c;
    }
    reverse(res.begin(),res.end());
    return res;
}
string decodestring(string str)
{
    stack<char> s;
    string t="";
    for(int i=0;i<str.size();i++)
    {
        if(str[i]!=']')
        {
            s.push(str[i]);
        }
        else
        {
            string temp="";
            while(!s.empty() && s.top()!='[')
            {
                char c=s.top();
                s.pop();
                temp+=c;
            }
            reverse(temp.begin(),temp.end());
            s.pop();
            string times;
            while(!s.empty() && isdigit(s.top()))
            {
                char c=s.top();
                s.pop();
                times+=c;
            }
            reverse(times.begin(),times.end());
            int t=stoi(times);
            for(int i=0;i<t;i++)
            {
                for(int j=0;j<temp.size();j++)
                {
                    s.push(temp[j]);
                }
            }
        }
    }
    return converttostring(s);
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
	    cout<<decodestring(str);
	    cout<<endl;
	}
	return 0;
}
