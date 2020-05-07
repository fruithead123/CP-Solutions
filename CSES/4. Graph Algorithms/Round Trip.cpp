
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 100009;

vector<int> G[MAXN];
stack<int> path;
int n,m, visited[MAXN], found = 0;
stack<int>pnt;

void dfs(int i, int par){
    //cout << i << " " << par << endl;
    if(found == 1){return;}
    if(visited[i] == 1){
        found = 1;
        pnt.push(i);
        while(true){
            pnt.push(path.top());
            path.pop();
            if(pnt.top() == i){
                break;
            }
        }
        cout << pnt.size() << endl;
        while(pnt.size()){
            cout << pnt.top() << " ";
            pnt.pop();
        }
        return;
    }

    visited[i] = 1;
    path.push(i);
    for(int e : G[i]){
        if(e != par){
            dfs(e,i);
        }
    }
    path.pop();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0, a, b; i<m; i++){
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    memset(visited, 0, sizeof visited);

    for(int i=1; i<=n; i++){
        if(visited[i] == 0 && found == 0){
            dfs(i, -1);
        }
    }
    if(found == 0){
        cout << "IMPOSSIBLE" << endl;
    }
}
