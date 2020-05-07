
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> G[100009];
int visited[100009];
int n,m;
stack<int> order;

void dfs(int i){
    if(visited[i] == 1){
        cout << "IMPOSSIBLE" << endl;
        exit(0);
    }
    if(visited[i] == 2) return;

    visited[i] = 1;
    for(int e : G[i]){
        dfs(e);
    }
    order.push(i);
    visited[i] = 2;
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
        dfs(i);
    }
    while(!order.empty()){
        cout << order.top() << " ";
        order.pop();
    }
}
