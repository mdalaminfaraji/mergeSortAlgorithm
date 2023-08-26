#include<bits\stdc++.h>
using namespace std;
const int N=1e5+5;
bool visited [N];
vector<int> result;
vector<int>adj[N];
void dfs(int u){
    visited[u]=true;
    result.push_back(u);
    for(int v: adj[u]){  
        if(visited[v]==true) continue;
        dfs(v);
    }  
}
int main()
{
     int n, m;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
      

    }

    int Node;
    cin>>Node;
    dfs(Node);
   cout<<result.size()-1<<endl;
    return 0;
}
