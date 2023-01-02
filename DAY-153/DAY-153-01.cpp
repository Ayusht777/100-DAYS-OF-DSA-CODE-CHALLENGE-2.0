#include <bits/stdc++.h>
using namespace std;
// DFS Traversal 
// https://www.codingninjas.com/codestudio/problems/dfs-traversal_630462?leftPanelTab=0

void dfs(int node,unordered_map < int, bool > &visited,unordered_map< int,list<int>> &adjList,vector<int> &component){
    //ans store
    component.push_back(node);
    //mark visited 
    visited[node] = true;
    for(auto i : adjList[node]){
        if(!visited[i]){
            dfs(i,visited,adjList,component);
        }
        
    }
    
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{   unordered_map < int,list<int>> adjList;
    //prepared adj list
     for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);

     }
 vector<vector<int>> ans;
 unordered_map < int, bool > visited;
 //for all nodes call dfs if not visited
 for(int i =0;i<V;i++){
     if(!visited[i]){
         vector<int> component;
         dfs(i,visited,adjList,component);
         ans.push_back(component);
     }
 }
 return ans;
}