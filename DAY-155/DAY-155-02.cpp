#include <bits/stdc++.h>
using namespace std;
//Shortest path in Directed Acyclic Graph
// https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
class Solution {
  public:
  void dfs(int node, unordered_map<int,bool> &visited,stack<int> &s,unordered_map<int,set < pair <int,int> > > &adj){
        visited[node] =true;
        for(auto i : adj[node]){
            if(!visited[i.first]){
                dfs(i.first,visited,s,adj);
            }
        }
        s.push(node);
    }
     void getshortestpath(int src,vector<int> &dist,stack<int> &s,unordered_map<int,set <pair<int,int>>> &adj){
        
        dist[src] =0;
        while (!s.empty())
        {
            int top  =s.top();
            s.pop();
            if(dist[top] != INT_MAX){
                for (auto i:adj[top])
                {
                   if(dist[top] + i.second < dist[i.first]){
                    dist[i.first] = dist[top] +i.second;
                   }
                }
                
            }
        }

    }

     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        unordered_map<int,set < pair < int,int> > > adj;
        for(int i = 0; i < M; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            pair<int,int> p = make_pair(v,w); 
            adj[u].insert(p);
        }
    vector<int> dist(N,INT_MAX);
          
    unordered_map<int,bool> visited;
    stack <int> s;
    for (int i = 0; i < N; i++)
    {
        if(!visited[i]){
            dfs(i,visited,s,adj);
        }
    }

    getshortestpath(0,dist,s,adj);
     for(int i=0;i<N;i++)

        {

            if(dist[i]==INT_MAX)

                dist[i]=-1;

        }
    return dist;
    
    }
};
class Solution {
  public:
  void dfs(int node, unordered_map<int,bool> &visited,stack<int> &s,unordered_map<int,set < pair <int,int> > > &adj){
        visited[node] =true;
        for(auto i : adj[node]){
            if(!visited[i.first]){
                dfs(i.first,visited,s,adj);
            }
        }
        s.push(node);
    }
     void getshortestpath(int src,vector<int> &dist,stack<int> &s,unordered_map<int,set <pair<int,int>>> &adj){
        
        dist[src] =0;
        while (!s.empty())
        {
            int top  =s.top();
            s.pop();
            if(dist[top] != INT_MAX){
                for (auto i:adj[top])
                {
                   if(dist[top] + i.second < dist[i.first]){
                    dist[i.first] = dist[top] +i.second;
                   }
                }
                
            }
        }

    }

     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        unordered_map<int,set < pair < int,int> > > adj;
        for(int i = 0; i < M; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            pair<int,int> p = make_pair(v,w); 
            adj[u].insert(p);
        }
    vector<int> dist(N,INT_MAX);
          
    unordered_map<int,bool> visited;
    stack <int> s;
    for (int i = 0; i < N; i++)
    {
        if(!visited[i]){
            dfs(i,visited,s,adj);
        }
    }

    getshortestpath(0,dist,s,adj);
     for(int i=0;i<N;i++)

        {

            if(dist[i]==INT_MAX)

                dist[i]=-1;

        }
    return dist;
    
    }
};