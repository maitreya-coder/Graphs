#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<pair<int,int>>> &graph, int u, int v, int wt){
    graph[u].push_back(make_pair(v,wt));
    graph[v].push_back(make_pair(u,wt));
}
int main(){
    int V=5;
    vector<vector<int>> edges = { {0, 1, 4}, {0, 2, 8}, {1, 4, 6}, {2, 3, 2}, {3, 4, 10} };
    int src = 0;
    vector<int> dist(V,INT_MAX);
    dist[src] = 0;
    for(int i=1;i<=(V-1);i++){
        for(int j=0;j<edges.size();j++){
            int u = edges[j][0] , v = edges[j][1] , wt = edges[j][2];
            // the graph is undirected.
            // so you have to relax in both directions
            // from u->v and from v->u
            if (dist[u]!=INT_MAX && ((dist[u] + wt) < dist[v])){
                dist[v] = dist[u] + wt;
            }
            if (dist[v]!=INT_MAX && ((dist[v] + wt) < dist[u])){
                dist[u] = dist[v] + wt;
            }
        }
    }

    for(int i=0;i<V;i++) cout<<dist[i]<<" ";
    return 0;
}

// Bellman Ford is very simple : you just gotta relax the nodes , (V-1) times. Run it one more time, the
// Vth time , and if it still relaxes, you've got a cycle. It all works for all sorts of weights.

// Bellman Ford is EDGE BASED. YOU DON'T NEED AN ADJACENCY MATRIX FOR THIS.
