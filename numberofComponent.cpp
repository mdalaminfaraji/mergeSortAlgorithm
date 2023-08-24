#include<bits\stdc++.h>
using namespace std;
const int N=1e3+5;
vector<int>adj[N];
bool visited[N];
int level[N];
void dfs(int u){
    visited[u]=true;
    for(int v:adj[u]){
        if(visited[v]) continue;
        dfs(v);
    }
}


void bfs(int s){
    queue<int>q;
    q.push(s);
    visited[s]=true;
    //section1: a node is being processed
 
    while(!q.empty()){
        int u=q.front();
        q.pop();
        cout<<"visiting node:"<<u<<endl;
        //section 2: child processing
        for(int v:adj[u]){
            if(visited[v]==true) continue;
            q.push(v);
            visited[v]=true;
            //section 3: child processing
           
        }
        //section 4: same as section 1
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
        adj[v].push_back(u);
    }
    int cc=0;
    for(int i=1; i<=n; i++){
        if(visited[i]) continue;
        dfs(i);
        cc++;
    }
    
    cout<<"Number of connected components:"<<cc<<endl;
   
    return 0;
}
