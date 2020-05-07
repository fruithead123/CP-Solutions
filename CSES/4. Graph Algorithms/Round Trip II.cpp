
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


stack<int> stk;
vector<int> G[100009];
vector<int> path;
int visited[100009],n,m;
int done = 0;

void dfs(int i){
    if(visited[i] == 1){
        done = 1;
        path.push_back(i);
        while(stk.top() != path[0]){
            path.push_back(stk.top());
            stk.pop();
        }
        cout << path.size()+1 << endl;
        cout << path[0] << " ";
        reverse(path.begin(), path.end());
        for(int x : path){
            cout << x << " ";
        }
        exit(0);
    }
    visited[i] = 1;
    stk.push(i);
    for(auto e : G[i]){
        if(done == 0){
            dfs(e);
        }
    }
    visited[i] = 0;
    stk.pop();
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(visited, 0, sizeof visited);
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    for(int i=1; i<=n; i++){
        if(done == 0){
            dfs(i);
        }
    }
    cout << "IMPOSSIBLE" << endl;
}
