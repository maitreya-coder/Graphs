#include<bits/stdc++.h>
using namespace std;
void addEdges( vector<vector<int>> &graph, int u, int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}
void dfs(vector<vector<int>> &graph, vector<bool> &visited, int u){
    visited[u] = true;
    cout<<u<<"\n";
    for(int i=0;i<graph[u].size();i++){
        if(!visited[graph[u][i]]){
            dfs(graph,visited,graph[u][i]);
        }
    }
}
int main(){
    int n = 6;
    vector<vector<int>> graph(n);
    addEdges(graph,0,1);
    addEdges(graph,0,2);
    addEdges(graph,3,5);
    addEdges(graph,5,4);
    addEdges(graph,4,3);

    vector<bool> visited(n,false);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(graph,visited,i);
        }
    }
    return 0;
}
