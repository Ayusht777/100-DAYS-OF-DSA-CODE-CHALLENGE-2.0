#include <bits/stdc++.h>
using namespace std;
//  Detect Cycle In A Directed Graph 
// https://www.codingninjas.com/codestudio/problems/detect-cycle-in-a-directed-graph_1062626

bool checkCycleDFS(int node ,unordered_map<int,bool> &visited,unordered_map<int ,bool> &dfsvisited,unordered_map<int ,list<int>> &adj){
   visited[node] =true;
   dfsVisited[node] =true;
   for(auto neighbour : adj[node]){
       if(visited[neighbour] == false){
           bool cycleDetected = checkCycleDFS(neighbbour,visited,dfsvisited,adj){
               if(cycleDetected == true){
                   return true;
               }
               else if(dfsvisited[neighbour] == true){
                   return true;
               }
           }
       }
   }
    //wapsi call back pa dfsvisited ko flase kardo
    dfsvisited[node] = false;
    return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  //create  adj list
    unordered_map<int ,list<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
       }
    //call DFS for all componets
    unordered_map<int ,bool> visited;
    unordered_map<int ,bool> dfsvisited;
    for(int i=1;i<=n;i++){
        if(visited[i] == false){
            bool cycleFound = checkCycleDFS(i,visited,dfsvisited,adj);
            if(cycleFound == true){
                return true;
            }
        }
    }
    return false;
}