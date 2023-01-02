#include <bits/stdc++.h>
using namespace std;
//Cycle Detection In Undirected Graph - Using DFS
//https://www.codingninjas.com/codestudio/problems/cycle-detection-in-undirected-graph_1062670


bool isCycleDFS(int node,int parent, unordered_map<int,bool> &visited,unordered_map<int,list<int>> &adj){
  visited[node] =true;
    for(auto neighbour: adj[node]){
        if(visited[neighbour] == false){
            bool cycleDetected = isCycleDFS(neighbour,node,visited,adj);
        }
        else if(neighbour != parent){
            return true;
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
            bool ans = isCycleDFS(i,-1,visited,adj);
            if(ans == 1){
                
               
                return "Yes";
            }
        }
    }
return "No";
   
}
