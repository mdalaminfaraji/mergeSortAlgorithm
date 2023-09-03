#include<bits\stdc++.h>
using namespace std;
const int N=19999;
int dis[N];
bool vis[N];
vector<int>v[N];

void dfs(int s){
    vis[s]=true;
    cout<<s<<endl;
    for(int child:v[s]){
        if(!vis[child]){
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
    v[a].push_back(b);
    v[b].push_back(a);
   }
   int cnt=0;
   for(int i=1; i<=n; i++){
    if(!vis[i]){
        cnt++;
        dfs(i);
    }
   }
   cout<<cnt<<endl;
    return 0;
}
