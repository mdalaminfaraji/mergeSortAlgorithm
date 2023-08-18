#include <bits\stdc++.h>
using namespace std;
const int N = 1e3 + 5;
// vector<int>adj[N];
vector<int> adj[N];
bool visited[N];
int depth[N];
int height[N];

void dfs(int u)
{
    // section 1: actions just after entering a node u
    visited[u] = true;
    // cout<<"Visiting node: "<<u <<endl;
    for (int v : adj[u])
    {
        // section 2:actions before entering a neighbor/child
        if (visited[v] == true)
            continue;
        depth[v] = depth[u] + 1;  
        dfs(v);
        // section 3:actions after exiting a neighbor
        //  if(height[v]+1>height[u]){
        //      height[u]=height[v]+1;
        //  }
        height[u] = max(height[u], height[v] + 1);
    }
    // section 4:actions before exiting a node u
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //   for(int i=1; i<=n; i++){
    //     cout<<"Node "<< i<<": ";
    //     for(int j:adj[i]){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    //   }
    dfs(1);

    for (int i = 1; i <= n; i++)
    {
        cout << "Depth of Node " << i << " :" << depth[i] << endl;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << "Depth of height " << i << " :" << height[i] << endl;
    }

    return 0;
}

/*10
9
1 2
1 3
1 10
2 4
3 5
3 6
4 7
4 8
6 9
*/
