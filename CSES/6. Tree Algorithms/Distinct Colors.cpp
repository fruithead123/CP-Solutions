
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,a,b,col[200009], ans[200009];
vector<int> adj[200009];
unordered_set<int> s;

void dfs(int x, int p){
    unordered_set<int> t;
    t.insert(col[x]);
    for(int e : adj[x]){
        if(e != p){
            dfs(e, x);
            if(s.size() > t.size()) swap(s,t);
            for(int k : s) t.insert(k);
        }
    }
    ans[x] = t.size();
    swap(s,t);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++) cin >> col[i];

    for(int i=0; i<n-1; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,-1);
    for(int i=1; i<=n; i++){
        cout << ans[i] << " ";
    }
}
