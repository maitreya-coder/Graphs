#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<int>> &graph, int u, int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}
int main(){
    int n=3;
    vector<vector<int>> graph(n);
    addEdge(graph,0,1);
    addEdge(graph,0,2);
    vector<bool> visited(n,false);
    for(int i=0;i<n;i++){
    if(!visited[i]){
    queue<int> q;
    q.push(i);
    visited[i] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout<<u<<"\n";
        for(int j=0;j<graph[u].size();j++){
            if(!vis[i]){
            visited[i] = true;
            q.push(graph[u][j]);
            }
        } 
    }
    }
    }
    return 0;
}
