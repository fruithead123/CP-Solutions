
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

char grid[1000][1000];
int n, m, cnt = 0;

void dfs(int i, int j){
    if(i<0 || i>=n || j<0 || j>=m || grid[i][j] == '#'){
        return;
    }
    grid[i][j] = '#';
    dfs(i+1, j);
    dfs(i, j+1);
    dfs(i-1, j);
    dfs(i, j-1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> grid[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == '.'){
                dfs(i,j);
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}
