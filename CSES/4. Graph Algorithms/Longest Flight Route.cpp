
#include <bits/stdc++.h>
using namespace std;

//Topological sort the graph
//for each vertex, consider all the edges and see how many nodes we can visit for each connetion
//dp[i] = {f,s}
//f -> The max number of nodes we can visit while ending at this vertex
//s -> The previous node in the longest path

typedef long long ll;

vector<int> G[100009];
vector<int> topo;
int visited[100009];
int n,m;
stack<int> order;
pair<int,int> dp[100009];

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
        dp[i] = {0,0};
    }
    for(int i=1; i<=n; i++){
        dfs(i);
    }
    while(!order.empty()){
        topo.push_back(order.top());
        order.pop();
    }

    dp[1] = {1,0}; //# visitd, prev
    for(int x : topo){
        for(int e : G[x]){
            if(dp[x].first != 0 && dp[x].first + 1 > dp[e].first){
                dp[e].first = dp[x].first + 1;
                dp[e].second = x;
            }
        }
    }

    if(dp[n].first == 0){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        cout << dp[n].first << endl;
        int tmp = n;
        while(tmp != 1){
            order.push(tmp);
            tmp = dp[tmp].second;
        }
        cout << 1 << " ";
        while(!order.empty()){
            cout << order.top() << " ";
            order.pop();
        }
    }
}
