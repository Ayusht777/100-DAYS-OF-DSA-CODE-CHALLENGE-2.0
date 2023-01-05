#include <bits/stdc++.h>
using namespace std;
//Dijkstra's shortest path 
// https://www.codingninjas.com/codestudio/problems/dijkstra-s-shortest-path_920469?leftPanelTab=0

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    //create adj list with weights
    unordered_map <int,list<pair<int,int>>> adj;
    for(int i = 0 ;i<edges;i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
        
    }
    //distance array with infinity value
    vector<int> dist(vertices,INT_MAX);
    //create a set with distance and node 
    set<pair<int,int>> st;
    //initialize set and distance with zero
    dist[source] = 0;
    st.insert(make_pair(0,source));
    
    while(!st.empty()){
        //fetch top record
        auto top = *(st.begin());
        
        int nodeDistance = top.first;
        int topNode = top.second;
        
        //remove top record now
        st.erase(st.begin());
        
        //traverse on neighbour
        for(auto i : adj[topNode]){
            if(nodeDistance + i.second < dist[i.first]){
                auto record = st.find(make_pair(dist[i.first],i.first));
                //if record found,then erase it
                if(record != st.end()){
                    st.erase(record);
                }
                //distance update
                dist[i.first] = nodeDistance + i.second;
                //record push in set
                st.insert(make_pair(dist[i.first],i.first));
                
            }
        }
        
    }
    return dist;
    
    
}
