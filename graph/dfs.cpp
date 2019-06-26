/* dfs traversal on graph (more components) */

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
    for(auto node:mp)
    {
        cout<<node.first<<"->";
        for(auto neib:node.second)
            cout<<neib<<" ";
        cout<<endl;
    }
}
void dfsutil(map<int,list<int>> mp,map<int,bool> &visited,int src)
{
    cout<<src<<" ";
    visited[src]=true;
    for(auto neib:mp[src])
    {
        if(!visited[neib])
              dfsutil(mp,visited,neib);
     }
}
void dfs(map<int,list<int>> mp)
{
    map<int,bool> visited;
    for(auto node:mp)
    {
        if(!visited[node.first])
              dfsutil(mp,visited,node.first);
    }
}
int main()
{
    map<int,list<int>> mp;
    addedge(mp,0,1,true);
    addedge(mp,0,2,true);
    addedge(mp,1,2,true);
    addedge(mp,1,3,true);
    addedge(mp,1,4,true);
    addedge(mp,2,3,true);
    addedge(mp,3,4,true);
    addedge(mp,5,6,true);
    printgraph(mp);
    dfs(mp);
    return 0;
}
