#include <bits/stdc++.h>
using namespace std;
//  Detect Cycle In A Directed Graph  Using - Kahn's Algo
// https://www.codingninjas.com/codestudio/problems/detect-cycle-in-a-directed-graph_1062626?leftPanelTab=0

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  //create adj list
    unordered_map<int,list<int>> adj;
    for(int i = 0;i<edges.size();i++){
        int u = edges[i].first-1;
        int v = edges[i].second-1;
        adj[u].push_back(v);
    }
    
    //Find all in degress 
    vector<int> indegrees(n);
    queue<int> q;
    for(auto i :adj){
        for(auto j : i.second){
            indegrees[j]++;
        }
    }
    //0 degree vali node ko push karo queue ma
    for(int i = 0;i<n;i++){
        if(indegrees[i] == 0){
            q.push(i);
        }
    }
    //do bfs
    
    int cnt=0;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        //cnt 
        cnt++;
        
        //neighbour node ki indegree updateakro
        for(auto ne : adj[front]){
            indegrees[ne]--;
            if(indegrees[ne] == 0){
                q.push(ne);
            }
        }
    }
    if(cnt == n){
        //iska matlab ki vo valid toplogical sort hai   toh matlab acyclic ha yahan cycle nhi hai
        return false;
    }
    else{
        return true;
    }
}