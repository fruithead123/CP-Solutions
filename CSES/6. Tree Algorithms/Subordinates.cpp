
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, sz[200009];
vector<int> adj[200009];

int dfs(int x){
    int s = 0;
    for(int e : adj[x]){
        s += dfs(e);
    }
    sz[x] = s;
    return s+1;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=2; i<=n; i++){
        int k;
        cin >> k;
        adj[k].push_back(i);
    }
    sz[1] = dfs(1) - 1;
    for(int i=1; i<=n; i++){
        cout << sz[i] << " ";
    }
}
