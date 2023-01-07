#include <bits/stdc++.h>
using namespace std;
// Articulation Point - I
// https://practice.geeksforgeeks.org/problems/articulation-point-1/1
class Solution {
  public:
  void dfs(int node,int parent,vector<int> &disc,vector<int> &low,unordered_map<int,bool> &vis,vector<int> adj[],int &timer,set<int>&ans){
  vis[node] =true;
  disc[node] = low[node] =timer++;
  int child = 0;
  for (auto nb : adj[node])
  {
    if(nb == parent){
        continue;
    }
    if(!vis[nb]){
        dfs(nb,node,disc,low,vis,adj,timer,ans);
        low[node] = min(low[node],low[nb]);
        //check ap or not
        if(low[nb] >= disc[node] && parent != -1){
            ans.insert(node);

        }
        child++;

    }
    else{
        low[node] = min(low[node],disc[nb]);
    }

  }
  if(parent == -1 && child > 1){
    ans.insert(node);
  }
  }
  
    vector<int> articulationPoints(int V, vector<int>adj[]) {
    int timer = 0;
    vector<int> disc(V,-1);
    vector<int> low(V,-1);
    unordered_map<int,bool> vis;
    set<int> ans;
    //dfs
    for (int i = 0; i < V; i++)
    {
        if(!vis[i]){
          dfs(i,-1,disc,low,vis,adj,timer,ans);
        
        }
    }
    
     
    vector<int> final(ans.begin(),ans.end());
    if(final.size()==0) return {-1};
    return final;   
    }
};

class Solution {
  public:
  void dfs(int node,int parent,vector<int> &disc,vector<int> &low,unordered_map<int,bool> &vis,vector<int> adj[],int &timer,set<int>&ans){
  vis[node] =true;
  disc[node] = low[node] =timer++;
  int child = 0;
  for (auto nb : adj[node])
  {
    if(nb == parent){
        continue;
    }
    if(!vis[nb]){
        dfs(nb,node,disc,low,vis,adj,timer,ans);
        low[node] = min(low[node],low[nb]);
        //check ap or not
        if(low[nb] >= disc[node] && parent != -1){
            ans.insert(node);

        }
        child++;

    }
    else{
        low[node] = min(low[node],disc[nb]);
    }

  }
  if(parent == -1 && child > 1){
    ans.insert(node);
  }
  }
  
    vector<int> articulationPoints(int V, vector<int>adj[]) {
    int timer = 0;
    vector<int> disc(V,-1);
    vector<int> low(V,-1);
    unordered_map<int,bool> vis;
    set<int> ans;
    //dfs
    for (int i = 0; i < V; i++)
    {
        if(!vis[i]){
          dfs(i,-1,disc,low,vis,adj,timer,ans);
        
        }
    }
    
     
    vector<int> final(ans.begin(),ans.end());
    if(final.size()==0) return {-1};
    return final;   
    }
};