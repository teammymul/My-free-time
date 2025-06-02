#include <bits/stdc++.h>
using namespace std;
map<int,pair<int,vector<int>>> mp;
int bfs(int s){
    int mx = 0;
    bool visited[10005] = {false};
    vector<int> dist(10005,-1);
    visited[s] = true;
    priority_queue<tuple<int,int,vector<int>> , vector<tuple<int,int,vector<int>>> , greater<tuple<int,int,vector<int>>>> pq;
    pq.push({0,mp[s].first,mp[s].second});
    while (!pq.empty())
    {
        int crr = get<0>(pq.top());
        int w = get<1>(pq.top());
        vector<int> s = get<2>(pq.top());
        cout<<w<<" ";
        for(int i = 0 ; i < s.size() ; ++i){
            if(!visited[s[i]]){
                cout<<s[i];
                visited[s[i]] = true;
                dist[s[i]] = crr+mp[s[i]].first;
                pq.push({crr+mp[s[i]].first,mp[s[i]].first,mp[s[i]].second});
                mx = max(mx,crr+mp[s[i]].first);
            }
            else continue;
        }
        pq.pop();
    }

    return mx;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m,k;cin>>n>>m>>k;
    for(int i = 0 ; i < m ; ++i){
        int a,b,c;cin>>a>>b>>c;
        mp[a].first = c;
        mp[a].second.push_back(b);
        mp[b].first = c;
        mp[b].second.push_back(a);
    }
    cout<<bfs(1);
}