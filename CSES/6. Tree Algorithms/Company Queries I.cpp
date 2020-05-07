
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1000000009;

vector<int> adj[200009];
int up[200009][20]; // up[i][j] = the boss of i 2^j levels up

void dfs(int x, int p){
    up[x][0] = p;
    for(int e : adj[x]){
        if(e != p) dfs(e, x);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,q,x,k;
    cin >> n >> q;
    for(int i=2; i<=n; i++){
        int a;
        cin >> a;
        adj[i].push_back(a);
        adj[a].push_back(i);
    }
    dfs(1, 0);

    for(int j=1; j<20; j++){
        for(int i=1; i<=n; i++){
            up[i][j] = up[up[i][j-1]][j-1];
        }
    }

    while(q--){
        cin >> x >> k;
        int ans = x;
        for(int i=0; i<20; i++){
            if(k&1){
                ans = up[ans][i];
            }
            k/=2;
        }
        cout << (ans==0 ? -1 : ans) << "\n";
    }
}
