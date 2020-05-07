
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,m,q,dists[510][510],adj[510][510];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> q;;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            adj[i][j] = 1000000000000000000LL;
            dists[i][j] = 1000000000000000000LL;
            if(i == j){
                adj[i][j] = 0LL;
                dists[i][j] = 0LL;
            }
        }
    }
    for(ll i=0,a,b,w; i<m; i++){
        cin >> a >> b >> w;
        adj[a][b] = min(adj[a][b], w);
        adj[b][a] = min(adj[b][a],w);
        dists[a][b] = min(dists[a][b],w);
        dists[b][a] = min(dists[b][a], w);
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j]);
            }
        }
    }
    while(q--){
        cin >> n >> m;
        if(dists[n][m] == 1000000000000000000LL) cout << -1 << endl;
        else cout << dists[n][m] << endl;
    }
}
