
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, visited[100009], a,b;
vector<int> G[100009];
vector<int> components;

void dfs(int i){
    if(visited[i] == 1){return;}
    visited[i] = 1;
    for(int e : G[i]){
        dfs(e);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(visited, 0, sizeof visited);
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i=1; i<=n; i++){
        if(visited[i] == 0){
            components.push_back(i);
            dfs(i);
        }
    }
    auto sz = components.size();
    cout << sz - 1 << endl;
    for(int i=1; i<sz; i++){
        cout << 1 << " " << components[i] << "\n";
    }
}
