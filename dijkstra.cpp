#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<pair<int,int>>> &graph, int u, int v, int wt){
    graph[u].push_back(make_pair(wt,v));
    graph[v].push_back(make_pair(wt,u));
}

int main(){
    int V = 4;
    vector<vector<pair<int,int>>> graph(V);
    addEdge(graph,0,1,1);
    addEdge(graph,0,2,3);
    addEdge(graph,1,2,5);
    addEdge(graph,1,3,2);
    addEdge(graph,2,3,1);

    vector<int> dist(V,INT_MAX);
    dist[0] = 0;

    priority_queue < pair<int,int> , vector< pair<int,int> > , greater<> > pq;
    pq.push(make_pair(dist[0],0));

    while(!pq.empty()){
        pair<int,int> p = pq.top();
        pq.pop();
        int node = p.second , wt_node = p.first;
        if(dist[node] < wt_node) continue;
        for(int i=0;i<graph[node].size();i++){
            pair<int,int> g = graph[node][i];
            int nbr = g.second , wt_nbr = g.first;
                if((wt_nbr + dist[node]) < dist[nbr]){
                dist[nbr] = wt_nbr + dist[node];
                pq.push(make_pair(nbr,dist[nbr]));
                }
        }
    }

    for(int i=0;i<V;i++) cout<<dist[i]<<" ";

    return 0;
}
