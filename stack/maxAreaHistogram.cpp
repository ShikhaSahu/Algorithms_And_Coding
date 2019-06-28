/*
Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. For simplicity, assume that all bars have same width and the width is 1 unit.

Input:
The first line contains an integer 'T' denoting the total number of test cases. T test-cases follow. In each test cases, the first line contains an integer 'N' denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array. The elements of the array represents the height of the bars.

Output:
For each test-case, in a separate line, the maximum rectangular area possible from the contiguous bars.

Constraints:
1 <= T <= 100
1 <= N <= 103
1 <= A[i] <= 1018

Example:
Input: 
2
7
6 2 5 4 5 1 6
4
6 3 4 2
Output:
12
9
*/

#include<iostream>
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll max_area_in_histogram(ll arr[],ll n)
{
    ll i=0,area=0,maxarea=-1,top;
    stack<ll> s;
    while(i<n)
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
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    ll n;
	    cin>>n;
	    ll arr[n];
	    for(ll i=0;i<n;i++)
	        cin>>arr[i];
	   cout<<max_area_in_histogram(arr,n)<<endl;
	}
	return 0;
}
