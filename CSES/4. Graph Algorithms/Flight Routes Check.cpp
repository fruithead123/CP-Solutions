
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int n,m, visited[100009], component[100009];
vector<int> adj[100009], adjRev[100009];
stack<int> order;

void dfs(int x){
    if(visited[x] != 0) return;
    visited[x] = 1;
    for(int e : adj[x]) dfs(e);
    order.push(x);
}

void dfs2(int x, int c){
    if(component[x] != 0) return;
    component[x] = c;
    for(int e : adjRev[x]) dfs2(e, c);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0; i<=n; i++){
        visited[i] = component[i] = 0;
    }
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adjRev[b].push_back(a);
    }
    for(int i=1; i<=n; i++){
        if(component[i] == 0) dfs(i);
    }
    int cur = 1;
    int badNode = 0;
    int firstNode = order.top();
    while(!order.empty()){
        //cout << order.top() << "\n";
        int x = order.top(); order.pop();
        if(component[x] == 0) dfs2(x, cur++), badNode = x;
    }

    if(cur > 2){
        cout << "NO" << "\n" << badNode << " " << firstNode;
    }
    else{
        cout << "YES";
    }
}
