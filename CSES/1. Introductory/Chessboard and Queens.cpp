
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int ans = 0;
bool col[8], diag1[16], diag2[16];
char board[8][8];

void solve(int y) {
    if (y == 8) {
        ans++;
        return;
    }
    for (int x = 0; x < 8; x++) {
        if (col[x] || diag1[x+y] || diag2[x-y+7] || board[y][x] == '*') continue;
            col[x] = diag1[x+y] = diag2[x-y+7] = 1;
            solve(y+1);
            col[x] = diag1[x+y] = diag2[x-y+7] = 0;
        }
}

int main(){
    memset(col, false, sizeof col);
    memset(diag1, false, sizeof col);
    memset(diag2, false, sizeof col);
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            cin >> board[i][j];
        }
    }
    solve(0);
    cout << ans << "\n";
}
