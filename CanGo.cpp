#include<bits\stdc++.h>
using namespace std;
const long long int N = 1e5 + 5;
vector<pair<long long int,long long int>> v[N];
long long int dis[N];
void dijkstra(long long int s)
{
    queue<long long int> q;
    q.push(s);
    dis[s] = 0;
    while (!q.empty())
    {
       long long int parent = q.front();
        q.pop();
        for (pair<long long int,long long int> child: v[parent])
        {
          
            long long int childNode = child.first;
           long long  int childCost = child.second;
            if (dis[parent] + childCost < dis[childNode])
            {
                dis[childNode] = dis[parent] + childCost;
                q.push(childNode);
            }
        }
    }
}
int main()
{
    long long int n, e;
    cin >> n >> e;
    while (e--)
    {
      long long  int a, b, w;
        cin >> a >> b >> w;
        v[a].push_back({b, w});
    }
    for (long long int i = 1; i <= n; i++)
    {
        dis[i] = INT_MAX;
    }
    long long int s;
    cin>>s;
    dijkstra(s);
    long long int Q;
    cin>>Q;
    while(Q--){
        long long int u, v;
        cin>>u>>v;
        if(dis[u]<=v){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }

    //  for(int i=1; i<=n; i++){
    //     cout<<"Node"<<i<<":"<<dis[i]<<endl;
    // }
    return 0;
}
