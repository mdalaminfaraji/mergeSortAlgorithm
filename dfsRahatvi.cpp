#include<bits\stdc++.h>
using namespace std;
const int N=1e3+5;
vector<int>adj[N];
bool vis[N];
void dfs(int s){
    vis[s]=true;
    cout<<s<<endl;
    for(int i=0; i<adj[s].size(); i++){
         int child=adj[s][i];
         if(vis[child]==false){
           dfs(child);
         }
    }
}

int main()
{
   int n, e;
   cin>>n>>e;
   while(e--){
    int a, b;
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
   }
   dfs(1);
    return 0;
}
