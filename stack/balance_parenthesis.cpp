/*
problem is that we have a string which contains alphanumeric characters and parenthesis like"[({})]"
we need to check wether the parenthesis are balanced or not

*/


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//Function that checks wether the parenthesis is balanced or not return true if balanced otherwise false.
bool check_balance_symbols(string str)
{
    stack<char> s;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='(' || str[i]=='[' || str[i]=='{')
            s.push(str[i]);
        else if(str[i]==')' || str[i]==']' || str[i]=='}')
        {
            if(s.top()=='(' && !s.empty() && str[i]==')')
                s.pop();
            else if(s.top()=='[' && !s.empty() && str[i]==']')
                s.pop();
            else if(s.top()=='{' && !s.empty() && str[i]=='}')
                s.pop();
            else
                 return false;
        }
    }
    if(s.empty()==true)
        return true;
    else
        return false;
}
int main()
{
    string str;
    cin>>str;
    bool res=check_balance_symbols(str);
    if(res)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    return 0;
}
