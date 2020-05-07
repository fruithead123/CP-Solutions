
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
vector<int> adj[200009];
pair<int,int> best = {0,0};

void dfs(int x, int p, int d){
    if(d > best.second){
        best = {x, d};
    }
    for(int e : adj[x]){
        if(e != p){
            dfs(e, x, d+1);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n-1; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, -1, 0);
    dfs(best.first, -1, 0);
    cout<<best.second<<endl;
}
