#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<int>> &graph, int u, int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}
void bfs(vector<vector<int>> &graph, queue<int> &q, vector<bool> &vis){

    int node = q.front();
    q.pop();
    cout<<node<<"\n";
    vis[node] = true;
    for(int i=0;i<graph[node].size();i++){
        int nbr = graph[node][i];
        if(!vis[nbr]){
        vis[nbr] = true;
        q.push(nbr);
        }
    }
    if(!q.empty())
    bfs(graph,q,vis);
    return;
}
int main(){
    int n=3;
    vector<vector<int>> graph(n);
    addEdge(graph,0,1);
    addEdge(graph,1,2);
    addEdge(graph,0,2);
    vector<bool> vis(n,false);
    for(int i=0;i<n;i++){
    if(!vis[i]){
        queue<int> q;
        q.push(i);
        bfs(graph,q,vis);
    }
    }
    return 0;
}
