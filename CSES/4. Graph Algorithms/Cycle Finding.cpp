
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<pair<pair<ll,ll>, ll>> edges;
stack<int> path;
ll dists[2509];
ll MAXN = 1000000000000000000LL;
int n,m, par[2509], visited[2509];
vector<int> toPrint;
int x = -1;



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    memset(par, 0, sizeof par);
    memset(visited, 0, sizeof visited);
    for(int i=1; i<=n; i++){
        dists[i] = MAXN;
    }
    for(int i=0; i<m; i++){
        ll a,b,w;
        cin >> a >> b >> w;
        edges.push_back({{a,b}, w});
    }

    dists[1] = 0;
    for(int i=0; i<n; i++){
        x = -1;
        for(auto e : edges){
            if(dists[e.first.first] + e.second < dists[e.first.second]){
                dists[e.first.second] = dists[e.first.first] + e.second;
                x = e.first.second;
                par[e.first.second] = e.first.first;
            }
        }
    }
    if(x==-1){
        cout << "NO" << endl;
    }
    else{
        visited[x] = 1;
        path.push(x);
        x = par[x];
        while(visited[x] == 0){
            visited[x] = 1;
            path.push(x);
            x = par[x];
        }
        toPrint.push_back(x);
        while(path.top() != toPrint[0]){
            toPrint.push_back(path.top());
            path.pop();
        }
        toPrint.push_back(path.top());
        cout << "YES" << endl;
        for(int k : toPrint){
            cout << k << " ";
        }
    }
}
