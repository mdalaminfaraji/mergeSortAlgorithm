#include<bits\stdc++.h>
using namespace std;
const int N=1e3+5;
vector<int> adj[N];
int dis[N];
bool vis[N];
void bfs(int src){
    queue<int>q;
    q.push(src);
    vis[src]=true;
    dis[src]=0;
    while(!q.empty()){
        int parent=q.front();
        q.pop();
        for(int i=0; i<adj[parent].size(); i++){
           int child=adj[parent][i];
             if(!vis[child]){
                q.push(child);
                dis[child]=dis[parent]+1;
                vis[child]=true;
             }
        }
    }


}

int main()
{
    int n, e;
    cin>>n>>e;
    while(e--){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(1);
    for(int i=1; i<=n; i++){
        cout<<"Node index: "<<i<<" :"<<dis[i]<<endl;
        
    }
    
    return 0;
}
