#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<int>> &graph, int u, int v){
    graph[u].push_back(v);
}
void dfs(vector<vector<int>> &graph, int node, vector<int> &res, vector<bool> &vis){
    vis[node] = true;
    for(int i=0;i<graph[node].size();i++){
        int nbr = graph[node][i];
        if(!vis[nbr])
        dfs(graph,nbr,res,vis);
    }
    res.push_back(node);
}
int main(){
    int V = 6;
    vector<vector<int>> graph(V);
    addEdge(graph,0,1);
    addEdge(graph,1,2);
    addEdge(graph,2,3);
    addEdge(graph,5,1);
    addEdge(graph,5,2);
    addEdge(graph,4,5);

    vector<bool> vis(V,false);
    vector<int> res;

    for(int i=0;i<V;i++){
        if(!vis[i])
            dfs(graph,i,res,vis);
    }

    reverse(res.begin(),res.end());

    for(int i=0;i<res.size();i++) cout<<res[i]<<" ";

    return 0;
}
