#include <bits/stdc++.h>
using namespace std;
// Topological Sort Using -DFS
// https://www.codingninjas.com/codestudio/problems/topological-sort_982938?leftPanelTab=0

void topSort(int node, vector<bool> &visited,stack<int> &s,unordered_map<int,list<int>> &adj){
    visited[node] = true;
    for(auto neighbour : adj[node]){
        if(visited[neighbour] == false){
            topSort(neighbour,visited,s,adj);
        }
    }
    //imp 
    s.push(node);
    
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    //create adj list
    unordered_map<int,list<int>> adj;
    for(int i = 0;i<e;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }
    
    //call DFS Toplogical Sort Util function for all componets
    vector<bool> visited(v);
    stack<int> s;
    for(int i=0;i<v;i++){
        if(visited[i] == false){
            topSort(i,visited,s,adj);
        }
    }
    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}