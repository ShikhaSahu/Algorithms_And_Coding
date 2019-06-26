/* Grpagh adjacency list implementation using map of list */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void addedge(map<int,list<int>> &mp,int u,int v,bool bidir)
{
    mp[u].push_back(v);
    if(bidir)
        mp[v].push_back(u);
}
void printgraph(map<int,list<int>> mp)
{
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        cout<<it->first<<"->";
        for(int i:it->second)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    map<int,list<int>> mp;
    addedge(mp,0,1,true);
    addedge(mp,0,2,true);
    addedge(mp,2,1,true);
    addedge(mp,3,1,true);
    addedge(mp,2,3,true);
    addedge(mp,4,1,true);
    addedge(mp,3,4,true);
    printgraph(mp);
}
