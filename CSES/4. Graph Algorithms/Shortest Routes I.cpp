
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,m,dists[100009],visited[100009];
vector<pair<int,int>> G[100009];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);



    memset(visited, 0LL, sizeof visited);

    cin >> n >> m;
    for(ll i=0, a,b,c; i<m; i++){
        cin >> a >> b >> c;
        G[a].push_back({b,c});
    }

    for(int i=1; i<=n; i++){
        dists[i] = 1000000000000000000LL;
    }
    dists[1] = 0LL;
    priority_queue<pair<ll,ll>> pq;
    pq.push({0,1});
    while(!pq.empty()){
        int a = pq.top().second; pq.pop();
        if(visited[a] == 1){continue;}
        visited[a] = 1;
        for(auto e : G[a]){
            ll b = e.first, w = e.second;
            if(dists[a] + w < dists[b]){
                dists[b] = dists[a] + w;
                pq.push({-dists[b], b});
            }
        }
    }
    for(int i=1; i<=n; i++){
        cout << dists[i] << " ";
    }
}
