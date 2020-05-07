
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<pair<pair<int,int>, ll>> edges;
vector<int> adj[2509], adj2[2509], nodes,nodes2,tocheck;
ll n,m, dists[2509], visited[2509], visited2[2509];

void dfs(int i, int key){
    if(key == 0){
        if(visited[i] == 1) return;
        visited[i] = 1;
        nodes.push_back(i);
        for(int e : adj[i]){
            dfs(e,0);
        }
    }
    else{
        if(visited2[i] == 1) return;
        visited2[i] = 1;
        nodes2.push_back(i);
        for(int e : adj2[i]){
            dfs(e,1);
        }
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    memset(visited,0,sizeof visited);
    memset(visited2,0,sizeof visited2);
    for(ll i=0,a,b,w; i<m; i++){
        cin >> a >> b >> w;
        edges.push_back({{a,b},-w});
        adj[b].push_back(a);
        adj2[a].push_back(b);
    }
    dfs(n,0);
    dfs(1,1);

    for(int i=1; i<=n; i++){
        dists[i] = 1000000000000000000LL;
    }
    dists[1] = 0;
    for(int i=1; i<n; i++){
        for(auto e : edges){
            dists[e.first.second] = min(dists[e.first.second], dists[e.first.first] + e.second);
        }
    }

    for(int i=1; i<=n; i++){
        if(visited[i] && visited2[i]){
            tocheck.push_back(i);
        }
    }

    vector<ll> tmp;
    for(int e : tocheck){
        tmp.push_back(dists[e]);
    }
    for(auto e : edges){
        dists[e.first.second] = min(dists[e.first.second], dists[e.first.first] + e.second);
    }
    for(int i=0; i<tocheck.size(); i++){
        if(dists[tocheck[i]] != tmp[i]){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << -dists[n] << endl;
}
