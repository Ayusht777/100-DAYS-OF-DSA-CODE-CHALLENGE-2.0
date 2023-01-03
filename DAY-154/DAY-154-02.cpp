#include <bits/stdc++.h>
using namespace std;
// Topological Sort Using - BFS/Kahn'S Algo
// https://www.codingninjas.com/codestudio/problems/topological-sort_982938?leftPanelTab=0

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    //create adj list
    unordered_map<int,list<int>> adj;
    for(int i = 0;i<e;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }
    
    //Find all in degrees 
    vector<int> indegrees(v);
    queue<int> q;
    for(auto i :adj){
        for(auto j : i.second){
            indegrees[j]++;
        }
    }
    //0 degree vali node ko push karo queue ma
    for(int i= 0;i<v;i++){
        if(indegrees[i] == 0){
            q.push(i);
        }
    }
    //do bfs
    
    vector<int> ans;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        //ans store
        ans.push_back(front);
        
        //neighbour node ki indegree update kro
        for(auto ne : adj[front]){
            indegrees[ne]--;
            if(indegrees[ne] == 0){
                q.push(ne);
            }
        }
    }
    return ans;
}