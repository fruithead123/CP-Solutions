
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m;
vector<pair<ll,ll>> G[100009], G2[100009];
vector<tuple<ll,ll,ll>> edges;
ll dists[100009], dists2[100009];



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=1; i<=n; i++){
        dists[i] = 1000000000000000000LL;
        dists2[i] = 1000000000000000000LL;
    }

    for(int i=0; i<m; i++){
        ll a,b,w;
        cin >> a >> b >> w;
        edges.push_back(make_tuple(a,b,w));
        G[a].push_back({b,w});
        G2[b].push_back({a,w});
    }
    priority_queue<pair<ll,ll>, vector<pair<ll,ll> >, greater<pair<ll,ll>>> q;
    q.push({0,1});
    while(!q.empty()){
        pair<ll,ll> u = q.top(); q.pop();
        //cout << u.first << " " << u.second << endl;

        if(dists[u.second] == 1000000000000000000LL){
            dists[u.second] = u.first;
            for(auto e : G[u.second]){
                q.push({u.first + e.second,e.first});
            }
        }
    }

    q.push({0,n});
    while(!q.empty()){
        pair<ll,ll> u = q.top(); q.pop();
        if(dists2[u.second] == 1000000000000000000LL){
            dists2[u.second] = u.first;
            for(auto e : G2[u.second]){
                q.push({u.first + e.second,e.first});
            }
        }
    }
    ll ans = 1000000000000000000LL;
    for(auto e : edges){
        int a,b,w;
        tie(a,b,w) = e;
        ans = min(ans, dists[a] + dists2[b] + w/2);
    }
    cout << ans << endl;

}
