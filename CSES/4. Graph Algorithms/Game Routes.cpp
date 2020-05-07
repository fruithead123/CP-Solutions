
#include <bits/stdc++.h>
using namespace std;

//Topological sort the graph
//dp[x] = number of paths to x from 1
//for each node, we can reach each of its neighbours in dp[x] ways

typedef long long ll;

vector<int> G[100009];
vector<int> topo;
int visited[100009];
int n,m;
stack<int> order;
int dp[100009];
const int MOD = 1000000007;

void dfs(int i){
    if(visited[i] == 1) return;

    visited[i] = 1;
    for(int e : G[i]){
        dfs(e);
    }
    order.push(i);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
    }
    memset(visited, 0, sizeof visited);
    for(int i=1; i<=n; i++){
        dp[i] = 0;
    }
    for(int i=1; i<=n; i++){
        dfs(i);
    }
    while(!order.empty()){
        topo.push_back(order.top());
        order.pop();
    }

    dp[1] = 1;
    for(int x : topo){
        for(int e : G[x]){
            dp[e] = (dp[e] + dp[x]) % MOD;
        }
    }
    cout << dp[n] << endl;
}
