
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1000000009;

vector<int> adj[200009];
int d1[200009], d2[200009] ,n;

void dfs1(int x=0, int p=-1, int d=0){
    d1[x] = d;
    //cout << x << " " << d<<endl;
    for(int e : adj[x]){
        if(e != p) dfs1(e, x, d+1);
    }
}

void dfs2(int x=0, int p=-1, int d=0){
    d2[x] = d;
    for(int e : adj[x]){
        if(e != p) dfs2(e, x, d+1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1; i<n; i++){
        int a,b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    dfs1();
    dfs2(max_element(d1, d1+n) - d1);
    dfs1(max_element(d2, d2+n) - d2);
    for(int i=0; i<n; i++){
        cout << max(d1[i], d2[i]) << " ";
    }
}
