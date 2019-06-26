/*
BFS traversal of a graph
0->1 2
1->0 2 3 4
2->0 1 3
3->1 2 4
4->1 3
Bfs traversal:  0 1 2 3 4
*/

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
void bfs(int src,map<int,list<int>> mp)  //Bfs function 
{
    queue<int> q;
    map<int,bool> visited;
    visited[src]=true;
    q.push(src);
    while(!q.empty())
    {
        int node=q.front();
        cout<<node<<" ";
        q.pop();
        for(int neib:mp[node])
        {
            if(visited[neib]==false)
            {
                q.push(neib);
                visited[neib]=true;
            }
        }
    }
    cout<<endl;
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
    bfs(0,mp);
}
