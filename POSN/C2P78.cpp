#include <bits/stdc++.h>
using namespace std;
unordered_map<int, vector<int>> mp;
void bfs(int s, unordered_map<int, bool> &visited) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : mp[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    unordered_map<int, bool> visited;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        mp[a].push_back(b);
        mp[b].push_back(a);
         visited[a] = false;
         visited[a] = false;
    }
    for (auto &p : mp) {
        sort(p.second.begin(), p.second.end());
    }
    int components = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            ++components;
            bfs(i, visited);
        }
    }
    cout <<components << endl;
}
