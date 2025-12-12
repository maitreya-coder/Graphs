#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<int>> &graph, int u, int v, vector<int> &in_degree){
    graph[u].push_back(v);
    in_degree[v]++;
}
int main(){
    int V = 5;
    vector<int> in_degree(V,0);
    vector<vector<int>> graph(V);
    addEdge(graph,0,1,in_degree);
    addEdge(graph,1,2,in_degree);
    addEdge(graph,3,2,in_degree);
    addEdge(graph,3,4,in_degree);
    vector<int> res;
    queue<int> q;
    for(int i=0;i<V;i++){
        if(in_degree[i]==0)
        q.push(i);
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        res.push_back(node);
        for(int i=0;i<graph[node].size();i++){
            int nbr = graph[node][i];
            in_degree[nbr]--;
            if(in_degree[nbr]==0)
            q.push(nbr);
        }
    }
    for(int i=0;i<V;i++)
    cout<<res[i]<<" ";
    cout<<"\n";
    return 0;
}
