#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> parent, componentSize;

int find(int u) {
    if (u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void union_sets(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        if (componentSize[u] < componentSize[v]) swap(u, v);
        parent[v] = u;
        componentSize[u] += componentSize[v];
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> adj(N);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> removeOrder(N);
    for (int i = 0; i < N; ++i) {
        cin >> removeOrder[i];
        removeOrder[i]--;
    }
    
    parent.resize(N);
    componentSize.resize(N);
    vector<bool> active(N, false);
    vector<string> result(N);
    
    for (int i = 0; i < N; ++i) {
        parent[i] = i;
        componentSize[i] = 1;
    }
    
    int components = 0;
    for (int i = N - 1; i >= 0; --i) {
        int node = removeOrder[i];
        active[node] = true;
        components++;
        
        for (int neighbor : adj[node]) {
            if (active[neighbor]) {
                if (find(node) != find(neighbor)) {
                    union_sets(node, neighbor);
                    components--;
                }
            }
        }
        
        result[i] = (components == 1) ? "YES" : "NO";
    }
    
    for (const auto& res : result) {
        cout << res << endl;
    }
    
    return 0;
}
