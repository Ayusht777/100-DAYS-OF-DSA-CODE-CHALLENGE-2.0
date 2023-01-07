#include <bits/stdc++.h>
using namespace std;
// Bridges In A Graph 
// https://www.codingninjas.com/codestudio/problems/bridges-in-graph_893026?leftPanelTab=0
void dfs(int node,int parent,int &timer, vector<int> &disc,vector<int> &low,vector<vector<int>> &result, unordered_map<int,list<int>> &adj,unordered_map<int,bool> &vis){
    vis[node] = true;
    disc[node] = low[node] = timer++;
    for(auto nb : adj[node]){
        if(nb == parent){
            continue;
        }
        if(!vis[nb]){
            dfs(nb,node,timer,disc,low,result,adj,vis);
            low[node] = min(low[node],low[nb]);
            //check edges is bridge
            if(low[nb] > disc[node]){
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nb);
                result.push_back(ans);
            }
        }
        else{
            //back edges
            low[node] = min(low[node],disc[nb]);
        }
    }
    
}
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    //adj list
    unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int timer = 0;
    vector<int> disc (v,-1);
    vector<int> low (v,-1);
    int parent = -1;
    unordered_map<int,bool> vis;
    vector<vector<int>> result;
    //dfs
    for(int i=0;i<v;i++){
        if(!vis[i]){
            dfs(i,parent,timer,disc,low,result,adj,vis);
        }
    }
    return result;

} 