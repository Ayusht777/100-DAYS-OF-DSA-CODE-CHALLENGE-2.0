#include <bits/stdc++.h>
using namespace std;
// Implementing Dijkstra Algorithm
// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

class Solution {
    public:
        //Function to find the shortest distance of all the vertices
        //from the source vertex S.
        vector < int > dijkstra(int V, vector < vector < int >> adj[], int S) {

            //distance array with infinity value
            vector < int > dist(V, INT_MAX);
            //create a set with distance and node 
            set < pair < int, int >> st;
            //initialize set and distance with zero
            dist[S] = 0;
            st.insert(make_pair(0, S));

            while (!st.empty()) {
                //fetch top record
                auto top = * (st.begin());

                int nodeDistance = top.first;
                int topNode = top.second;

                //remove top record now
                st.erase(st.begin());

                //traverse on neighbour
                for (auto i: adj[topNode]) {
                    if (nodeDistance + i[1] < dist[i[0]]) {
                        auto record = st.find(make_pair(dist[i[0]], i[0]));
                        //if record found,then erase it
                        if (record != st.end()) {
                            st.erase(record);
                        }
                        //distance update
                        dist[i[0]] = nodeDistance + i[1];
                        //record push in set
                        st.insert(make_pair(dist[i[0]], i[0]));

                    }
                }

            }
            return dist;
        }
};