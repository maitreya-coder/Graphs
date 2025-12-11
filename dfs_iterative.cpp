#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<int>> &graph, int u, int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}
int main(){

    int n = 3;
    vector<vector<int>> graph(n);
    addEdge(graph,0,1);
    addEdge(graph,1,2);
    addEdge(graph,2,0);

    vector<bool> visited(n,false);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            stack<int> st;
            st.push(i);
            while(!st.empty()){
                int u = st.top();
                st.pop();
                if(visited[u]) continue;
                visited[u] = true;
                cout<<u<<"\n";
                for(int j=0;j<graph[u].size();j++){
                    if(!visited[graph[u][j]])
                    st.push(graph[u][j]);
                } 
            }
        }
    }

    return 0;
}
