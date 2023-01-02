#include <bits/stdc++.h>
using namespace std;
//Cycle Detection In Undirected Graph - Using BFS
//https://www.codingninjas.com/codestudio/problems/cycle-detection-in-undirected-graph_1062670


bool isCycleBFS(int src, unordered_map<int,bool> &visited,unordered_map<int,list<int>> &adj){
    unordered_map<int,int> parent;
    //by default Node parent is -1
    parent[src] = -1;
    visited[src] = 1; //mark it true
    queue<int> q;
    q.push(src);
    
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        for(auto neighbour : adj[frontNode]){
           if(visited[neighbour] == true && neighbour != parent[frontNode]){
               return true;
           } 
           else if(visited[neighbour] == false){
               q.push(neighbour);
               visited[neighbour] = 1;
               parent[neighbour] = frontNode;
           }
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{   
    //creating ajd list from edges where m is numbers of edges
    unordered_map<int,list<int>> adj;
    for(int i=0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //Visited list
    unordered_map<int,bool> visited;
    //to handle disconnected commponets
    for(int i=0;i<n;i++){
        if(visited[i] == false){
            bool ans = isCycleBFS(i,visited,adj);
            if(ans == 1){
                string temp ="Yes";
               
                return temp;
            }
        }
    }
   string temp = "No";
  return temp;
   
}


