
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1000000009;

vector<int> adj[200009];
vector<pair<int,int>> order;
int n, par[200009],sz[200009];
ll ans[200009];

int dfs(int x, int p, int d){
    ans[1] += (ll)d;
    int s = 1;
    par[x] = p;
    order.push_back({d, x});
    for(int e : adj[x]){
        if(e != p){
            s += dfs(e, x, d+1);
        }
    }
    sz[x] = s;
    return s;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1; i<n; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ans[1] = 0;
    sz[1] = dfs(1, -1, 0);
    sort(order.begin(), order.end());
    for(auto p : order){
        if(p.second == 1) continue;
        ans[p.second] = ans[par[p.second]] + (ll)(n - 2*sz[p.second]);
    }
    for(int i=1; i<=n; i++){
        cout << ans[i] << " ";
    }
}
