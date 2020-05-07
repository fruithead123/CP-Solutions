
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,x, books[1010], prices[1010];
    cin >> n >> x;
    for(int i=0; i<n; i++){
        cin >> prices[i];
    }
    for(int i=0; i<n; i++){
        cin >> books[i];
    }
    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));
    for(int i=0; i<=n; i++){
        for(int j=0; j<=x; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            else if(j - prices[i-1] >= 0){
                dp[i][j] = max(dp[i-1][j], books[i-1] + dp[i-1][j-prices[i-1]]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n][x] << endl;
    /*
    for(int i=0; i<=n; i++){
        for(int j=0; j<=x; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    */
}
