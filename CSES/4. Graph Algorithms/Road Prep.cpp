
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//Find minimum spanning tree and check if all nodes are in the same component at the end

int link[100009], sz[100009]; //link[x] -> next element towards representitive, sz[x] -> Size of component
int n,m;
vector<pair<ll, pair<int,int>>> edges;
ll ans = 0LL;

int fnd(int x){
    if(x == link[x]) return x;
    return link[x] = fnd(link[x]);
}

bool same(int a, int b){
    return fnd(a) == fnd(b);
}

void unite(int a, int b){
    a = fnd(a);
    b = fnd(b);
    if(sz[a] < sz[b]) swap(a,b);
    sz[a] += sz[b];
    link[b] = a;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i=1; i<=n; i++){
        link[i] = i;
        sz[i] = 1;
    }
    for(int i=0; i<m; i++){
        int a,b;
        ll w;
        cin >> a >> b >> w;
        edges.push_back({w, {a,b}});
    }
    sort(edges.begin(), edges.end());

    for(auto e : edges){
        if(!same(e.second.first, e.second.second)){
            unite(e.second.first, e.second.second);
            ans += e.first;
        }
    }
    int flag = 1;
    for(int i=2; i<=n; i++){
        if(!same(1,i)){
            flag = 0;
            break;
        }
    }
    if(flag){
        cout << ans << endl;
    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }
}
