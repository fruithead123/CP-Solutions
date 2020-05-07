
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m,a,b,col[100009],good=1;
vector<int> G[100009];

void dfs(int i, int c){
    //cout << i << " " << c << endl;
    if(col[i] != -1){
        if(col[i] != c){
            good=0;
        }
        return;
    }
    else{
        col[i] = c;
        for(int e : G[i]){
            dfs(e, 1-c);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    memset(col, -1, sizeof col);

    for(int i=1; i<=n; i++){
        if(col[i] == -1){
            dfs(i, 0);
        }
    }
    if(good){
        for(int i=1; i<=n; i++){
            cout << col[i] + 1 << " ";
        }
    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }
}
