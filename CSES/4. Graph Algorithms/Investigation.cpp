
#include <bits/stdc++.h>
using namespace std;

//Find the shortest path DAG for the graph (Keep only edges that are used in shortest paths, eliminates cycles)
//Topological sort, use dp to find answers

typedef long long ll;

int n,m, visited[100009];
vector<pair<int,ll>> adj[100009], dag[100009];
vector<int> topo;
stack<int> order;
ll dists[100009];
ll dp[100009][4];
const ll MOD = 1000000007;
const ll MAXN = 1000000000000000000LL;

void dfs(int i){
    if(visited[i]) return;
    visited[i] = 1;
    for(auto e : dag[i]){
        dfs(e.first);
    }
    order.push(i);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    memset(visited, 0, sizeof visited);
    memset(dp, 0LL, sizeof dp);
    for(int i=1; i<=n; i++){
        dists[i] = MAXN;
        dp[i][0] = MAXN;
    }
    for(int i=0; i<m; i++){
        int a,b;
        ll w;
        cin >> a >> b >> w;
        adj[a].push_back({b,w});
    }
    priority_queue<pair<ll,pair<pair<int,int>, ll>>> pq; //(-dist, (dest,from), weight)
    dists[1] = 0;
    for(auto e : adj[1]){
        pq.push({-e.second, {{e.first, 1}, e.second}});
    }
    while(!pq.empty()){
        auto k = pq.top(); pq.pop();
        ll d = -k.first;
        int cur = k.second.first.first;
        int src = k.second.first.second;
        int wt = k.second.second;
        if(d > dists[cur]){
            continue;
        }
        else if(d == dists[cur]) {
            dag[src].push_back({cur,wt});
        }
        else{
            dists[cur] = d;
            dag[src].push_back({cur, wt});
            for(auto e : adj[cur]){
                pq.push({-(d + e.second), {{e.first,cur}, e.second}});
            }
        }
    }

    //DAG is stored as dag[]
    /*
    for(int i=1; i<=n; i++){
        for(auto x : dag[i]){
            cout << x.first << " " << x.second << "| ";
        }
        cout << endl;
    }
    */
    for(int i=1; i<=n; i++){
        dfs(i);
    }
    while(!order.empty()){
        topo.push_back(order.top());
        order.pop();
    }
    /*
    for(int k : topo){
        cout << k << " ";
    }
    cout << endl;
    */

    //do dp through topo
    //dp[i] -> (min price, #, least flight, most flight)
    dp[1][0] = dp[1][2] = dp[1][3] = 0;
    dp[1][1] = 1LL;

    for(int x : topo){
        for(auto e : dag[x]){
            int dest = e.first;
            ll d = e.second;
            if(dp[dest][0] < dp[x][0] + d){
                continue;
            }
            if(dp[dest][0] == dp[x][0] + d){
                dp[dest][1] = (dp[dest][1] + dp[x][1]) % MOD;
                dp[dest][2] = min(dp[dest][2], dp[x][2] + 1);
                dp[dest][3] = max(dp[dest][3], dp[x][3] + 1);
            }
            else{
                dp[dest][0] = dp[x][0] + d;
                dp[dest][1] = dp[x][1];
                dp[dest][2] = dp[x][2] + 1;
                dp[dest][3] = dp[x][3] + 1;
            }
        }
    }
    cout << dp[n][0] << " " << dp[n][1] << " " << dp[n][2] << " " << dp[n][3] << endl;
}
