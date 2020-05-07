
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m,a,b;
vector<int> G[100009];
int pre[100009];

void printPath(int cur, int len){
    if(cur == 1){
        cout << len << endl;
        cout << cur << " ";
    }
    else{
        printPath(pre[cur], len+1);
        cout << cur << " ";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


    memset(pre, 0, sizeof pre);

    cin >> n >> m;
    for(int i=0; i<m; i++){
       cin >> a >> b;
       G[a].push_back(b);
       G[b].push_back(a);
    }

    queue<pair<int,int>> q;
    q.push({1, -1});
    while(!q.empty()){
        auto t = q.front(); q.pop();
        if(pre[t.first] != 0){continue;}
        //cout << t.first << " " << t.second << endl;
        pre[t.first] = t.second;
        if(t.first == n){
            printPath(n, 1);
            return 0;
        }
        for(int e : G[t.first]){
            q.push({e, t.first});
        }
    }
    cout << "IMPOSSIBLE" << endl;
}
