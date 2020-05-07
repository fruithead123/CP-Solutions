
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, nums[5010], pfx[5010];
    pfx[0] = 0;
    cin >> n;
    vector<vector<ll>> dp(n,  vector<ll>(n,-100000000000LL));
    for(int i=0; i<n; i++){
        cin >> nums[i];
        dp[i][i] = nums[i];
        pfx[i+1] = pfx[i] + nums[i];
    }
    for(int j=1; j<n; j++){
        for(int i=j-1; i>=0; i--){
            dp[i][j] = max(max(dp[i][j], nums[i] + (pfx[j+1] - pfx[i+1] - dp[i+1][j])), nums[j] + (pfx[j] - pfx[i] - dp[i][j-1]));
        }
    }
    cout << dp[0][n-1] << endl;
    /*
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    */
}
