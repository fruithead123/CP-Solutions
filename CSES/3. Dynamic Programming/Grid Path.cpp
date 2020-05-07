
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    vector<vector<int>> dp(1010, vector<int>(1010,0));
    vector<vector<char>> grid(1010, vector<char>(1010,0));
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> grid[i][j];
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i-1 >= 0 && grid[i-1][j] == '.'){
                dp[i][j] = (dp[i][j] + dp[i-1][j]) % 1000000007;
            }
            if(j-1 >= 0 && grid[i][j-1] == '.'){
                dp[i][j] = (dp[i][j] + dp[i][j-1]) % 1000000007;
            }
            if(grid[i][j] == '*'){
                dp[i][j] = 0;
            }
        }
    }

    cout << dp[n-1][n-1] << endl;
}
