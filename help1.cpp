#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_N = 1005;

vector<int> graph[MAX_N];
int dist[MAX_N];

void bfs(int source, int n) {
    for (int i = 0; i < n; ++i) {
        dist[i] = -1;
    }
    
    queue<int> q;
    q.push(source);
    dist[source] = 0;
    
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        
        for (int neighbor : graph[curr]) {
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[curr] + 1;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;
    
    for (int i = 0; i < e; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    int q;
    cin >> q;
    
    for (int i = 0; i < q; ++i) {
        int s, d;
        cin >> s >> d;
        
        bfs(s, n);
        cout << dist[d] << endl;
    }
    
    return 0;
}
